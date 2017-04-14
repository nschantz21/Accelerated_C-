#include <iostream>
using std::cout;

template<typename T>
void DisplayValue(T tValue){
    std::cout << tValue << "\n";
}

template<typename TYPE>
void PrintTwice(TYPE data){
    cout<<"Twice: " << data * 2 << "\n"; 
}

template<typename T>
T Add(T n1, T n2){
    return n1 + n2;
}

struct Currency{
    int Dollar;
    int Cents;
    
    operator double() { // there is a now a possible conversion from Currency to one of the types that ostream::operator<< takes.
        return Dollar + (double)Cents/100;
    }
    
    Currency operator+(Currency);
    
    
    
};

int main(){
    
    Currency x;
    x.Dollar = 10;
    x.Cents = 50;
    
    DisplayValue(x); // <int>
    PrintTwice(x);
    
    Add(x, 5.5);
    DisplayValue(x);
    return 0;
}