#include "Vec.h"
#include <cstring> // strlen
#include <iterator> // back_inserter
#include <algorithm> // copy
#include <iostream> // istream, ostream
// defining a Str class that lets us create objects that behave approx as we would like

class Str {
    friend std::istream& operator>>(std::istream&, Str&);
    
    public:
        
        
        typedef Vec<char>::size_type  size_type;
        // used in operator<<
        size_type size() const { return data.size(); }
        
        // default constructor
        Str() {};
        
        // create a Str containing n copies of c
        // uses the corresponding Vec constructor to construct data
        Str(size_type n, char c): data(n, c) {}
        
        // create a Str from a null-terminated array of char
        // also acts as a type converter when using assignment operator as long as pointer to const char is available
        Str(const char* cp){
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
        }
        
        // create a Str from the range denoted by iterators b and e
        template<class In> Str(In b, In e){
            std::copy(b, e, std::back_inserter(data));
        }
        
        // index operator; must be part of class
        // they just forward their work to the corresponding Vec operations
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }
        
        // concatenation and assignment operator
        Str& operator+=(const Str& s){
            std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
            return *this;
        }
        
        
        
        
        private:
            Vec<char> data;
            // we rely on the synthesized destructor, copy operator, and assignment operator because the Str class itself doe no memory allocation.  
            // we don't need a destructor because the Vec does it for us
};

// must be non-member functions
std::istream& operator>>(std::istream&, Str&); // cin
std::ostream& operator<<(std::ostream&, const Str&); // cout

// output operator
std::ostream& operator<<(std::ostream& os, const Str& s){
    for(Str::size_type i = 0; i != s.size(); ++i)
        os<<s[i];
    return os;
}

// input operator
std::istream& operator>>(std::istream& is, Str& s){
    // obliterator existing value(s)
    s.data.clear();
    
    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ; // nothing to do, except testing the condition
        
    // if still something to read, do so wuntil next whitespace character
    if(is){
        do s.data.push_back(c);
        while(is.get(c) && !isspace(c));
        
        // get rid of trailing whitespace
        // if we read whitespace, then put it back on the stream
        if(is)
            is.unget();
    }
}

// declaration of function
Str operator+(const Str&, const Str&);
// definition of function
Str operator+(const Str& s, const Str& t){
    // we copy the left Str using the synthesized copy constructor
    Str r = s;
    // use the member function, concat/assignment operator
    r+= t;
    return r;
}