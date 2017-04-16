
// private classes for use in the implementation only
class Pic_base {}; // base class - needs to be declared before derived classes

// class declarations
class String_Pic: public Pic_base {}; // declaring an inheritance from Pic_base class
class Frame_Pic: public Pic_base {};
class Vcat_Pic: public Pic_base {};
class Hcat_Pic: public Pic_base {};

// public interface class and operations
class Picture {
    public:
        Picture(const std::vector<std::string>& = std::vector<std::string>());
    private:
        Ptr<Pic_base> p;
};

// output operator for Picture class
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

