#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;

/* 
    url_finder.cpp
    scans a document and finds all the URLs in it
    looks for a sequence of characters in the form of "protocol-name://resource-name"
    Our function will take a string argument and will look for
    instances of :// in that string. Each time we find such an instance, we'll look for the
    protocol-name that precedes it, and the resource-name that follows it.
    
*/


// not_url_char will return true when passed a character that cannot be in a URL:
bool not_url_char(char c){
    // characters, in addition to alphanumerics, that can appear in a URL
    // Local variables that are declared to be static are preserved across invocations of the function.
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    
    // see whether c can appear ub a URL and return the negative
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
    return find_if(b, e, not_url_char);
}


/*
    The url_beg
    function will be responsible for identifying whether a valid URL is present and, if so, for
    returning an iterator that refers to the first character of the protocol-name. If it does not identify
    a URL in the input, then it will return its second argument (e in this case) to indicate failure.
*/

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
    static const string sep = "://";
    typedef string::const_iterator iter;
    
    // i marks where the separator was found
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e){
        
        // make sure the serperator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e){
            
            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
            --beg;
            // is there at least one appropriate character before and after the separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
            
        }
        
        // the seperator we found wasn't part of a URL advance i past this separator
        i += sep.size();
    }
    return e;
}
    




// returns a vector of strings containing the URLs
vector<string> find_urls(const string& s){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    // look through the entire input
    while (b != e){
        
        // look for one or more letters followed by "://"
        b = url_beg(b, e);
        
        // if we found it
        if(b != e){
            // get the rest of the URL
            iter after = url_end(b,e);
            
            // remember the URL
            ret.push_back(string(b,after));
            
            // advance b and check for more URLs on this line
            b = after;
        }
    }
    
    return ret;
}