#include "Str.h"
#include "Vec.h"
#include <iostream>

using std::cout; 

int main(){
    
    Str string1 = "hello my friends";
    Str string2;
    
    bool x = string1; // true
    bool y = string2; // false
    bool z = (!string1); // false
    bool a = (!string2); // true
    cout << x << "\n";
    cout << y << "\n";
    
    cout << z << "\n";
    cout << a << "\n";     
    
    
    return 0;
}