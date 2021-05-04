#include<iostream>
using namespace std;

class OpenDocument{
public:
    void onFileOPen(){
        cout<<"dialog..."<<endl;
        cout<<"open file .."<<endl;
        Serialize();
        Serialize_1();
        cout<<"close file ..."<<endl;
        cout<<"update all views..."<<endl;
    
    }
    virtual void Serialize()=0;
    virtual void Serialize_1(){ cout<<"parent second serialize ";
    }
};

class CMyDoc:public OpenDocument{
public:
    virtual void Serialize(){
        cout<<"son first Serialize"<<endl;
    }
    virtual void Serialize_1(){
        cout<<"son second serialzie"<<endl;
    }
};

int main(){
    CMyDoc d;
    d.onFileOPen();
}