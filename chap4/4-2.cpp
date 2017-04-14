#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

using std::endl;  using std::cin;     using std::streamsize;
using std::cout;    using std::sort;    using std::vector;
using std::setw;    

// Write a program to calculate the squares of int values up to 100. The program should
// write two columns: The first lists the value; the second contains the square of that value. Use
// setw to manage the output so that the values line up in columns.

// setw(n): Returns a value of type streamsize that, when written on an output stream s, has
// the effect of calling s.width(n).
int main(){

    std::vector<double> v(100) ; // vector with 100 ints.
    std::iota (std::begin(v), std::end(v), 1); // Fill with 1, ..., 100.

    for(vector<double>::size_type i=0; i != v.size(); ++i){
        streamsize linwidth = cout.width();

        
        
        cout<<std::internal<<v[i]<<setw(10)
        <<pow(v[i],2)<<setw(linwidth)<<endl;
        cout.flush();
    }
    return 0;
}