#include<iostream>
using namespace std;
class Fraction{
private:
    int m_numerator;
    int m_denominator;
public :
    Fraction(int num,int den=1):m_numerator(num),m_denominator(den){}
    operator double()const{
        return ((double )m_numerator/m_denominator);
    }
};

int main(){
    Fraction f(3,5);
    double a=f+4;
    cout<<a<<endl;
}