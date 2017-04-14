
#include <algorithm>
#include "Vec.h"
#include "frame.h"

#include "Str.h"


using std::max;

// same as the one from chap 5 except now using iterators

Str::size_type width(const Vec<Str>& v){
    Str::size_type maxlen = 0;
    for(Vec<Str>::const_iterator i = v.begin(); i !=v.end(); ++i){
        maxlen = max(maxlen, i->size());
    }
    return maxlen;
}

Vec<Str> frame(const Vec<Str>& v){
    Vec<Str> ret;
    Str::size_type maxlen = width(v);
    Str border((maxlen + 4), '*');
    
    //write the top border
    ret.push_back(border);
    
    //write each interior row, bordered by an asterisk and a space
    Vec<Str>::const_iterator i = v.begin();
    while(i != v.end()){
        ret.push_back("* " + *i + Str(maxlen - i->size(), ' ') + " *");
        ++i;
    }
    
    //write the bottom border
    ret.push_back(border);
    return ret;
}


// vertical concatenation
Vec<Str> vcat(const Vec<Str>& top, const Vec<Str>& bottom){
    // copy the top picture
    Vec<Str> ret = top;
    
    // copy entire bottom picture
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

// horizontal concatenation
Vec<Str> hcat(const Vec<Str>& left, const Vec<Str>& right){
    Vec<Str> ret;
    
    // add 1 to leave a space between pictures
    Str::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    Vec<Str>::const_iterator i = left.begin(), j = right.begin();
    
    Str s;
    
    // continue until we've seen all rows from both pictures
    while (i !=left.end() || j !=right.end()){
        //construct new Str to hold characters from both pictures
        
        
        // copy a row from the left-hand side, if there is one
        if (i !=left.end())
            s = *i++;
        
            // pad to full width
            s += Str(width1 - s.size(), ' ');
            
            // copy a row from the right-hand side, if there is one
        if (j != right.end())
            s += *j++;
        
        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}
