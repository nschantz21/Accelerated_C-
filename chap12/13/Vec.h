#ifndef GUARD_Vec_11_6
#define GUARD_Vec_11_6
#include<cstddef> // size_t, ptrdiff_t
#include<ostream> // operator 
#include<memory> // allocator, uninitialized_fill, uninitialized_copy, destroy
#include<algorithm> // max
#include<iterator>
#include<cstring>


 
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
        void destroy(T*); // Destroys in-place the object pointed by T; this does not deallocate the storage for the element
        
        Vec (const Vec& v) { create(v.begin(), v.end()); } // copy constructor; this is one case when it is essential that the parameter be a reference type.  copying an object should not change the object being copied from, so the constructor takes a const reference to the object from which to copy
        ~Vec() {uncreate();} // destructor.  cleanup that should be done whenever an object goes away. Typically, this cleanup involves releasing resources, such as memory, that the constructor has allocated
        
        Vec& operator=(const Vec&); // assignment operator. must be a member of the class. operator= that takes a const reference to the class itself is special. returns reference for consistency with built-in assignment operators
        
        typedef T* iterator; // random-access since we're using array to hold elements of Vec.  each pointer will point to the underlying data array
        typedef const T* const_iterator;
        typedef std::size_t size_type; // used size_t b/c it's able to hold any array size
        typedef T value_type; // synonym for type of the objects that the container holds, i.e. type T
        
        // input construct
        template <class In> Vec(In i, In j) { create(i, j); }
        
        Vec() {create();} //default constructor. calls member function "create", which has data and limit set to 0 - it's empty container
        explicit Vec(size_type n, const T& val = T()) {create(n, val);} // 2nd constructor. Allows for value initialization, but uses 1st default contructor as default val parameter if not. calls member function "create".  the explicit means the comiler will only use the constructor in contexts in which the user expressly invokes the constructor, and not otherwise
        // explicit Vec(size_t n, size_t m) {create(n, m);}
        
        
        
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
        
        void push_back_2(const T& val){
            if(avail == limit) // get space if needed
                grow_2();
            unchecked_append(val); //append the new element
        }        
        
        // constructor based on pointer
        // this is shitty though, it should be a template based on the iterator
        Vec(std::string x){
            create();
            for(std::string::iterator i = x.begin(); i != x.end(); ++i){
                push_back(*i);
            }
        }
        
        // 11-6 exercises
        iterator erase(iterator position) { // erases a single element of the Vec
            // starting with the iterator denoting the position of the element, we destroy the object pointed to by the iterator
            for (iterator i = position; i != avail; ++i){
                alloc.destroy(i);
                if ((i + 1) != avail) 
                    alloc.construct(i, *(i + 1)); // construct a copy of the object pointed to by the next iterator in the current position
            }
            --avail; // decrement pointer to the last constructed element
            // note that this does not deallocate the memory the memory initially allocated for the object
            return position;
        }
        
        void clear(){ uncreate(); } // deletes all the elements of Vec and deallocates the memory
        
        
        typedef T& reference; // for the back inserter
        typedef const T& const_reference; // for back inserter
        // for back inserter
        // back_inserter is a convenience function template that constructs a std::back_insert_iterator for the container c with the type deduced from the type of the argument. Container must support push_back function
        template< class Container >
            std::back_insert_iterator<Container> back_inserter( Container& c ){
                return std::back_insert_iterator<Container>(c);
                }
                
        template <class In> void insert(iterator p, In i, In j) {
            // get the total length of the new Vec
            size_type new_size = size() + (j - i);
            // allocated enough memory for the new length
            iterator new_data = alloc.allocate(new_size);
            // uninitialized_copy(start, stop, target_location)
            // put the old Str, from beginning up to the indicated position (p) into the newly allocated memory
            std::uninitialized_copy(data, p, new_data);
            // copy the selection (i,j] after p
            std::uninitialized_copy(i, j, new_data + (p - data));
            // copy the rest of the original Str into the new Str after the length of the inserted Str, while leaving room for the null
            iterator new_avail = std::uninitialized_copy(p, avail, new_data + (p - data) + (j - i));
            // get rid of the old Str
            uncreate();
            // assign the new attributes
            
            data = new_data;
            avail = new_avail;
            limit = data + new_size;
        }
        
        template <class In> void assign(In i, In j) {
            create(i, j);
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
        //void create(const_iterator, const_iterator); // will work for both const and non-const iterators
        template <class In> void create(In, In);
        // destroy the elements in the array and free the memory
        void uncreate();
        
        // support functions for push_back
        void grow();
        void grow_2();
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

template <class T> template <class In> void Vec<T>::create(In i, In j) {
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


// second grow function that only allocates one for each value added
template <class T> void Vec<T>::grow_2(){

    // when growing, allocate max of twice as much space as currently in use or 1 if the array is empty
    size_type new_size = std::size_t(limit) + std::ptrdiff_t(1);
    
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