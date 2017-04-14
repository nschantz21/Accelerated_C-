#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"
#include <list>
#include <ctime>
#include <map>

using std::map;
using std::cin;     using std::setprecision;
using std::cout;    using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;    using std::string;
using std::max;     using std::vector;
using std::list;



int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;    // the length of the longest name
    list<Student_info> students2;
    map<char, int> letters;
    
    
    cout<<"Enter the student's name followed by their Final, Midterm and Homework grades"<<endl;
    
    // read and store all the students data.
    // Invariant: students conatains all the student records read so far
    // maxlen contains the length of the longest name in students
        
    while (read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
        students2.push_back(record);
    }
    
    vector<Student_info>::iterator miter = students.begin();
    while (miter != students.end()){
        miter->letter = letter_grade(*miter);
        ++letters[(*miter).letter];
        ++miter;
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    cout<<endl;
    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
    i != students.size(); ++i){
        
        //write the name, padded on the right to maxlen + 1 characters
        cout<<students[i].name<<string(maxlen + 1 - students[i].name.size(), ' ');
        
        // compute and write the grade
        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout<<setprecision(3)<<final_grade<<setprecision(prec);
        } catch (domain_error e) {
            cout<< e.what();
        }
        
        cout<<endl;
        
    }
    
    cout << endl << "number of students with each letter grade:" << endl;
    map<char, int>::iterator m = letters.begin();
    while(m != letters.end()){
        cout<< m->first << "\t" <<  m->second <<  endl;
        ++m;
    }
    
    
    
    
    std::clock_t    start;
    start = std::clock();
    vector<Student_info> fail = extract_fails(students);
    cout << endl << "Vector of Failing Students:"<< endl;
    
    for (vector<Student_info>::const_iterator iter = fail.begin(); iter != fail.end(); ++iter) {
        cout<<iter->name << endl;
    }
    
    cout<< fail.size()<<endl;
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    
    
    // test the time for a list
    
    std::clock_t start2;
    start2 = std::clock();
    
    
    
    list<Student_info> fail_list = extract_fails(students2);
    fail_list.sort(compare);
    cout << "List of Failing Students:"<< endl;
    for (list<Student_info>::const_iterator iter = fail_list.begin(); iter != fail_list.end(); ++iter) {
        cout << iter->name << endl;
    }
    cout<< fail_list.size()<<endl;
    std::cout << "Time: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    return 0;
}