#include "Str.h"
#include <iostream>
#include <string>
#include <ctime>
using std::cout; using std::string;
using std::cin; using std::getline;

int main(){
    clock_t m = clock();
    Str name;
    name = "Nick";
    
    Str my_second_Str = "Hello " + name + "!";
    
    Str in_Str;
    string copy_string = "copy this bitch!";
    
    in_Str = Str(copy_string.begin(), copy_string.end());
    
    cout<<my_second_Str<< "\t"<<my_second_Str.size()<<"\n";
    cout<<in_Str<<"\n";
    
    Str cin_string;
    
    while(cin){
        Str temp;
        cin>>temp;
        cin_string+= temp + " ";
    }
    
    
    Str copy_string_2(20, 'F');
    cin_string.copy(copy_string_2.begin(), cin_string.size());
    cout << copy_string_2 << "\n";
    
    m = clock() - m;
    
    cout<< m << "\n";
    
    return 0;
}