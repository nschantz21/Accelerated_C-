#ifndef GUARD_grade_h
#define GUARD_grade_h
// grade.h
#include <vector>
#include "Core.h"
#include <list>
#include <ostream>
#include <string>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
bool pgrade(const Student_info&);
double median_analysis(const std::vector<Student_info>& students);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_mean_analysis(const Student_info&);
void write_analysis(std::ostream&, const std::string&, 
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, 
                    double analysis(const Student_info&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);



#endif

