// source file for average-related functions
#include "average.h"


using std::istream; using std::vector;

istream& read_numbs(istream& in, vector<double>& numbs)
{
    if(in) {
        // reset vector (get rid of previous contents)
        numbs.clear();
        
        // read homework grades
        double x;
        while( in >> x )
            numbs.push_back(x);
            
        // clear failure flag for istream
        in.clear();
    }
    return in;
}

double average_of_vector (vector<double>& dubs){
    int total = 0;
    vector<double>::size_type vec_size = dubs.size();
    for (vector<double>::size_type i = 0;
    i != dubs.size(); ++i){
        total =+ dubs[i];
    }
    return (total / vec_size);
}