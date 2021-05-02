#include "string.h"
#include <iostream>
using namespace std;

int main(){
    String s1;
    String s2("Hello");
    String s3(s1);
    cout<<s3<<std::endl;
    s3=s2;
    cout<<s3<<std::endl;
}