#ifndef GUARD_Core_h
#define GUARD_Core_h
#include<iostream> // istream
#include<string> // string
#include<algorithm> // min
#include<vector> // vector
#include<stdexcept>
#include "Core_help.h"
#include "letter_grade_array.h"

// no longer represents all kinds of students, but only those students who meet the core requirements for the course
//  Records for graduate students will start with a G , and those for an undergraduate will start with a U .
class Core{ // base class
    friend class Student_info;
    
    public:
        // default Core constructor
        Core(): midterm(0), final(0) { std::cerr<<"Core"<<"\n"; } // added cerr output for 13-1
        Core(std::istream& is) { std::cerr<<"Core::Core(istream&)"<<"\n"; read(is); }
        std::string name() const;
        virtual std::istream& read(std::istream&);
        bool valid() const { return !homework.empty(); }
        virtual double grade() const; // for compare_grades function
        virtual ~Core() {}
        virtual bool has_thesis() const {return true;} // added for 13-5
        std::string Core_letter_grade() const { return letter_grade(grade()); } // 13-4
    protected:
        std::istream& read_common(std::istream&);
        double midterm, final;
        std::vector<double> homework;
        virtual Core* clone() const {return new Core(*this);}  // for Student_info copy()
        
    private:
        std::string n;
};

class Grad: public Core{ // dervied from or inherits from class Core
    protected:
        Grad* clone() const { return new Grad(*this);}
    
    public:
        // both constructors implicitly use Core::Core() to initialize the base part
        Grad(): thesis(0) { std::cerr<<"Grad"<<"\n"; }
        Grad(std::istream& is) { std::cerr<<"Grad::Grad(istream&)"<<"\n"; read(is); }
        // these two are virtual by inheritance
        double grade() const; // redefined from Core, uses different algorithm
        std::istream& read(std::istream&); // redefined
        bool has_thesis() const {return thesis > 0;}
    private:
        double thesis; // added member
        // also inherits name and read_common functions
        // inherits n, midterm, final, and homework
};

class Auditor: public Core {
    protected:
        Auditor* clone() const { return new Auditor(*this);} // for Student_info copy()
    public:
        double grade() const; // redefined for Auditor
        char pass_fail();
        // default constructors
        Auditor() {};
        // i think you need to add a read(is ) constructor function
        Auditor(std::istream& is) { std::cerr<<"Auditor::Auditor(istream&)"<<"\n"; Core::read(is); }
        bool valid() const {return true;}
        bool has_thesis() const {return true;}
};


std::string Core::name() const { std::cerr<<"Core::name()\n"; return n; }

double Core::grade() const{
    std::cerr<<"Core::grade()\n";
    return ::grade(midterm, final, homework); // this needs to be linked the grade header from chap 9
}

std::istream& Core::read_common(std::istream& in){
    // read and store the student's name and exam grades
    in >> n >> midterm >> final;
    return in;
}

std::istream& Core::read(std::istream& in){
    read_common(in);
    ::read_hw(in, homework); // from Student_info.h
    return in;
}

std::istream& Grad::read(std::istream& in){
    read_common(in);
    in>>thesis;
    ::read_hw(in, homework);
    return in;
}


double Grad::grade() const{
    std::cerr<<"Grad::grade()\n";
    return std::min(Core::grade(), thesis);  // scope operator is essential since we are calling to the base member function not the redefined derived class member function
}

bool compare(const Core& c1, const Core& c2){ // works with both core and grade as either argument - Core, Grad
    return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2){
    return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2){
    return compare(*cp1, *cp2);
}

// Auditor member functions
double Auditor::grade() const{
    if(homework.size() > 0)
        return Core::grade();
    else
        return (midterm + final) / 2;
}

char Auditor::pass_fail(){
    if (grade() >= 60)
        return 'P';
    else
        return 'F';
}

class Student_info { // this is our handle class
        // the idea is that this can represent either a Core or Grad class
    public:
        // constructors
        Student_info(): cp(0) {} // initialize to 0 so that the Student_info object is unbound (not Core or Grad)
        Student_info(std::istream& is): cp(0) {read(is);}
        Student_info(const Student_info&);
        Student_info& operator=(const Student_info&);
        ~Student_info() {delete cp;} // calls the virtual Core destructor
        
        // operations
        std::istream& read(std::istream&);
        
        
        std::string Core_letter_grade() const{
            if (cp) return cp->Core_letter_grade();
            else throw std::runtime_error("uninitialized Student");
        }
        std::string name() const {
            if (cp) return cp->name();
            else throw std::runtime_error("uninitialized Student");
        }
        double grade() const{
            if (cp) return cp->grade();
            else throw std::runtime_error("uninitialized Student");
        }
        bool valid() const{
            if (cp) return cp->valid();
            else throw std::runtime_error("uninitialized Student");
        }
        
        static bool compare(const Student_info& s1, const Student_info& s2){
            // redefining this allows us to use it in the std::sort (template) function because Student_info::compare is not overloaded
            // we don't need to check for exceptions because the name member function will do that for us
            return s1.name() < s2.name();
        }
        
        bool requirements(){
            return (cp->valid() && cp->has_thesis());
        }
        
    private:
        Core* cp; // pointer to a type Core object or type derived from Core
};

// 
std::istream& Student_info::read(std::istream& is){
    delete cp;  // delete previous object, if any
    
    char ch;
    is >> ch; // get record type
    
    if (ch == 'G') cp = new Grad(is);
    else if (ch == 'A') cp = new Auditor(is);
    else cp = new Core(is);
    
    return is;
}

Student_info::Student_info(const Student_info& s) : cp(0){
    if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s){ 
    // copy constructor
    if (&s != this){ // guard against self-assignment
        delete cp;
        if (s.cp)
            cp = s.cp->clone();
        else
        cp = 0;
    }
    return *this;
}



#endif

