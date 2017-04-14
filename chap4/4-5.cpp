#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    


    string x;
    vector<string> names;
    int total = 0;

    cout<<"Enter the names of your students, then press Ctrl-D when finished:"<<endl;
    while( cin>>x ) {
        
        names.push_back(x);
        total ++;
    }// you have to press ctrl-D to break the loop
    
    cout<<endl;
    

    
    
    for(vector<string>::size_type i = 0; i != names.size(); i++ ){
        
        int p = 0;
        for(vector<string>::size_type j = 0; j != names.size(); j++ ){
            
            
            if(names[i].compare(names[j])==0){
                    p++;
            }
        
        }
        
        cout<<names[i]<<"\t"<<p<<endl;
    }
    
    
    vector<string> unique(names.begin(), names.end());
    
    for(vector<string>::size_type i = 0; i != unique.size(); i++ ){
        cout<<unique[i]<<endl;

    }
    
    cout<<"there are "<<total<<" students in the class"<<endl;
    
    return 0;
}