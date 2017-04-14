#include "Core.h"
#include <iostream> // cin and cout
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>



using std::string; using std::vector; using std::sort;
using std::domain_error; using std::cin; using std::cout;
using std::max; using std::streamsize; using std::setprecision;
using std::endl;

//  Records for graduate students will start with a G , and those for an undergraduate will start with a U .

int main(){
    Core* p1 = new Core;
    Core* p2 = new Grad;
    Core s1;
    Grad s2;
    p1->grade();
    p1->name();
    p2->grade();
    p2->name();
    s1.grade();
    s1.name();
    s2.name();
    s2.grade();
    
    
    
    
    return 0;
}