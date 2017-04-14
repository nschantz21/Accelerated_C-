#include <vector>
#include <algorithm>
#include "frame.h"

using std::vector; using std::max;

// same as the one from chap 5 except now using iterators

Str::size_type width(const vector<Str>& v){
    Str::size_type maxlen = 0;
    for(vector<Str>::size_type i = 0; i !=v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
        return maxlen;
}

vector<Str> frame(const vector<Str>& v){
    vector<Str> ret;
    Str::size_type maxlen = width(v);
    Str border(maxlen + 4, '*');
    
    //write the top border
    ret.push_back(border);
    
    //write each interior row, bordered by an asterisk and a space
    vector<Str>::iterator i = ret.begin();
    while(i != ret.end()){
        ret.push_back("* " + v[*i] + Str(maxlen - v[(*i)].size(), ' ') + " *");
        ++i;
    }
    
    //write the bottom border
    ret.push_back(border);
    return ret;
}


// vertical concatenation
vector<Str> vcat(const vector<Str>& top, const vector<Str>& bottom){
    // copy the top picture
    vector<Str> ret = top;
    
    // copy entire bottom picture
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

// horizontal concatenation
vector<Str> hcat(const vector<Str>& left, const vector<Str>& right){
    vector<Str> ret;
    
    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<Str>::const_iterator i = left.begin(), j = right.begin();
    
    Str s;
    
    // continue until we've seen all rows from both pictures
    while (i !=left.end() || j !=right.end()){
        //construct new Str to hold characters from both pictures
        
        
        // copy a row from the left-hand side, if there is one
        if (i !=left.end())
            s = left[*i++];
        
            // pad to full width
            s += Str(width1 - s.size(), ' ');
            
            // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += right[*j++];
        
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
