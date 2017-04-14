#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using std::vector;  using std::string;
using std::cin; using std::cout; using std::endl;
using std::sort; using std::domain_error;

template<class R, class Iterator>
// call this function to find the median of a vector of values of any kind of arithmetic type
R median_by_iter(Iterator beg, Iterator end){
    typedef typename vector<R>::iterator iter;
    bool is_there (end > beg);
    
    // this part might not work
    if (!is_there)
        throw domain_error("median of an empty vector");
        
        
    iter size = end- beg;
    
    sort(beg, end);
    
    iter mid = size/2;
    
    return size % 2 == 0 ? *((mid + (mid - 1))/2) : *mid;
}



int main(){
    vector<double> y;
    
    double b;
    
    
    while(cin>>b)
        y.push_back(b);
    
    
    cout<<median_by_iter(y.begin(), y.end())<<endl;
    
    return 0;
}