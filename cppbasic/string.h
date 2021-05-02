#ifndef __MYSTRING__
#define __MYSTRING__
#include<cstring>
class String{
public:
    String(const char* cstr=0);
    String(const String& cstr);//拷贝构造
    String& operator=(const String& str );//拷贝赋值  
    ~String();//析构函数
    char* get_c_str()const {return m_data;}
private:
    char * m_data;
};
inline
String::String(const char* cstr){
    if (cstr){
        m_data=new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }
    else   {
        m_data=new char[1];
        *m_data='\0';
    }
}
inline 
String::~String(){
    delete[]m_data; 
}

inline //拷贝构造函数，如果类有指针，必须要有拷贝构造和拷贝赋值
        //，因为C++默认的拷贝构造函数只会赋值指针，这样两个变量指向
        //同一个指针，会发生意外情况以及内存泄漏
String::String(const String& str){
    m_data=new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}
inline
String& String::operator=(const String& str){
    if (&str==this){
        return *this;
    }
    delete []m_data;
    m_data=new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
    return *this;
}
// class ostream;
#include<iostream>
std::ostream &operator<<(std::ostream &os,const String& str){
    os<<str.get_c_str();
    return os;
}
#endif