// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{  
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and midterm and final exam grades
    is>>s.name>>s.midterm>>s.final;
    read_hw(is, s.homework);// read and store all the student's homework grades
    return is;
}

char letter_grade(const Student_info& s){
    double student_letter_grade = grade_aux(s);
    if(student_letter_grade >= 90)
        return 'A';
    else
    if(80 <= student_letter_grade && student_letter_grade < 90)
        return 'B';
    else
    if(70 <= student_letter_grade && student_letter_grade < 80)
        return 'C';
    else
    if(60 <= student_letter_grade && student_letter_grade < 70)
        return 'D';
    else
    if(student_letter_grade < 60)
        return 'F';
    else
        return 'X';
    
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if(in) {
        // reset vector (get rid of previous contents)
        hw.clear();
        
        // read homework grades
        double x;
        while( in >> x )
            hw.push_back(x);
            
        // clear failure flag for istream
        in.clear();
    }
    return in;
}