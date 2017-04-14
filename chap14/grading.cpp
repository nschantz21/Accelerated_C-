#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include"Handle.h"
#include"Core.h"
#include<iomanip>
#include<stdexcept>


using namespace std;

// exercise 14-1
bool compare_Core_pointers(const Ptr<Core>& hc1, const Ptr<Core>& hc2){
    return hc1->name() < hc2->name();
} 

int main(){
    vector< Ptr<Core> > students; // changed type
    Ptr<Core> record;
    char ch;
    string::size_type maxlen = 0;
    
    // read and store the data
    while (cin>>ch) {
        if (ch == 'U')
            record = new Core; // allocated a Core object
        else 
            record = new Grad; // allocate Grad object
        record->read(cin); // Handle<T>::->, then virtual call to read
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }
        
    // compare must be rewritten to work on const Handle<Core>&
    sort(students.begin(), students.end(),compare_Core_pointers);
    
    // write names and grades
    for (vector<Ptr<Core> >::size_type i = 0; i != students.size(); ++i){
        //students[i] is a Handle, which we dereference to call the functions
        cout << students[i]->name() << string(maxlen + 1 - students[i]->name().size(), ' ');
        try{
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << std::setprecision(3) << final_grade << std::setprecision(prec) << endl;
        } catch (domain_error e) {
            cout<<e.what()<<endl;
        }
        // no delete statement
    }
    return 0;
}