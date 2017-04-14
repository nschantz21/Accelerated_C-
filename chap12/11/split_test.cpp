#include "Str.h"
#include "Vec.h"
#include "split.h"
#include <vector>
#include <iostream>

using std::vector; using std::cout;

int main(){
    
    Str my_string = "hello my baby hello my darling";
    
    vector<Str> v = split(my_string);
    for(vector<Str>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << "\n";
    }
    
    return 0;
}