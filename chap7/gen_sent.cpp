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
using std::map; using std::istream;
using std::domain_error; using std::logic_error;
using std::list;

// gen_sent.cpp
//read a grammar from a given input stream

Grammar read_grammar(istream& in){
    Grammar ret;
    string line;
    
    // read input
    while(getline(in, line)){
        // split the input into words
        vector<string> entry = split(line);
        if(!entry.empty())
        // use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}


bool bracketed(const string& s){
    return (s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>');
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret){
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to 'word'
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        
        // from which we select one at random
        const Rule& r = c[nrand(c.size())];
        
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

// return a random integer
int nrand(int n){
    if (n<= 0)
        n = -n;
    if(n > RAND_MAX)
        n = n/RAND_MAX;
        
    const int bucket_size = RAND_MAX / n;
    int r;
    
    do r = rand() / bucket_size;
    while (r>=n);
    
    return r;
}

list<string> gen_sentence(const Grammar& g){
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}