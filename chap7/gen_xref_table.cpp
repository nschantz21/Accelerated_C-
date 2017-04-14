#include <string>
#include <vector>
#include <map>
// i couldn't figure out how to get this to work as a seperate file
#include "cross.h"
#include "split.h"
#include "url_finder.h"
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::map;
using std::istream;
using std::endl;

// to compile use split.h, split.cpp,, cross.cpp, cross.h

// using xref to generate a cross reference table
// generate a cross-reference table that indicates where each word occurs in the input
int main(){
    
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin, find_urls);
    
    // write the results
    
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it){
        // write the word
        
        cout << it->first << " occurs on line(s): ";
        
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
            cout << *line_it; // write the first line
            
            ++line_it;
            
            // the bit iterator and logic statement prevents restament of line occurances
            vector<int>::const_iterator bit = line_it - 1;
            // write the rest of the line numbers, if any
            while (line_it != it->second.end()){
                if(*line_it != *bit){
                cout << ", "<< *line_it; 
                }
                ++line_it;
                ++bit;
            }
            
        cout<<endl;
        
    }
    
    return 0;
}