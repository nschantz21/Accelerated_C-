#include <stdexcept>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <list>
#include <ostream>
#include <string>
#include <numeric>

using std::domain_error; using std::vector; using std::list; using std::ostream;
using std::string; using std::endl; using std::accumulate;

// definitions from the grade functions from §4.1/52, §4.1.2/54 and §4.2.2/63

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
    throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}

// predicate to determine whether a student failed
bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

/*
    // iterators but no indexing; still potentially slow
vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    while (iter!= students.end()) {
        if (fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }

    
return fail;
}
*/
list<Student_info> extract_fails(list<Student_info>& students){
    list<Student_info> fail_list;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter!= students.end()) {
        if (fgrade(*iter)){
            fail_list.push_back(*iter);
            iter = students.erase(iter);
        } else
        ++iter;
    }
    return fail_list;
}

bool did_all_hw(const Student_info& s){
    return ((find(s.homework.begin(), s.homework.end(), 0 )) == s.homework.end());
}

double grade_aux(const Student_info& s){
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const vector<Student_info>& students){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double>& v){
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s){
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students){
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    
    return median(grades);
}

//median of the nonzero elements of s.homework, or 0 ifno such elements exist
double optimistic_mean_analysis(const Student_info& s){
    vector<double> nonzero;
    
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    
    if(nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt){
    out<< name <<": median(did)= "<<analysis(did)<<", median(didnt)= "<<analysis(didnt)<<endl;
}

void write_analysis(ostream& out, const string& name, double analysis(const Student_info&), const vector<Student_info>& did, const vector<Student_info>& didnt){

    vector<Student_info> students;
    vector<double> grades;
    vector<Student_info>::const_iterator i = did.begin();
    vector<Student_info>::const_iterator j = didnt.begin();
    while(i != did.end()){
        students.push_back(*i);
        ++i;
    }
    while(j != didnt.end()){
        students.push_back(*j);
        ++j;
    }
    
    vector<Student_info>::iterator h = students.begin();
    while(h != students.end()){
        grades.push_back(analysis(*h));
        ++h;
    }
    
    
    out<< name << median(grades) << endl;
}


bool pgrade(const Student_info& s){
    return !fgrade(s);
}

/*
// uses algorithm rather than iterator declarations
vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
    studetms.erase(remove_if(students.begin(), studetns.end(), fgrade), students.end())
    return fail;
}
*/

// uses stable_partition algorithm
vector<Student_info> extract_fails(vector<Student_info>& students){
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}

