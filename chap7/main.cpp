#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>

using std::string;  using std::map;
using std::cin;     using std::cout;
using std::endl;    using std::sort;
using std::pair;    using std::vector;

// this shit took me way too fucking long


// compares based on value of pairs
bool compare_value(pair<string, int> x, pair<string, int> y){
    return y.second < x.second;
}

//counting words using maps
// returns each unique word and the number of occurances as pairs
int main(){
    
    string s;
    map<string, int> counters; // store each word and an associated counter
    
    //read the input, keeping track of each word and how often we see it
    while(cin >> s){
        string::iterator t = s.begin();
        
        //converts all the letters to lowercase
        while(t != s.end()){
            *t = tolower(*t);
            ++t;
        }
        
        // initializes the key value in the map and adds one to its value counter
        ++counters[s];
    }
    
    // copy contents of the map to a vector of pairs
    vector<pair<string, int> > mapcopy(counters.begin(), counters.end());
    
    
    // sort the vector of pairs based on the values
    sort(mapcopy.begin(), mapcopy.end(), compare_value);
    
    //write the words and associated counts
    for (vector<pair<string, int> >::const_iterator it = mapcopy.begin(); it != mapcopy.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
    }
    
	return 0;
}