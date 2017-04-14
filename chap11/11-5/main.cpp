#include "Student_info.h"
#include <iostream> // cin and cout
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>


// Assignment 10-1
// Rewrite the student-grading program from §9.6/166 to generate letter grades

using std::string; using std::vector; using std::sort;
using std::domain_error; using std::cin; using std::cout;
using std::max; using std::streamsize; using std::setprecision;
using std::endl;

char pass(const Student_info& stu){
    if(stu.grade() > 60){
        return 'P';
    }else{
        return 'F';
    }
}



int main(){
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    Student_info second = record;
    
    // read and store data
    while (record.read_and_grade(cin)){ // changed to member function
        maxlen = max(maxlen, record.name().size()); // changed
        students.push_back(record);
    }
    
    // aplhabetize the student records
    sort(students.begin(), students.end(), compare);
    
    // write the names and grades
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        
        cout<<students[i].name()<<string(maxlen + 1 - students[i].name().size(), ' ');
        
        if (students[i].valid()){
            double final_grade = students[i].grade();  // member function to calculate the student grade
            streamsize prec = cout.precision();
            
            
            cout << setprecision(3)<<final_grade<< "\t" <<
            // calling the member function of the Student_info Class, letter to get the letter grade for the student
            students[i].letter()<<setprecision(prec)<<endl;
        }

    }
    
    // print how many Student_info objects were created, alive at end of compilation, assigned, and deleted.
    cout<< "created: " << Student_info::objects_created << "\t" 
    << "alive: " << Student_info::objects_alive << "\t"
    << "assigned: " << Student_info::objects_assigned << "\t" 
    << "copied: " << Student_info::objects_copied << "\t" 
    << "deleted: " << Student_info::objects_deleted << "\n";
    
    return 0;
}