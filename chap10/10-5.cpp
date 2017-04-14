#include <iostream>

#include "string_list.h"

using namespace std; // this is bad form, but fine for testing

// 10-5. Write a bidirectional iterator for your String_list class.
// this just tests the iterator.  the iterator itself was created in the header

int main() {
  string arr1[] = {"Hello", "to", "the", "world!"};
  list<string> a = list<string>(arr1, arr1 + 4);
  list<string>::const_iterator i = a.begin();

  // Test equality
  if (a.begin() == a.begin())
    cout << "The beginning" << endl; // Should print "The beginning"

  // Test inequality
  if (a.begin() != a.end())
    cout << "Is not the end" << endl; // Should print "Is not the end"

  // Test dereference
  cout << *i << endl; // Should print "Hello"
  cout << i->size() << endl; // Should print 5, from "Hello"

  // Test increment
  ++i;
  cout << *i << endl; // Should print "to"
  i++;
  cout << *i << endl; // Should print "the"
  cout << *i++ << endl; // Should print "the"
  cout << *i << endl; // Should print "World!"

  // Test decrement
  --i;
  cout << *i << endl; // Should print "the"
  i--;
  cout << *i << endl; // Should print "to"
  cout << *i-- << endl; // Should print "to"
  cout << *i << endl; // Should print "Hello"
  
  return 0;
}