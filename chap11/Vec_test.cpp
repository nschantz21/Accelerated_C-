#include "Vec11-6.h"
#include<cstddef>
#include<iostream>
using std::cout;
using std::size_t;

int main(){
    
    Vec<int> my_vec(100, 100);
    
    Vec<double> my_dub_vec;
    int x = 100;
    Vec<int> my_second_vec = my_vec;
    
    
    my_vec.push_back(x);
    cout<<my_vec.size()<<"\n"<<my_dub_vec.size()<<"\n"<<my_second_vec.size()<<"\n";
    
    //Vec<int>::iterator it = my_vec.begin();
    
    my_vec.erase(my_vec.begin() + 50);
    
    cout<<"now with one less element! \n" << my_vec.size()<<"\n" 
        <<my_dub_vec.size()<<"\n"  <<my_second_vec.size()<<"\n";
      
    my_vec.clear(); // delete all the elements
    cout<<"now no elements! \n" << my_vec.size()<<"\n";
      
    
    return 0;
}