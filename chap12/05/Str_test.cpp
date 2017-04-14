#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <string>
#include <ctime>
using std::cout; using std::string;
using std::cin; using std::getline;

int main(){
    
    Str string1 = "ello this is my string";
    Str string2 = string1 + '!';
    Str string3 = 'H' + string2;
    
    cout << string1 << "\n"
         << string2 << "\n"
         << string3 << "\n";
         

    return 0;
}