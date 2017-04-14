#include "Student_info.h"
#include <iostream> // cin and cout
#include "Vec.h"
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>



using std::string; using std::sort;
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
    Vec<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store data
    while (record.read_and_grade(cin)){ // changed to member function
        maxlen = max(maxlen, record.name().size()); // changed
        students.push_back(record);
    }
    
    // aplhabetize the student records
    sort(students.begin(), students.end(), compare);
    
    // write the names and grades
    
    for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i){
        
        cout<<students[i].name()<<string(maxlen + 1 - students[i].name().size(), ' ');
        
        if (students[i].valid()){
            double final_grade = students[i].grade();  // member function to calculate the student grade
            streamsize prec = cout.precision();
            cout << setprecision(3)<<final_grade<<setprecision(prec)<<endl;
        }

    }
    
    return 0;
}