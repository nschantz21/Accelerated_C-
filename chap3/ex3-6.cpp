// Exercise 3-6
// change how C++ handles an undefined values for the final grade

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>  

using namespace std;

int main()
{
    cout << "Please, enter your name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
        "followed by end-of-file: ";
    int count = 0;
    double sum;
    
    // variable into which to read
    double x;

    // invariant: homework contains all the homework grades read so far
    while( cin >> x ) {
        ++count;
        sum += x;
    }
    double hm_wk = sum/count;
        cout<<hm_wk<<endl;
    
    if (isnan(hm_wk) == false){
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * hm_wk
            << setprecision(prec) << endl;
    }else{
        cout<<"Well that's not right"<<endl;
    }
    
    return 0;
}