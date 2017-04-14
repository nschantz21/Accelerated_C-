#include "Str.h"
#include "Vec.h"
#include <iostream>

using std::cout; using std::cin;

int main(){
    
    Str my_string = "You  This!";
    Str my_second_string = "should see";
    // using iterators
    my_string.insert(my_string.begin() + 4 , my_second_string.begin(), my_second_string.end());
    
    cout << my_string << "\n";

    
    return 0;
}