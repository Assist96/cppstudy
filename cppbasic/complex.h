#ifndef __COMPLEX__ //防卫式声明（即引入时首先检查是否声明过）
#define __COMPLEX__//未声明过即声明
//--------------------------------------------------
#include<cmath>
class ostream;
class complex;
complex& __doapl(complex* ths,const complex& r);
//---------------------------------------------------
class complex
{
private:
    double re,im;
    friend complex& __doapl(complex*,const complex &);//友元函数 可以
    /* data */
public:
    complex(double r=0,double i=0)
        :re(r),im(i)//初始列 initialization list<==>{re=r;im=i;}
    {}
    complex& operator+=(const complex&);//参数传递最好传递引用
    double real() const{ return re;}//const 说明 该函数不改变变量 
    double imag() const{ return im;}
    // ~complex();
};
//---------------------------------------------------
inline complex&
__doapl(complex* ths,const complex &r){
    ths->re+=r.re;
    ths->im+=r.im;
    return *ths;
}
inline complex&
complex::operator +=(const complex& r){
    return __doapl(this,r);
}

inline double
imag(const complex& x){
    return x.imag();
}
inline double 
real(const complex& x){
    return x.real();
}
//--- 不可以使用reference 因为返回的是某个local object ，即创建了一个空间
inline complex
operator +(const complex& x,const complex& y){
    return complex(real(x)+real(y),
                    imag(x)+imag(y));// 创建了临时对象 没有名称就是临时对象
}
inline complex
operator +(const complex& x,double y){
    return complex(real(x)+y,imag(x));
}
inline complex
operator +(double x,const complex& y){
    return complex(x+real(y),imag(y));
}
//---
inline complex
operator +(const complex& x){
    return x;
}
inline complex 
operator -(const complex& x){
    return complex(-real(x),-imag(x));
}
inline bool
operator ==(const complex& x,const complex&y){
    return (real(x)==real(y)&&imag(x)==imag(y));
}
inline bool
operator ==(const complex& x,double y){
    return (real(x)==y&&imag(x)==0);
}
inline bool
operator ==(double x,const complex& y){
    return (x==real(y)&&imag(y)==0);
}
inline bool
operator !=(const complex& x,const complex&y){
    return (real(x)!=real(y)||imag(x)!=imag(y));
}
inline bool
operator !=(const complex& x,double y){
    return (real(x)!=y||imag(x)!=0);
}
inline bool
operator !=(double x,const complex& y){
    return (x!=real(y)||imag(y)!=0);
}
inline complex
conj(const complex& x){
    return complex(real(x),-imag(x));
}
#include<iostream>
// #include <ostream>
ostream&
operator <<(ostream& os,const complex& x){
    return os <<'('<<real(x)<<','<<imag(x)<<')';
}
//----------------------------------------------------
#endif
//1 数据都要在 private
//2 参数 尽量使用 reference （引用类型）来传 
//3 返回值尽量使用 reference （引用类型）来传
//4 在类中的函数能加 const 的尽量加 
//5 尽量使用构造函数的 initialization