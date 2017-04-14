#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// defining a type which contains four data members
struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // note the semicolon it's required

istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and midterm and final exam grades
    is>>s.name>>s.midterm>>s.final;
    read_hw(is, s.homework);  // read and store all the student's homework grades
    return is;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info& x, const Student_info& y)
{  
    return x.name < y.name;
}

int main(){
    vector<Student_info>students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store all the records, and find the length of the longest name
    while (read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    //alphabetize the records
    sort(students.begin(), students.end(), compare);
    
    for (vector<Student_info>::size_type i = 0;
    i != students.size(); ++i){
        
        // write the name, padded on the right to maxlen + 1 characters
        cout<<students[i].name<<string(maxlen + 1 - students[i].name.size(), ' ');
        
        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout<<setprecision(3)<<final_grade<<setprecision(prec);
        } catch (domain_error e){
            cout<<e.what();
        }
        cout<<endl;
        
    }
    return 0;
}
    