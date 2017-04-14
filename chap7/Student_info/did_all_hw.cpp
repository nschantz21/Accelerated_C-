#include <algorithm>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;


int main(){
    

    // Students who did and didn't do all their homework
    vector<Student_info> did, didnt;
    
    // read the student records and partition them
    Student_info student;

    // read all the records, separating them based on whether all homework was done
    while (read(cin, student)){
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    
    // check that both groups contain data
    
    if (did.empty()){
        cout<<"No student did all the homework!"<<endl;
        return 1;
    }
    
    if (didnt.empty()){
        cout<<"every student did all the homework!"<<endl;
        return 1;
    }
    
    // do the analyses
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in ", optimistic_mean_analysis, did, didnt);
    
    return 0;
    
    
}