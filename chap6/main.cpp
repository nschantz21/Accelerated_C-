#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>
#include "split.h"
#include "frame.h"

using std::cin;     using std::cout;    
using std::endl;    using std::string;
using std::vector;



int main() {
    string s;
    // read and split each line of input
    
    
    while (getline(cin, s)) {
        
        
        vector<string> v = split(s);
        vector<string> f = frame(v);
        vector<string> vc = vcat(f, f);
        vector<string> hc = hcat(vc, vc);
        // write each word in v
        for (vector<string>::size_type i = 0; i != hc.size(); ++i)
            cout << hc[i] << endl;
    
        
        
    }
        
    return 0;
}