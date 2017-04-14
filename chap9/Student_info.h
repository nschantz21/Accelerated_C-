#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <stdexcept>

class Student_info {
    public:
        Student_info(); // construct an empty Student_info object
        Student_info(std::istream&); // construct one by reading a stream
        bool valid() const { return !homework.empty(); } // empty is a member of vector
        double grade () const;
        std::istream& read_and_grade(std::istream&);
        // std::istream& read(std::istream&); // must change definition
        std::string name() const { return n;} // copies the student's name (n).  acts as read-only access.  Accessor function.
    private:
        std::istream& read_hw(std::istream&, std::vector<double>&);
        std::string n;  // changed
        double midterm, final, g;
        std::vector<double> homework;
};

// double grade(const Student_info&);

double grade(double, double, std::vector<double>);
double grade(double,double, double);

bool compare(const Student_info&, const Student_info&);


double median(std::vector<double>);

#endif