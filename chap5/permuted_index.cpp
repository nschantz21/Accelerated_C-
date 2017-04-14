#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>
#include "split.h"

using std::cin;     using std::cout;    
using std::endl;    using std::string;
using std::vector;



int main() {
    string s;
    // read and split each line of input
    while (getline(cin, s)) {
        // splits the sentence into individual words vector
        vector<string> v = split(s);
        // makes a copy of the split word vector for manipulation
        vector<string> p(v);
        
        
        // sort the copy based on the lower case of the first letter of each word
        sort(p.begin(), p.end(), compare);
        
        // print that sorted bitch
        for (vector<string>::size_type i = 0; i != p.size(); ++i){
            
            for (vector<string>::size_type j = 0; j != s.size(); ++j){
                
                if(p[i][0] == s[j] && 
                s[j, j + p[i].length()-1] == p[i][0, p[i].length()-1] && 
                isspace(s[j-1])){
                    
                    
                    string x = s.substr(j);
                    string y = s.substr(0, j);
                    cout<<y<< '\t' <<x<<endl;
                    
                    }
                }
                
            }
            
        }
    
        // split a sentence into words and store as a vector maybe as a pair including the index
        // sort the vector of words A-Z
        // print the word preceeded by the words before it in the sentence and proceeded by those that follow (use slicing and substrings)
        
    return 0;
}