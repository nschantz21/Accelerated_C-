#include "Student_info.h"
#include <stdexcept>
#include <iostream>
#include <istream>
#include <ios>
#include <algorithm>


using std::domain_error; using std::vector; using std::istream;
using std::string; using std::endl; using std::sort; using std::bad_alloc;

double Student_info::grade() const {
    return g;
}

istream& Student_info::read_hw(istream& in, vector<double>& hw)
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


istream& Student_info::read_and_grade(istream& in){ // updated read function that also computes the final grade and assigns it to member function grade()
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);
    return in;
}



Student_info::Student_info(): midterm(0), final(0){} // default constructor for Student_info object


Student_info::Student_info(istream& is) {read_and_grade(is);} // second Student_info constructor



double median(vector<double> vec2)
{
    vector<double> vec(vec2);
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return
        size % 2 == 0 ?
        (vec[mid-1] + vec[mid]) / 2 :
        vec[mid];
}

 double grade(double midterm, double final, vector<double> hw)
{
    return grade(midterm, final, median(hw));
}

double grade(double midterm,double final,double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name(); // invoking the name function, not accessing the member directly
}