#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
 

int main()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
    std::vector<int>::iterator result;
 
    result = std::max_element(v.begin(), v.end());
    std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';
}