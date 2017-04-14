#ifndef GUARD_Ref_Handle
#define GUARD_Ref_Handle
#include<stdexcept> // runtime_error
#include<iostream> // istream
#include<string> // string

template<class T>class Ref_handle{
    public: 
        //manage reference count as well as pointer
        Ref_handle(): refptr(new size_t(1), p(0)) {}
        Ref_handle(T* t): refptr(new size_t(1), p(t)) {}
        Ref_handle(const Ref_handle& h): refptr(h.refptr), p(h.p) {
            // copy contructor doesn't make a new object
            // it copies the pointer it was passed
            // and increments the counter
            ++*refptr;
        }
        
        // assignment manipulates the reference count, but doesn't make new object
        Ref_handle& operator=(const Ref_handle&);
        ~Ref_handle();
        
        //as before
        operator bool() const { return p; }
        T& operator*() const {
            if (p)
                return *p;
            throw std::runtime_error("unbound Ref_handle");
        }
        
        T* operator->() const {
            if (p)
                return p;
            throw std::runtime_error("unbound Ref_handle");
        }
        
    private:
        T* p;
        size_t* refptr; // initialized by the constructors
    
};



// handle that never copies
// acts like a reference
template<class T> 
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs){
    ++*rhs.refptr;
    // freee the left hand side, destroying pointers if appropriate
    if (--*refptr == 0){
        delete refptr;
        delete p;
    }
    // copy in values from the right-hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template<class T> Ref_handle<T>::~Ref_handle(){
    if (--*refptr == 0){
        delete refptr;
        delete p;
    }
}

#endif