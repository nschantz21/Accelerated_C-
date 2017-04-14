#ifndef GUARD_Str
#define GUARD_Str

#include<algorithm>
#include<cstring>
#include<iostream>
#include"Vec.h"
#include"Ptr.h"

template<> Vec<char>* clone(const Vec<char>*);

class Str {
    friend std::istream& operator>>(std::istream&, Str&);
    friend std::istream& getline(std::istream&, Str&);
    public:
        Str& operator+=(const Str& s) {
            data.make_unique();
            std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
            return *this;
        }
        
        typedef Vec<char>::size_type size_type;
        
        typedef char* iterator;
        typedef const char* const_iterator;
        
        iterator begin() { return data->begin(); }
        const_iterator begin() const { return data->begin(); }

        iterator end() { return data->end(); }
        const_iterator end() const { return data->end(); }
        
        // reimplement constructors to create Ptrs
        Str(): data(new Vec<char>) { }
        
        Str(const char* cp): data(new Vec<char>) {
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
        }
        
        
        Str(size_type n, char c): data(new Vec<char>(n, c)) { }
        // template iterator constructor
        template<class In> Str(In i, In j): data(new Vec<char>) {
            std::copy(i, j, std::back_inserter(*data));
        }
        
        // call make_unique as necessary
        char& operator[](size_type i) {
            data.make_unique();
            return (*data)[i];
        }
        // random-access index operator
        const char& operator[](size_type i) const { return (*data)[i]; }
        
        size_type size() const { return data->size(); }
        
        Str substr(size_t pos, size_t len) const {
            if(pos > data->size()){
                throw std::out_of_range( "pos out of range" );
            } else
            return Str(data->begin() + pos, data->begin() + pos + len);
        }
    private:
        // store a Ptr to a vector
        Ptr< Vec<char> > data;
};

// as implemented in §12.3.2/216 and §12.3.3/219
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);




#endif