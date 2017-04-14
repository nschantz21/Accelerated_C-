#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <stdexcept>
// we need to call the file which holds the function we want to add to the Student_info Class
#include "letter_grade_array.h"

// Curiously Recurring Template Pattern (CRTP)
// this template has to proceed the base class for some reason
template <typename T>
struct counter
{
    static int objects_created;
    static int objects_alive;
    static int objects_assigned;
    static int objects_deleted;
    static int objects_copied;

    counter() // uninitialized contructor
    {
        ++objects_created;
        ++objects_alive;
    }
    
    counter(const counter&) // copy constructor
    {
        ++objects_created;
        ++objects_alive;
        ++objects_copied;
    }
    
    counter& operator=(const counter&) // assignment operator
    {
        ++objects_assigned;
    }
protected:
    ~counter() // destructor. objects should never be removed through pointers of this type
    {
        --objects_alive;
        ++objects_deleted;
    }
};

template <typename T> int counter<T>::objects_created( 0 );
template <typename T> int counter<T>::objects_alive( 0 );
template <typename T> int counter<T>::objects_assigned( 0 );
template <typename T> int counter<T>::objects_deleted( 0 );
template <typename T> int counter<T>::objects_copied( 0 );

class Student_info : public counter<Student_info> {
    public:
        Student_info();  // construct an empty Student_info object
        Student_info(std::istream&); // construct one by reading a stream
        bool valid() const { return !homework.empty(); } // empty is a member of vector
        double grade () const;
        std::istream& read_and_grade(std::istream&);
        std::string name() const { return n;}; // copies the student's name (n).  acts as read-only access.  Accessor function.
        std::string letter() const {return letter_grade(grade());} // generates a letter grade corresponding with the student's grade.
        
        
    private:
        std::istream& read_hw(std::istream&, std::vector<double>&);
        std::string n;  // changed
        double midterm, final, g;
        std::vector<double> homework;
        
};


double grade(double, double, std::vector<double>);
double grade(double,double, double);

bool compare(const Student_info&, const Student_info&);


double median(std::vector<double>);




#endif