#include <iostream>

#include "List.h"

using namespace std;

int main() {
  List<int> l0 = List<int>();
  int a1[] = {1, 2};
  List<int> l1 = List<int>(a1, a1 + 2);
  int a2[] = {3, 4};
  List<int> l2 = List<int>(a2, a2 + 2);
  List<int> l3;
  l3 = append(l1, l2);
  
  cout << "An empty List " << l0 << endl;
  cout << "Is the List empty? " << is_null(l0) << endl;
  cout << "Print everything in the List " <<  l1 << endl;
  cout << "List 1, element 0: " << List_ref(l1, 0) << endl;
  cout << "List 1, element 1: " << List_ref(l1, 1) << endl;
  cout << "Elements in List 3: " << l3 << endl;
  cout << "Return the reverse of List 3: " << reverse(l3) << endl;
  cout << "Is 2 in List 3? " << member<int>(2, l3) << endl;
  cout << "Is 0 in List 3? " << member<int>(0, l3) << endl;
  
  cout << "Incredible! He did it, the absolute madman! He made a list of two lists! \n" <<
  "List of List 1 and List 2: " << cons(l1, cons(l2, List< List<int> >())) << endl;

  return 0;
}