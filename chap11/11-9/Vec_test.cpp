#include "Vec.h"
#include<cstddef> 
#include<iostream>
#include <ctime>  /* clock_t, clock, CLOCKS_PER_SEC */

using std::cout;
using std::size_t;

int main(){
    
        // make another Vec and a second Vec to add to it
    Vec<int> my_vec_3(100000, 100);
    Vec<int> my_vec_4(500000, 100);
    
    // start our timer again, this time for the push_back_2 function
    clock_t m = clock();
    
    
    // use the push_back_2 function
    // this one allocated memory for a single element everytime you call it
    for(Vec<int>::size_type i = 0; i != my_vec_4.size(); ++i){
        my_vec_3.push_back_2(i);
    }

    m = clock() - m;
    
    
    // how much time did it take??????
    cout<<m<<"\n";
    
    
    // make a Vec and an int to add to it
    Vec<int> my_vec(100000, 100);
    Vec<int> my_vec_2(500000, 100);
    
    // start our timer
    clock_t t = clock();
    
    // this push_back allocates double the memory needed for the size of the Vec, so it doesn't have to call the memory allocator everytime. 
    for(Vec<int>::size_type i = 0; i != my_vec_2.size(); ++i){
        my_vec.push_back(i);
    }

    t = clock() - t;
    
    // how much time did it take??????
    cout<<t<<"\n";
    
    
    

    
    // how much longer did the push_back_2 take than the push_back function
    cout<< (t - m) << "\n";
    
    return 0;
}