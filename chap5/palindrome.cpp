// program to find palindromes in dictionary
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include <ios>
#include <list>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include "split.h"


using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::list;
using std::max;


int main(){
    
    std::clock_t start;
    start = std::clock();
    std::ifstream file;
    list<string> dict;
    file.open("words.txt");
    string word;
    
    
    list<string> palindromes;
    
    while(file >> word){
        dict.push_back(word);
    }
    cout<<dict.size()<<std::endl;
    
    
    // the whole dictionary takes forever since you are itorating through two lists with 350k+ members
    
    dict.resize(75000);
    
    list<string> reversed(dict);
    
    
    for(list<string>::iterator i = reversed.begin(); i!=reversed.end(); i++){
        reverse((*i).begin(), (*i).end());
    }
    
    list<string>::iterator j = dict.begin();
    list<string>::iterator k = reversed.begin();
    
    
    while (j != dict.end()){
        
        while (k != reversed.end()){
            if (compare_same_first(*j, *k) && *j == *k)
                palindromes.push_back(*j);
                
            ++k;
            
        }
        ++j;    
        k=reversed.begin();
    }
    
    string::size_type maxlen = 0;
    list<string>::iterator l = palindromes.begin();
    while (l != palindromes.end()){
        cout<<(*l)<<std::endl;
        maxlen = max(maxlen, (*l).size());
        ++l;
    }
    
    palindromes.sort(compare_word_size);
    cout<<"the longest palindrome is "<< palindromes.back() << " with a length of "<< maxlen << " characters" << " Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    return 0;
     
}