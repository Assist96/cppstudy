#include <iostream>
using namespace std;

class A{
public :
    A(){
        cout<<"this  is A Class"<<endl;
    }
    ~A(){
        cout<<"A is  end"<<endl;
    }
};

class B{
public :
    B(){
        cout<<"this  is B Class"<<endl;
    }
    ~B(){
        cout<<"B is  end"<<endl;
    }
};


class C:A{
public :
    B b ;
    C(){
        cout<<"this  is C Class"<<endl;
    }
    ~C(){
        cout<<"C is  end"<<endl;
    }
};


int main(){
    C c;
    cout<<"end..."<<endl;
}