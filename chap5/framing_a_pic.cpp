#include <string>
#include <vector>
#include <algorithm>
#include "frame.h"

using std::vector; using std::string; using std::max;

// same as the one from chap 5 except now using iterators

string::size_type width(const vector<string>& v){
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i !=v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
        return maxlen;
}

vector<string> frame(const vector<string>& v){
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    //write the top border
    ret.push_back(border);
    
    //write each interior row, bordered by an asterisk and a space
    vector<string>::iterator i = ret.begin()
    while(i != ret.end()){
        ret.push_back("* " + v[*i] + string(maxlen - v[(*i)].size(), ' ') + " *");
        ++i;
    }
    
    //write the bottom border
    ret.push_back(border);
    return ret;
}


// vertical concatenation
vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
    // copy the top picture
    vector<string> ret = top;
    
    // copy entire bottom picture
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

// horizontal concatenation
vector<string> hcat(const vector<string>& left, const vector<string>& right){
    vector<string> ret;
    
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<string>::const_iterator i = left.begin(), j = right.begin();
    
    string s;
    
    // continue until we've seen all rows from both pictures
    while (i !=left.end() || j !=right.end()){
        //construct new string to hold characters from both pictures
        
        
        // copy a row from the left-hand side, if there is one
        if (i !=left.end())
            s = left[*i++];
        
            // pad to full width
            s += string(width1 - s.size(), ' ');
            
            // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += right[*j++];
        
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
