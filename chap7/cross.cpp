#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "split.h"
#include "cross.h"

// generating a cross reference table Chap 7.3

using std::map;
using std::string;
using std::vector;
using std::istream;



// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&)){
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    
    // read the next line
    while (getline(in, line)){
        
        ++line_number;
        
        // break the input into words
        vector<string> words = find_words(line);
        
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}