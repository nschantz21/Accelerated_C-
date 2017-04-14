#include <cctype>
#include "split.h"
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>

using std::cin;     using std::cout;    
using std::endl;    using std::string;
using std::vector;

int main() {
    string s;
    // read and split each line of input
    
    
    while (getline(cin, s)) {
        string up;
        string low;
        int i = 0;
        while(s[i]){
            char c = s[i];
            up.push_back(toupper(c));
            low.push_back(tolower(c));
            
            i++;
            
        }
        
        
        
        vector<string> v1 = split(up);
        vector<string> v2 = split(low);
        
        for (vector<string>::size_type i = 0; i != v1.size(); ++i)
            cout << v1[i] << endl << v2[i] << endl;
    
        
        
    }
        
    return 0;
}
