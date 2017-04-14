#include "Vec.h"
#include "Str.h"
#include "split.h"
#include "frame.h"
#include<iostream>

using std::cout; using std::cin;

int main(){
    
    Str x = "hello world!";
    Str y;
    while(getline(cin,y)){
        Vec<Str> v = split(y);
        Vec<Str> f = frame(v);
        cout<< width(v) << "\n";
        
        for(Vec<Str>::const_iterator i = f.begin(); i != f.end(); ++i){
            cout<< *i <<"\n";
        }
        
        
    }
    /*
    Vec<Str> f = frame(v);
    for(Vec<Str>::const_iterator i = f.begin(); i != f.end(); ++i){
        cout<< *i <<"\n";
    }
    */
    
    return 0;
}