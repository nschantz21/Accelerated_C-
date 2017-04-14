// program to find palindromes in dictionary
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include <ios>
#include <list>
#include <ctime>
#include <algorithm>
#include "split.h"



using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::list;
using std::endl;
using std::max;

bool contains_letter(const string& x){
    string mystring = "bdfhktlgjpqy";
    int count = 0;

    for(string::size_type j = 0; j != x.size(); j++){

        for(string::size_type k = 0; k != mystring.size(); k++){
            
            if (count > 0 || x[j] == mystring[k]){
                ++count;
                break;
            }
        
        }
    }
    
    return count > 0;
}

int main(){
    
    std::clock_t start;
    start = std::clock();
    std::ifstream file;
    list<string> dict;
    file.open("words.txt");
    string word;

    
    while(file >> word){

            if(!contains_letter(word)){
                dict.push_back(word);
        }
    }
    
    string::size_type maxlen = 0;
    list<string>::iterator l = dict.begin();
    while(l != dict.end()){
        cout<<(*l)<<endl;
        maxlen = max(maxlen, (*l).size());
        ++l;
        
    }
    

    cout<<dict.size()<<endl;
    dict.sort(compare_word_size);
    cout<<"the longest word without ascenders or descenders is "<< dict.back() << " with a length of "<< maxlen << " characters" << " Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    
    
    return 0;
    
}
    