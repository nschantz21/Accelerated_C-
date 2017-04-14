#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <string>
#include<cstring>

using std::cout; using std::cin;
using std::string;


int main(){
    
    Str my_string = "You should not see This!";
    Str my_second_string = "you should see this";
    // using iterators
    my_string.assign( my_second_string.begin(), my_second_string.end());
    
    cout << my_string << "\n";

    string another_string = "hello there!";
    Vec<char> my_vec(another_string.begin(), another_string.end());
    for(Vec<char>::iterator i = my_vec.begin(); i != my_vec.end(); ++i){
        cout << *i;
    }
    cout <<"\n";
    
    return 0;
}