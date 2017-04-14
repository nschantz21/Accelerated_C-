#include "Str.h"
#include "Vec.h"
#include <iostream>

using std::cout; using std::cin;

int main(){
    
    Str my_string = "this is my string: ";
    char my_seperator;
    cout<<"what's the delimiter?: ";
    cin>>my_seperator;
    
    my_string.getline(cin, my_seperator);
    
    cout<<my_string<< "\n";
    
    
    
    return 0;
}