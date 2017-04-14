#include "../chap4/grade.h"
#include "../chap4/median.h"
#include "../chap4/Student_info.h"

// generic grading function from chap4 analysis
// 
template<class function>
double generic_grade_analysis(const vector<Student_info>& students, function grd_anal){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grd_anal);
    
    return median(grades);
}
