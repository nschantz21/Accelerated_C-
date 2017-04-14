#ifndef GUARD_Str_1201
#define GUARD_Str_1201

#include <cstring>
#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>



class Str {
    public:
        // aliasing
        typedef std::size_t size_type; 
        typedef char* iterator;
        typedef const char* const_iterator;
        
        // constructors
        Str() { create(0, '\0'); } // setting up a null terminated character array
        Str(size_type n, char c) { create(n, c); }
      
        Str(const Str& s) { create(s.begin(), s.end()); }
        Str& operator =(const Str&); // assignment operator
        ~Str() { uncreate(); } // destructor
        Str(const char* cp) { create(cp, cp + std::strlen(cp)); } // create Str from character pointer, also works as type converter
        template <class In> Str(In i, In j) { create(i, j); } // creates Str using iterators, like if you only want part of a Str
    
        char& operator [](size_type i) { return chars[i]; }
        const char& operator [](size_type i) const { return chars[i]; }
        size_type size() const { return length - 1; } // subtract 1 because of the null character
    
        // points to initial element
        iterator begin() { return chars; }
        const_iterator begin() const { return chars; }
    
        // includes the null character
        iterator end() { return chars + length - 1; } 
        const_iterator end() const { return chars + length - 1; }
        
        // like the string class, data() and c_str() member functions return pointers to initial character element
        const char* c_str() const { return chars; }
        const char* data() const { return chars; }
        
        size_type copy(iterator, size_type, size_type = 0) const;
    
        // concatenation/assignment operator
        Str& operator +=(const Str&);
        // member function: does the Str have any elements
        operator bool() const { return (size() > 0); }
        
        // member function to get substring of Str
        Str substr(size_type, size_type) const;
        template <class In> void insert(iterator, In, In);

    private:
        // chars is null-terminated, has length - 1 non-null chars
        size_type length;
        iterator chars;
        // memory allocator
        std::allocator<char> alloc;
        
        
        void create(size_type, char);
        template <class In> void create(In, In);
        void uncreate();

        void grow(size_type);
};

// Public functions
template <class In> void Str::insert(iterator p, In i, In j) {
    // get the total length of the new Str
    size_type new_length = length + (j - i);
    // allocated enough memory for the new length
    iterator new_chars = alloc.allocate(new_length);
    // uninitialized_copy(start, stop, target_location)
    // put the old Str, from beginning up to the indicated position (p) into the newly allocated memory
    std::uninitialized_copy(chars, p, new_chars);
    // copy the selection (i,j] after p
    std::uninitialized_copy(i, j, new_chars + (p - chars));
    // copy the rest of the original Str into the new Str after the length of the inserted Str, while leaving room for the null
    std::uninitialized_copy(p, chars + length - 1, new_chars + (p - chars) + (j - i));
    // put the null at one before the end
    alloc.construct(new_chars + new_length - 1, '\0');
    // get rid of the old Str
    uncreate();
    // assign the new attributes
    length = new_length;
    chars = new_chars;
}

// Private functions
template <class In> void Str::create(In i, In j) {
    length = (j - i) + 1; // add one for the null
    chars = alloc.allocate(length);
    std::uninitialized_copy(i, j, chars);
    alloc.construct(chars + length - 1, '\0');
}

// Other functions
std::ostream& operator <<(std::ostream&, const Str&);
std::ostream_iterator<char>& operator <<(std::ostream_iterator<char>&, const Str&);
std::istream& operator >>(std::istream&, Str&);
std::istream& getline(std::istream&, Str&);

Str operator +(const Str&, const Str&);
Str operator +(const char*, const Str&);
Str operator +(const Str&, const char*);

inline bool operator <(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) < 0);
}

inline bool operator >(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

inline bool operator <=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

inline bool operator >=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) >= 0);
}

inline bool operator ==(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}

inline bool operator !=(const Str& lhs, const Str& rhs) {
    return (std::strcmp(lhs.c_str(), rhs.c_str()) != 0);
}


#endif