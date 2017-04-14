#include "Core.h"
#include <iostream> // cin and cout
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>



using std::string; using std::vector; using std::sort;
using std::domain_error; using std::cin; using std::cout;
using std::max; using std::streamsize; using std::setprecision;
using std::endl;

//  Records for graduate students will start with a G , and those for an undergraduate will start with a U .

int main(){
    
    cout << "Enter your students and their grades." << "\n" 
    << "Put a 'U' for Undergrad, 'A' for Auditor,  and 'G' for Grad." << "\n"
    << "If it's a Grad student, then enter the thesis grade after the Final and Midterm!" << "\n" << "Auditors are pass/fail and don't need to do the homework, but may.\n";
    
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store data
    while (record.read(cin)){ 
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }
    
    // aplhabetize the student records
    sort(students.begin(), students.end(), Student_info::compare); // caling the static member function of the Student_info class
    
    // write the names and grades
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        
        cout<<students[i].name()<<string(maxlen + 1 - students[i].name().size(), ' ');
        
        try{
            double final_grade = students[i].grade();  // member function to calculate the student grade
            string the_letter_grade = students[i].Core_letter_grade();
            bool all_done = students[i].requirements();
            streamsize prec = cout.precision();
            
            cout << setprecision(3)<<final_grade<<"\t"<<the_letter_grade<<"\n"<<all_done<<setprecision(prec)<<"\n";
        } catch (domain_error e){
            cout << e.what() << endl;
        }
    }
    
    return 0;
}