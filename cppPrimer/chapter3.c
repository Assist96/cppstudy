#include<string>
#include<iostream>
using namespace std;
// int main(){
//     string line ;
//     while (getline(cin,line))
//     {
//         auto size=line.size();
//         decltype(size) a=10;
//         cout<<line<<" size is " <<size<<" and size's type is "<<typeid(size).name()<<endl;
//     }
    
// }
// int main(){
//     string line ;
//     while (cin >> line)
//     {
//         auto size=line.size();
//         decltype(size) a=10;
//         cout<<line<<" size is " <<size<<" and size's type is "<<typeid(size).name()<<endl;
//     }
    
// }
string big_string(const string& str1,const string & str2 ){
    if (str1>str2){
        return str1;
    }
    else return str2;
}
string long_string(const string& str1,const string & str2 ){
    if (str1.size()>str2.size()){
        return str1;
    }
    else return str2;
}
// int main(){
//     cout<<"Please enter two words,and this will return the big/long  one "<<endl;
//     string str1,str2;
//     cin>>str1>>str2;
//     cout<<"the big one is "<<big_string(str1,str2)<<endl
//     <<"the long one is "<<long_string(str1,str2)<<endl;
// }

void bind_str(string &str1,const string &str2){
    str1+=str2;
}

void bind_str_space(string &str1,const string &str2){
    str1=str1+" "+str2;
}
// int main(){
//     string str,res;
//     while (cin>>str)
//     {
//         if (str=="#"){
//             break;
//         }
//         bind_str(res,str);
//     }
//     cout<<"the binded str is '"<<res<<"'"<<endl;
    
// }

// int main(){
//     string str;
//     cin>>str;
//     for (char &c : str){
//         c='X';
//     }
//     cout<<"result is:"<<str<<endl;
// }

// int main(){
//     string str;
//     cin>>str;
//     int i=0;
//     while (str[i]!='\0'){
//         str[i]='X';
//         ++i;
//     }
//     cout<<"result is:"<<str<<endl;
// }
// int main(){
//     string str;
//     cin>>str;
//     for(unsigned int i=0;i<str.size();++i){
//         str[i]='X';
//     }
//     cout<<"result is:"<<str<<endl;
// }

// int main(){
//     string s;
//     cout<<s[0]<<endl;
// }
#include<cctype>
// int main(){
//     string str;
//     getline(cin,str);
//     for (auto &c : str){
//         if (!ispunct(c)){
//             cout<<c;
//         }
//     }
//     cout<<endl;
    
// }

// int main(){
//     const string str="Keep out!";
//     for (auto &c :str){
//         cout<<c;
//         // c='x';
//     }
//     cout<<endl;
// }
//--------------------------------3.3
#include <vector>
using std::vector;
// int main(){
// string str="some string ";
// for (auto iter=str.begin();iter!=str.end()&&!isspace(*iter);++iter){
//     *iter=toupper(*iter);
// }
// cout<<str<<endl;
// }

int get_index(const string &text,const char sought){
auto beg=text.begin();
auto end=text.end();
auto mid=text.begin()+(end-beg)/2;
while(mid!=end&& *mid !=sought){
    if (sought<*mid){
        end=mid;
    }
    else{
        beg=mid+1;
    }
    mid=beg+(end-beg)/2;

}
    return mid-text.begin();
}
// int main(){
// string text="123456789";
// auto index=get_index(text,'2');
// cout<<index<<endl;
// }
template <class T>
void print_vector(const vector<T> &in)
{
    if (in.cbegin() != in.cend())
    {
        for (auto beg = in.cbegin(); beg != in.cend(); ++beg)
        {
            cout << (*beg);
        }
    }

    cout << endl;
}
// int main(){
//     vector<int> v1;
//     vector<int> v2(10);
//     vector<int> v3(10,42);
//     vector<int> v4{10};
//     vector<int> v5{10,42};
//     vector<string> v6{10};
//     vector<string> v7{10,"hi"};
//     print_vector(v1);
//     print_vector(v2);
//     print_vector(v3);
//     print_vector(v4);
//     print_vector(v5);
//     print_vector(v6);
//     print_vector(v7);

// }
// int main(){
//     string text="asda dasda adada   dsjajdpoajdpoa";
//     for (auto it=text.begin();it!=text.end() &&!isspace(*it);++it){
//         *it=toupper(*it);
//         cout<<*it;
//     }
//     cout<<endl;
// }

// int main(){
//     vector<int> tmp(10,22);
//     for(auto beg=tmp.begin();beg!=tmp.end();++beg){
//         *beg=(*beg)*2;
//         cout<<*beg;
//     }
//     cout<<endl;
// }

// int main(){
//     vector<int> vInt;
//     int iVal;
//     while(cin>>iVal){
//         vInt.push_back(iVal);
        
//     }
//     if (vInt.cbegin()==vInt.cend()){
//         cout<<"no number"<<endl;
//     }
//     cout<<"near two sum is :"<<endl;
//     for (auto it=vInt.cbegin();it!=vInt.cend()-1;it++){
//         cout<<*it+*(++it)<<endl;
//     }
//     if (vInt.size()%2!=0){
//         cout<<*(vInt.cend()-1);
//     }
// }


// int main(){
//     vector<int> vInt;
//     int iVal;
//     while (cin>>iVal)
//     {
//         vInt.push_back(iVal);
//     }
//     if (vInt.cbegin()==vInt.cend()){
//         cout<<"vInt is Empty"<<endl;
//     }
//     for (auto it=vInt.cbegin();it!=vInt.cbegin()+(vInt.end()-vInt.cbegin())/2;++it){
//         cout<<*it+*(vInt.begin()+(vInt.cend()-it-1))<<endl;
//     }
//     if (vInt.size()%2!=0){
//         cout<<*(vInt.cbegin()+(vInt.end()-vInt.cbegin())/2)<<endl;
//     }
    
// }

// int main(){
//    int a[10]={1,1,1,1,1,1,1,1,1,1};
// //    int *p=a;
// //    for (int i=0;i<10;++i){
// //        *p++=0;
// //    } 
//     int *p=begin(a);
//     while ( p!=end(a))
//     {
//         *p++=0;
//     }
    
//    cout<<"end"<<endl;
// }
template <class T>
bool compare_array(const T  &a , const   T &b){
   
    if ((end(a)-begin(a))!=(end(b)-begin(b))){
        return false;
    }
   const int * p=begin(a);
   const int  *q=begin(b);
    while (p!=end(a)&&q!=end(b))
    {
        if (*p++!=*q++){
            return false;
        }
    }
    return true;
}
template <class T>
bool compare_vector(const vector<T> &a,const vector<T> &b){
    if((a.cend()-a.cbegin())!=(b.cend()-b.cbegin())){
        return false;
    }
    auto it_a=a.cbegin();
    auto it_b=b.cbegin();
    while (it_a!=a.cend()&&it_b!=b.cend())
    {
        if(*it_a++!=*it_b++){
            return false;
        }
    }
    return true;
}
// int main(){
//     // int a[3]={1,2,3};
//     // int b[3]={1,2,3};
//     // bool res=compare_array(a,b);
//     vector<int> a={1,2,3};
//     vector<int> b={1,2,3};
//     bool res=compare_vector(a,b);
//     cout<<"end"<<endl;
// }
#include<cstring>
using namespace std;
// int main(){
//     char a[]="123";
//     char b[]="456";
//     char c[7];
//     strcpy(c,a);
//     strcat(c,b);
//     cout<<c<<"end"<<endl;
// }
#include<ctime>
#include<cstdlib>
// int main(){
//     const int sz=10;
//     int a[sz];
//     srand((unsigned)time(NULL));
//     cout<<"array is :"<<endl;
//     for(auto &i:a){
//         i=rand()%100;
//         cout<<i<<endl;
//     }
//     vector<int> vInt(begin(a),end(a));
//     for(auto val:vInt){
//         cout<<val<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     const int sz=10;
//     int a[sz];
//     srand((unsigned)time(NULL));
//     cout<<"array is :"<<endl;
//     for(auto &i:a){
//         i=rand()%100;
//         cout<<i<<endl;
//     }
//     vector<int> vInt(begin(a),end(a));
//     for(auto val:vInt){
//         cout<<val<<" ";
//     }
//     cout<<endl;
// }

// 

// int main(){
//     int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
//     cout<<"range_for out is :"<<endl;
//     for(int (&raw)[4]:a){
//         for (int & col :raw){
//             cout<<col<<" ";
//         }
//         cout<<endl;
//     }
// cout<<"index of array out is :"<<endl;
//     for (int i =0;i<3;++i){
//         for(int j=0;j<4;++j){
//             cout<<a[i][j]<<" ";

//         }
//         cout<<endl;
//     }
//     cout<<"iter_for out is :"<<endl;
//     for (int (*p)[4]=a;p!=a+3;p++){
//         for (int *q=*p;q!=*p+4;++q){
//             cout<<*q<<" ";
//         }
//         cout<<endl;
//     }
// }

// using int_array=int[4];
// int main(){
//     int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
//     cout<<"range_for out is :"<<endl;
//     for(int_array &raw :a){
//         for (int & col :raw){
//             cout<<col<<" ";
//         }
//         cout<<endl;
//     }
// cout<<"index of array out is :"<<endl;
//     for (int i =0;i<3;++i){
//         for(int j=0;j<4;++j){
//             cout<<a[i][j]<<" ";

//         }
//         cout<<endl;
//     }
//     cout<<"iter_for out is :"<<endl;
//     for (int_array (*p) =a;p!=a+3;p++){
//         for (int *q=*p;q!=*p+4;++q){
//             cout<<*q<<" ";
//         }
//         cout<<endl;
//     }
// }


// using int_array=int[4];
// int main(){
//     int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
//     cout<<"range_for out is :"<<endl;
//     for(auto  &raw :a){
//         for (auto & col :raw){
//             cout<<col<<" ";
//         }
//         cout<<endl;
//     }
// cout<<"index of array out is :"<<endl;
//     for (int i =0;i<3;++i){
//         for(int j=0;j<4;++j){
//             cout<<a[i][j]<<" ";

//         }
//         cout<<endl;
//     }
//     cout<<"iter_for out is :"<<endl;
//     for (auto p =a;p!=a+3;p++){
//         for (auto *q=*p;q!=*p+4;++q){
//             cout<<*q<<" ";
//         }
//         cout<<endl;
//     }
// }

int fact(int n){
    int res=1;
    while (n>=1)
    {
        res=res*n;
        --n;
    }
    return res;
}
int abs(int i){
    // return 
    if (i>0) return i;
    else return 0-i;
}
// int main(){
// //    int i=0;
//   //  cout<<i<<endl<<++i<<endl<<i++<<endl;
//   cout<<"please enter n:"<<endl;
//   int n=0;
//   cin>>n;
//   cout<<"fact(n) is :"<<fact(n)<<endl;

//   int i=-10;
//     cout<<"abs(i) is :"<<abs(i)<<endl;
// }
void swap(int *p ,int * q){
    int tmp=*p;
    *p=*q;
    *q=tmp;
}

// int main(){
//     int i=0,j=1;
//     swap(&i,&j);
//     cout<<i<<" "<<j<<endl;
//     const int a=i;

// }
string::size_type find_char(const string &s,char c,string::size_type &occours){
    auto ret=s.size();
    occours=0;
    for (decltype(ret) i=0;i!=s.size();++i){
        if(s[i]==c){
            if(ret==s.size()){
                ret=i;
            }
            ++occours;
        }
    }
    return ret;
}

int compare(const int a,const int *b){
    if (a>*b){
        return a;
    }
    else{
        return *b;
    }
}

void swap_p(int*a,int *b){
    int *c=a;
    a=b;
    b=c;
}
void swap_p1(int*a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
void swap_p2(int*&a,int *&b){
    int *c=a;
    a=b;
    b=c;
}

// int main(){
//     int a=10,i=20,j=30;
//     int *b,*c;
//     b=&i;
//     c=&j;
//     int cc=compare(a,b);
//     cout<<"orignal is :"<<b<<" "<<c<<endl;
//     swap_p2(b,c);
//     cout<<"result is :"<<a<<" "<<*b<<" "<<*c<<endl;
//     cout<<"result is :"<<b<<" "<<c<<endl;
// }
void print(const int *p){
    cout<<*p<<endl;
}

void print2(const int *p,const int sz){
    int i=0;
    while (i!=sz)
    {
        cout<<*p++<<endl;
        ++i;
    }
    
}
void print3(const int *p,const int *e){
    while (p!=e)
    {
        cout<<*p++<<endl;
    }
    
}
// int main(){

//     int i=0,j[2]={0,1};
//     print(&i);
//     print2(&i,1);
//     // print3()
//     print(j);
//     print2(j,sizeof(j)/sizeof(*j));
//     print3(begin(j),end(j));
// }

// int main(int argc,char *argv[]){
//     string str;
//     for     (int i=0;i<argc;++i){
//         str+=argv[i];
//     }
//     cout<<str<<endl;
// }

int iCount(initializer_list<int> li){
    int cnt=0;
    for(auto val:li){
        cnt+=val;
    }
    return cnt;
}
int main(){
    cout<<"1,6,9  :"<<iCount({1,6,9})<<endl;
    cout<<"22,2,2,2,2,2,6,9  :"<<iCount({22,2,2,2,2,2,6,9})<<endl;
    cout<<"1,1,1,1,1,1,1,1  :"<<iCount({1,1,1,1,1,1,1,1})<<endl;
}