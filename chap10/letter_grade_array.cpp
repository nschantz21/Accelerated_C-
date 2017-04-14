#include <cstring>
#include <string>
#include "letter_grade_array.h"

using std::string;


// example implementation of standard-library function
size_t strlen(const char* p){
    size_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
}

string letter_grade(double grade){
    
    //range posts for numeric grades
    static const double numbers[] = {
        97, 94, 90, 87, 80, 77, 74, 70, 60, 0
    };
    
    // names for the letter grades
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };
    
    // compute the number of grades given the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers); // these return size in bytes
    
    // given a numeric grade, find and return the associated letter grade
    for (size_t i = 0; i < ngrades; ++i){
        if (grade > numbers[i])
            return letters[i];
    }
    
    return "?\?\?"; // forward slashes allow you to return multiple question marks
    
}