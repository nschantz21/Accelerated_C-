#ifndef GUARD_List
#define GUARD_List

#include <cstdarg>
#include <memory> // uninitialized_copy, alloctaor, construct
#include <iostream>

template <class T> class List {
    
    // some friend functions (non-member functions) to access the class private members
  template <class U> friend List<U> cons(const U&, const List<U>&); // push_front
  template <class U> friend U car(const List<U>&);
  template <class U> friend List<U> cdr(const List<U>&);
  template <class U> friend size_t length(const List<U>&);

public:
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T& reference;
  typedef const T& const_reference;

  List() { resize(0); }
  List(const List& other) { clone(other.data, other.avail); }
  List(const_iterator b, const_iterator e) { clone(b, e); }
  List& operator=(const List&);
  ~List() { destroy(); }

  const_iterator begin() const { return data; }
  const_iterator end() const { return avail; }

private:
  iterator data;
  iterator avail;
  std::allocator<value_type> alloc;

  void clone(const_iterator, const_iterator);
  void destroy();
  void resize(size_type);
};

template <class T> bool is_null(const List<T>&);
template <class T> T List_ref(const List<T>&, size_t);
template <class T> List<T> append(const List<T>&, const List<T>&);
template <class T> List<T> reverse(const List<T>&);
template <class T> List<T> member(const T&, const List<T>&);

template <class T> std::ostream& operator<<(std::ostream&, const List<T>&);

// Class public functions
template <class T> List<T>& List<T>::operator=(const List<T>& other) { // assignment
  if (this != &other) {
    destroy();
    clone(other.data, other.avail);
  }

  return *this;
}

// Class private functions
template <class T> void List<T>::clone(const_iterator b, const_iterator e) { // copy function
  resize(e - b);
  std::uninitialized_copy(b, e, data);
}

template <class T> void List<T>::destroy() { // destructor
  if (data) {
    for (iterator it = data; it != avail; ++it) alloc.destroy(it);
    alloc.deallocate(data, avail - data);
  }
  
  data = avail = 0;
}

template <class T> void List<T>::resize(size_type n) { // resizer
  data = alloc.allocate(n);
  avail = data + n;
}

// Friend functions
template <class T> List<T> cons(const T& e, const List<T>& l) { // push_front function
  List<T> new_l; // make new list
  new_l.resize(length(l) + 1); // set it's length equal to copied list
  new_l.alloc.construct(new_l.data, e); // put the value in the first element
  std::uninitialized_copy(l.data, l.avail, new_l.data + 1); // copies into the old list into the second element
  return new_l;
}

template <class T> T car(const List<T>& l) { // return first element of List
  if (is_null(l)) return T(); // check if there's anything there
  return l.data[0];
}

// these are to replace the random access iterators we used in Vec.h
// this is stupid because the Arrays that we're using already support random-access iterators
template <class T> List<T> cdr(const List<T>& l) { // makes copy from the sencond element to the last  
  if (is_null(l)) return List<T>();
  List<T> new_l;
  new_l.resize(length(l) - 1); // make it one smaller
  std::uninitialized_copy(l.data + 1, l.avail, new_l.data); // copies starting from the second element
  return new_l;
}

template <class T> size_t length(const List<T>& l) { // standard length function
  return l.avail - l.data;
}

// Other functions
template <class T> bool is_null(const List<T>& l) { // checks is List is empty
  return (length(l) == 0);
}

// acts as random access iterator, returns lvalue based on position
template <class T> T List_ref(const List<T>& l, size_t i) { 
  if (i == 0) return car(l); // return value if first element of List
  // this essentially removes the first element of the List and decrements the index
  // it will converge on the element (i) that you wanted and return that because it will be the first element in the new List created by cdr function
  return List_ref(cdr(l), i - 1);
}


template <class T> List<T> app_helper(const List<T>& l1, const List<T>& l2) {
  if (is_null(l1)) return l2;
  // calls the push_front function
  // puts the first element from l1 at the beginning of l2
  List<T> new_l2 = cons(car(l1), l2);
  
  // recursively does this for every element in l1
  return app_helper(cdr(l1), new_l2);
}

// concatenates two Lists
template <class T> List<T> append(const List<T>& l1, const List<T>& l2) {
  // calls reverse so that the order of l1 stays the same when added to l2
  return app_helper(reverse(l1), l2);
}

template <class T> List<T> rev_helper(const List<T>& l1, const List<T>& l2) {
  if (is_null(l1)) return l2;
  
  // recursively add the first element of l1 to the front of l2, then drop the first element from l1
  // you end up with a reverse list
  return rev_helper(cdr(l1), cons(car(l1), l2));
}

// returns reversed copy of supplied List
template <class T> List<T> reverse(const List<T>& l) {
  return rev_helper(l, List<T>());
}



template <class T> List<T> member(const T& e, const List<T>& l) {
  if (is_null(l)) return List<T>();
  
  if (e == car(l)) return l;
  // recursively check quality between value e and all elements of l
  return member(e, cdr(l));
}

template <class T> void print(std::ostream& out, const List<T>& l) {
  if (is_null(l)) return;
  // print first character of l
  out << car(l) << " ";
  // iterate thorugh and print each element
  print(out, cdr(l));
  // important to note that this does not return the ostream
}

template <class T> std::ostream& operator<<(std::ostream& out, const List<T>& l){
  out << "( ";
  print(out, l);
  out << ")";
  return out;
}

#endif