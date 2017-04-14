// Exercise 3-3
// Write a program to count how many times each distinct word appears in its input



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    vector<int> counts;
    
    cout<<"Please write the names of your friends: "<< endl;
    
    
    for(string word; cin >> word && word !="end"; )
    {
        bool found = false;
        int size = (int) words.size();
        for(int i = 0; i < size; i++)
        {
            if(words[i] == word) {
                counts[i]++; 
                found = true;
                break;
            }
        }
        if(!found) {
            words.push_back(word);
            counts.push_back(1);
        }
    }

    int size = (int) words.size();
    for(int i = 0; i < size; i++)
        cout << words[i] << " " << counts[i] << endl;

    return 0;
}