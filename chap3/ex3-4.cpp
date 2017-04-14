// Exercise 3-4
// Write a program to report the length of the longest and shortest string in its input


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// add input to vector and if it's shorter than items in vector, add it to the beginning, if longer, add it to the end

int main()
{
    vector<string> words;
    vector<int> counts;

    
    cout<<"Please write the names of your friends: "<< endl;
    
    string x;
    while( cin >> x && x != "end" ) {
        int y = x.length();
        words.push_back(x);
        counts.push_back(y);
    }

    std::vector<int>::iterator result;
    result = std::max_element(counts.begin(), counts.end());
    int position = std::distance(counts.begin(), result);
    
    std::vector<int>::iterator result2;
    result2 = std::min_element(counts.begin(), counts.end());
    int position2 = std::distance(counts.begin(), result2);
    
    std::cout << "the longest word is " << words[position] << '\n';
    cout<< "it is "<< words[position].length()<< " letters long"<< endl;
    std::cout << "the shortest word is " << words[position2] << '\n';
    cout<< "it is "<< words[position2].length()<< " letters long"<< endl;
    
    return 0;
    
}
