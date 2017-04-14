#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>

#include <vector>
#include <stdexcept>
#include <cctype>
#include "split.h"
#include "frame.h"
#include "Str.h"

using std::cin;     using std::cout;    
using std::endl;    
using std::vector;



int main() {
    Str s;
    // read and split each line of input
    
    
    while (getline(cin, s)) {
        
        
        vector<Str> v = split(s);
        vector<Str> f = frame(v);
        vector<Str> vc = vcat(f, f);
        vector<Str> hc = hcat(vc, vc);
        // write each word in v
        for (vector<Str>::size_type i = 0; i != hc.size(); ++i)
            cout << hc[i] << endl;
        
        
        
    }
        
    return 0;
}