#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <vector>
#include "average.h"

using std::cin;
using std::cout;    
using std::endl;    
using std::vector;

int main(){
    vector<double> my_vector;
    read_numbs(cin, my_vector);
    
    double final = average_of_vector(my_vector);

    cout << final;
    return 0;
}