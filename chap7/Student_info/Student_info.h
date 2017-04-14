#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

// defining a type which contains four data members
struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
    char letter;
}; // note the semicolon it's required

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
char letter_grade(const Student_info&);
#endif