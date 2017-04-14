#include "Str.h"
#include "Vec.h"
#include <iostream>

using std::cout; using std::cin;

int main(){
    
    Str my_string = "You shouldn't see this, You should see this";
    
    
    // using iterators
    Str my_second_string(my_string.begin() + 24, my_string.end());
    
    cout << my_second_string << "\n";

    
    return 0;
}