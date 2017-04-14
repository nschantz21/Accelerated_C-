#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "split.h"
#include "gen_sent.h"
#include <stdexcept>
#include <list>

using std::string;  using std::vector;
using std::map; using std::cin;
using std::cout; using std::endl;
using std::domain_error; using std::logic_error;
using std::list;

int main(){
    // generate the sentance
    list<string> sentence = gen_sentence(read_grammar(cin));
    
    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()) {
        cout << *it;
        ++it;
    }
    
    // write the rest of the words, each preceded by a space
    while (it != sentence.end()) {
        cout <<" "<< *it;
        ++it;
    }
    
    cout << endl;
    return 0;
}