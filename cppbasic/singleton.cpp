class A{
public:
    static A& getInstance();
    void setup();
private:
A();
A(const A& rhs);
// static A a;

};

inline
A& A::getInstance(){
    static A a;
    return a;
}