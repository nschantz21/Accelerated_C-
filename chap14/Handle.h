#ifndef GUARD_Handle
#define GUARD_Handle
#include<stdexcept> // runtime_error
#include<iostream> // istream
#include<string> // string




/*  Our Handle will have a restricted interface: Once you attach a Handle to an object, the Handle class will take over memory management for that object. Users should attach only one Handle to any object, after which they should not access the object directly through a pointer; all access should be through the Handle. These restrictions will allow Handles to avoid the problems inherent in built-in pointers. When we copy a Handle object, we'll make a new copy of the object, so that each Handle points to its own copy. When we destroy a Handle, it will destroy the associated object, and doing so will be the only straightforward way to free the object. We'll allow users to create unbound Handles, but we will throw an exception if the user attempts to access the object to which an unbound Handle refers (or, more accurately, doesn't refer). Users who want to avoid the exception can test to see whether the Handle is bound. */





template <class T> class Handle{
    public:
        Handle(): p(0) {} // null pointer
        // copy constructor - checks for object of copy target
        Handle(const Handle& s): p(0) { 
            if(s.p)
                p = s.p->clone(); 
        }
        Handle& operator=(const Handle&); // assignment constructor
        ~Handle() {delete p;} // destructor
        // Template magic
        // make Hanldle a copy of pointer to the Type T
        Handle(T* t): p(t) {} // binds the pointer to an object
        operator bool() const {return p;} // check if object is there
        T& operator*() const;
        T* operator->() const;
    
    private:
        T* p; 
};

// assignment copy constructor
template<class T> Handle<T>& Handle<T>::operator=(const Handle& rhs){
    if (&rhs != this) {
        delete p;
        // check if rhs.p has a value or set to null pointer
        p = (rhs.p) ? rhs.p->clone() : 0; // clone still needs to be defined
    }
    return *this;
}

template<class T>
T& Handle<T>::operator*() const { // return reference to underlying object
    if (p)
        return *p;
    throw std::runtime_error("unbound Handle");
}

template<class T>
T* Handle<T>::operator->() const{ // returns pointer of underlying object
    if (p)
        return p;
    throw std::runtime_error("unbound Handle");
}



#endif