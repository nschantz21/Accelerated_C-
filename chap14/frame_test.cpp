#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include "split.h"
#include "Vec.h"
#include "Str.h"
#include "frame.h"

using std::cin;     using std::cout;    
using std::endl;


int main() {
    Str s;
    // read and split each line of input
    
    
    while(getline(cin, s)){
        Vec<Str> v = split(s);
        Vec<Str> f = frame(v);
        Vec<Str> vc = vcat(f, f);
        Vec<Str> hc = hcat(vc, vc);
        // write each word in v
        for (Vec<Str>::size_type i = 0; i != hc.size(); ++i)
            cout << hc[i] << endl;
    }
    return 0;
}