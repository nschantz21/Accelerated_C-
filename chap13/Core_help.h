#ifndef GUARD_Core_helper
#define GUARD_Core_helper
#include<iostream> // istream
#include<string> // string
#include<algorithm> // min
#include<vector> // vector
#include<stdexcept>

std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read_hw(std::istream& in, std::vector<double>& hw)
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

double median(std::vector<double>);
double median(std::vector<double> vec2)
{
    std::vector<double> vec(vec2);
    typedef std::vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    /*
    if(size == 0) 
        throw domain_error("median of an empty vector");
    */
    std::sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;

    return
        size % 2 == 0 ?
        (vec[mid-1] + vec[mid]) / 2 :
        vec[mid];
}

double grade(double, double, double);
double grade(double midterm,double final,double homework){
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

 double grade(double, double, std::vector<double>);
 double grade(double midterm, double final, std::vector<double> hw)
{
    if (hw.size() == 0)
        return ::grade(midterm, final, 0); 
    double hw_m = median(hw);
    return ::grade(midterm, final, hw_m);
}

#endif