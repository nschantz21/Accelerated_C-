#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <string>
#include <ctime>
using std::cout; using std::string;
using std::cin; using std::getline;

int main(){
    Str str_one = "This is my string";
    Str str_two = str_one;
    Str str_three = "this is not my string!";
    
    cout << (str_one == str_two) << "\n"; // true
    cout << (str_one == str_three) << "\n"; // false
    cout << (str_one > str_two) << "\n"; // false
    cout << (str_one <= str_two) << "\n"; // true
    cout << (str_one != str_three) << "\n"; // true
    
    


    return 0;
}