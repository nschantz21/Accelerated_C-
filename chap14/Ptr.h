#ifndef GUARD_Ptr
#define GUARD_Ptr
#include<cstddef>
#include<stdexcept> // runtime_error
#include"Ref_count.h"

template<class T> class Ptr {
    public:
        // member to copy the object conditionally when needed
        void make_unique(){
            if ( refptr.val() != 1 ){
                --refptr;
                refptr = Ref_count();
                p = p? clone(p) : 0; // checks if p has a value before copying, and uses the global clone function
            }
        }
        
        // the rest of the class looks like Ref_handle except for its name
        Ptr(): p(0) {}
        Ptr(T* t): p(t) {}
        Ptr(const Ptr& h):  p(h.p), refptr(h.refptr) { ++refptr; }
        
        Ptr& operator=(const Ptr&) ;
        ~Ptr();
        operator bool() const { return p; }
        T& operator*() const {
            if (p)
                return *p;
            throw std::runtime_error("unbound Ptr");
        }
        
        
        T* operator->() const{
            if (p)
                    return p;
            throw std::runtime_error("unbound Ptr");
        }
        
    private:
        T* p;
        Ref_count refptr; // initialized by the constructors
};

// global clone function
template<class T> T* clone(const T* tp){
    return tp->clone();
}

template<class T> 
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs){
    ++rhs.refptr;
    --refptr;
    // free the left hand side, destroying pointers if appropriate
    if (refptr.val() == 0){
        delete p;
    }
    // copy in values from the right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template<class T> Ptr<T>::~Ptr(){
    --refptr;
    if (refptr.val() == 0){
        delete p;
    }
}

#endif