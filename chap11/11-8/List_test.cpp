// List_test.cpp
#include "List.h"
#include <iostream>
#include <string>

using std::cout; using std:: string;

int main(){
    
    List<int> my_int_List;
    
    
    my_int_List = cons(5, my_int_List); // push_front equivelenct functions
    
    
    for(List<int>::const_iterator i = my_int_List.begin(); i != my_int_List.end(); ++i){
        cout << *i << "\n";
    }
    
    List<int> my_int_List_2(my_int_List);
    
    for(List<int>::const_iterator i = my_int_List_2.begin(); i != my_int_List_2.end(); ++i){
        cout << *i << "\n";
    }
    
    
    
    List<string> my_string_List;
    string my_string = "poop";
    my_string_List = cons(my_string, my_string_List);
    
    
    for(List<string>::const_iterator i = my_string_List.begin(); i != my_string_List.end(); ++i){
        cout << *i << "\n";
    }
    cout << car(my_string_List) << "\n";
    
    
    
    return 0;
}