#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <istream>
#include <string>
#include "Vec.h"
#include <stdexcept>

class Student_info {
    public:
        Student_info(); // construct an empty Student_info object
        Student_info(std::istream&); // construct one by reading a stream
        bool valid() const { return !homework.empty(); } // empty is a member of Vec
        double grade () const;
        std::istream& read_and_grade(std::istream&);
        // std::istream& read(std::istream&); // must change definition
        std::string name() const { return n;} // copies the student's name (n).  acts as read-only access.  Accessor function.
    private:
        std::istream& read_hw(std::istream&, Vec<double>&);
        std::string n;  // changed
        double midterm, final, g;
        Vec<double> homework;
};

// double grade(const Student_info&);

double grade(double, double, Vec<double>);
double grade(double,double, double);

bool compare(const Student_info&, const Student_info&);


double median(Vec<double>);

#endif