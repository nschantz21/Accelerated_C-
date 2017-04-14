#ifndef GUARD_Str
#define GUARD_Str

#include "Vec.h"
#include <cstring> // strlen
#include <iterator> // back_inserter, ostream_iterator
#include <algorithm> // copy, min
#include <iostream> // istream, ostream
#include <stdexcept> // out_of_range
// defining a Str class that lets us create objects that behave approx as we would like

class Str {
    friend std::istream& operator>>(std::istream&, Str&);
    friend Str operator+(const char&, const Str&);
    friend Str operator+(const Str&, const char&);
    friend std::istream& getline(std::istream&, Str&, const char = '\n');
    public:
        
        typedef Vec<char>::iterator iterator;
        typedef Vec<char>::const_iterator const_iterator;
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
        template<class In> Str(In b, In e): data(b, e) {}
        template<class In> void assign(In i, In j){
            data.assign(i, j);
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
        
        // The new functions
        const char* c_str() const { return data.begin(); } 
        const char* my_data() const { return c_str(); }
        // Copies a substring of the current value of the string object into the array pointed by s. This substring contains the len characters that start at position pos. The function does not append a null character at the end of the copied content.
        size_type copy(Vec<char>::iterator s, size_type n, size_type pos = 0) const;
        
        char* begin() {return data.begin();} // added so the test will work. you should add aliases for Vec::iterators
        const char* begin() const {return data.begin();}
        
        char* end() {return data.end();} // added so the test will work. you should add aliases for Vec::iterators
        const char* end() const {return data.end();}
        
        
        
        // relational operators
        bool operator==(const Str& x){
            return strcmp(x.begin(), this->begin()) == 0;
        }
        
        bool operator<(const Str& x){
            // if ptr 1 is less than ptr 2 it's negative
            return strcmp(this->begin(), x.begin()) < 0; 
        }
        
        bool operator>(const Str& x){
            return strcmp(x.begin(), this->begin()) < 0;
        }
        
        bool operator<=(const Str& x){
            return strcmp(this->begin(), x.begin()) <= 0;  
        }
        
        bool operator>=(const Str& x){
            return strcmp(x.begin(), this->begin()) >= 0;
        }
        
        bool operator!=(const Str& x){
            return strcmp(x.begin(), this->begin()) != 0;
        }
        
        
        operator void*() const{
            static int dummy;
            if (this->size() > 0){
                return &dummy;
            }else{
                return 0;
            }
        }
        
        bool operator!() const{
            static int dummy;
            if (this->size() > 0){
                return 0;
            }else{
                return &dummy;
            }
        }
        
        
        Str substr(size_t pos, size_t len) const {
            return Str(begin() + pos, begin() + pos + len);
        }
        
        template<class In> void insert(iterator p, In i, In j){
            return data.insert(p, i, j);
        }
        
        private:
            Vec<char> data;
            // we rely on the synthesized destructor, copy operator, and assignment operator because the Str class itself doe no memory allocation.  
            // we don't need a destructor because the Vec does it for us
};


std::istream& getline(std::istream& is, Str& s, const char seperator){
    while(is){
        char c;
        while (is.get(c) && c==seperator)
        ; // nothing to do, except testing the condition
        
        do s.data.push_back(c);
        while(is.get(c) && c!=seperator);
        
        // get rid of trailing whitespace
        // if we read whitespace, then put it back on the stream
        if(is)
            is.unget();
    }
}

// must be non-member functions
std::istream& operator>>(std::istream&, Str&); // cin
std::ostream& operator<<(std::ostream&, const Str&); // cout

// output operator
std::ostream& operator<<(std::ostream& os, const Str& s){
    std::ostream_iterator<char> out_it (os);
    std::copy(s.begin(), s.end(), out_it);
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

// concatenation that doesn't rely on char to Str conversion.  works directly with char pointers
Str operator+(const Str&, const char&);
Str operator+(const Str& s, const char& t){
    Str r = s;
    r.data.push_back(t);
    return r;
}

Str operator+(const char&, const Str&);
Str operator+(const char& t, const Str& s) {
    Vec<char> r(1, t);
    Vec<char>::size_type i = 0;
    while (i != s.size()){
        r.push_back(s[i]);
        ++i;
    }
    return Str(r.begin());
}


// copy(pointer to target array of characters, Number of characters to copy, Position of the first character to be copied.)
// this is fucking retarded. it just uses the std::copy function
Str::size_type Str::copy(char* s, size_type n, size_type pos) const {
    
  if (pos > size()) throw std::out_of_range("pos > size()");
  
  size_t copy_length = std::min(n, size() - pos);
  
  std::copy(data.begin() + pos, data.begin() + copy_length, s);
  return copy_length;
}






#endif