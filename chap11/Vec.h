#ifndef GUARD_Vec
#define GUARD_Vec
#include<cstddef> // size_t, ptrdiff_t
#include<ostream> // operator 
#include<memory> // allocator, uninitialized_fill, uninitialized_copy
#include<algorithm> // max
 
// chap 11 Implementing the Vec Class
// we're going to create an immitation of the vector class


// Vec is a template class with one type parameter T
// we are going to store the data in a dynamically allocated array (new/delete pointers)
template <class T> class Vec{
    public:
        // interface
        T* allocate(std::size_t); // allocates typed but uninitialized storage sufficient to hold the requested number of elements
        void deallocate(T*, std::size_t); // frees this uninitialized storage.
        void construct(T*, const T&); // construct or destroy a single object in this uninitialized space
        void destroy(T*);
        
        Vec (const Vec& v) { create(v.begin(), v.end()); } // copy constructor; this is one case when it is essential that the parameter be a reference type.  copying an object should not change the object being copied from, so the constructor takes a const reference to the object from which to copy
        ~Vec() {uncreate();} // destructor.  cleanup that should be done whenever an object goes away. Typically, this cleanup involves releasing resources, such as memory, that the constructor has allocated
        
        Vec& operator=(const Vec&); // assignment operator. must be a member of the class. operator= that takes a const reference to the class itself is special. returns reference for consistency with built-in assignment operators
        
        typedef T* iterator; // random-access since we're using array to hold elements of Vec.  each pointer will point to the underlying data array
        typedef const T* const_iterator;
        typedef std::size_t size_type; // used size_t b/c it's able to hold any array size
        typedef T value_type; // synonym for type of the objects that the container holds, i.e. type T
        
        
        Vec() {create();} //default constructor. calls member function "create", which has data and limit set to 0 - it's empty container
        explicit Vec(size_type n, const T& val = T()) {create(n, val);} // 2nd constructor. Allows for value initialization, but uses 1st default contructor as default val parameter if not. calls member function "create".  the explicit means the comiler will only use the constructor in contexts in which the user expressly invokes the constructor, and not otherwise
        
        size_type size() const {return avail - data;} // size member function. returns ctype ptrdiff_t and converts to size_type (size_t) difference between iterators pointing to the first and last elements in the container Vec. declared as const function b/c it doen't change Vec, and allows us to call size() on a const Vec as well
        
        T& operator[](size_type i){ return data[i]; } // returns a reference to the first element of an element of Vec
        const T& operator[](size_type i) const { return data[i]; } // same but const
        // The reason to return a reference is that if the objects stored in the container are large, it is more efficient to avoid copying them.
        
        // functions to return iterators
        iterator begin() {return data;}
        const_iterator begin() const {return data;}
        iterator end() {return avail;}
        const_iterator end() const {return avail;}
        
        // push_back function
        void push_back(const T& val){
            if(avail == limit) // get space if needed
                grow();
            unchecked_append(val); //append the new element
        }
        
    private:
        // implementation
        iterator data; // pointer to first element in the Vec
        iterator limit; // pointer to one past the last element in the Vec
        // we will compute the size of the Vec using the difference between pointers.  There's no need to make another member.
        
        iterator avail; // pointer to (one past) the last constructed element
        
        // facilities for memory allocation
        std::allocator<T> alloc; // object to handle memory allocation
        
        // allocate and initialize the underlying array
        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator); // will work for both const and non-const iterators
        
        // destroy the elements in the array and free the memory
        void uncreate();
        
        // support functions for push_back
        void grow();
        void unchecked_append(const T&);
};  // remember this stupid semi-colon at the end of the class declaration

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs){
    // check for self-assignment
    if(&rhs != this){ // checks if address of end of array is equal to beginning of array
        
        // free the array in the left-hand side
        uncreate();
        
        // copy elements from the right-hand to the left-hand side
        create(rhs.begin(), rhs.end());
    }
    
    return (*this) ;
}

template <class T> void Vec<T>::create(){
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val){
    data = alloc.allocate(n); // allocate space for the number of elements in the array
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j){
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate(){
    if (data){ // the alloc.deallocate function requires a nonzero pointer
    
        // destroy in reverse order the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it); // we can decrememnt b/c it's a random access iterator
            
            // return all the space that was allocated  pointer to the first element of the memory to free, and an integral value that indicates how many elements of type T are to be freed
            alloc.deallocate(data, limit - data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
} 


// These functions initialize elements in space that is allocated by allocate
template <class Out, class T> void std::uninitialized_fill(Out, Out, const T&); // fills this uninitialized space with the specified value
template <class In, class Out> Out std::uninitialized_copy(In, In, Out); // copies values from a sequence specified by its first two arguments into a target sequence denoted by its third argument.  assumes that the target range contains raw storage, rather than elements that already hold values, and it constructs new objects in that memory
template <class T> void Vec<T>::grow(){
    // when growing, allocate max of twice as much space as currently in use or 1 if the array is empty
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));
    
    // It allocates more than it needs, so that subsequent calls to push_back can use the excess, avoiding the overhead of frequent memory allocations
    
    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    // saved as new variables so that when we destroy the old one it doesn't destroy the new size and data
    
    
    // return the old space
    uncreate();
    
    // reset pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

//builds an element in the first location after the constructed elements. assumes avail points at allocated, but uninitialized space
// we only call this after we call grow(), so we know it's safe
template <class T> void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}

#endif