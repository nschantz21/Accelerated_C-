#include <iterator> // 
#include <stdexcept> // domain_error
#include <algorithm> // sort
#include <vector> // vector
#include <iostream> //cout endl

using std::vector;
using std::sort; using std::domain_error;


using std::cout; using std::endl;


// 10-2
// Rewrite the median function from §8.1.1/140 so that we can call it with either a vector or
// a built-in array. The function should allow containers of any arithmetic type.

template <class T, class Iterator>
T median_by_iter(Iterator begin, Iterator end) {
  if (begin == end)
    throw domain_error("median of an empty container");
  
  vector<T> temp;
  
  for ( ; begin != end; ++begin)
    temp.push_back(*begin);

  sort(temp.begin(), temp.end());

  size_t mid = temp.size() / 2;

  T ret = (temp.size() % 2 == 0)
    ? (temp[mid] + temp[mid - 1]) / 2
    : temp[mid];

  return ret;
}

int main(){
    int my_array[] = {0, 1,  2, 3, 4};
    vector<int> my_vec(my_array, my_array + 5);
    
    int med_array = median_by_iter<int>(my_array, my_array + 5);
    int med_vec = median_by_iter<int>(my_vec.begin(), my_vec.end());
    
    
    cout << med_array << "\t" << med_vec << endl;
    return 0;
}