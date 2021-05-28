#include<string>
#include<iostream>
#include<istream>
using namespace std;
// struct Sales_data{
//     Sales_data()=default;
//     Sales_data(const string &bn,unsigned n,double p):bookNo(bn),units_sold(n),revenue(p*n){}
//     Sales_data(const string &bn):bookNo(bn){}
//     Sales_data(istream &is){
//         double price=0;
//         is>>this->bookNo>>this->units_sold>>price;
//         this->revenue=this->units_sold*price;
//     }
//     std::string bookNo;
//     unsigned units_sold=0;
//     double revenue=0.0;
//     string isbn() const {return bookNo;}
//     string isbn()  {return bookNo;}
//     Sales_data& combine(const Sales_data&);
//     double avg_price() const;
//     Sales_data& __doapl(Sales_data *,const Sales_data &);
//     Sales_data& operator+=(const Sales_data &rhs);
//     // string get_a(string str);
//     // string get_a(const string & str);
// };
class Sales_data{
    friend Sales_data add(const Sales_data &,const Sales_data&);
    friend std::ostream &print(std::ostream& ,const Sales_data&);
    friend std::istream &read(std::istream& ,Sales_data&);
    friend Sales_data& __doapl(Sales_data *,const Sales_data &);
    // friend ostream &operator<<(ostream &,const Sales_data& );
    // friend istream &operator>>(istream &  ,Sales_data & );
public:
    Sales_data()=default;
    Sales_data(const string &bn,unsigned n,double p):bookNo(bn),units_sold(n),revenue(p*n){}
    Sales_data(const string &bn):bookNo(bn){}
    Sales_data(istream &is){
        double price=0;
        is>>this->bookNo>>this->units_sold>>price;
        this->revenue=this->units_sold*price;
    }
    string isbn() const {return bookNo;}
    // string isbn()  {return bookNo;}
    double us() const {return units_sold;}
    double re() const {return revenue;}
    double avg() const {return avg_price();}
    void setbn(const string & s){bookNo=s;}
    void setu(double u){units_sold=u;}
    void setr(double r){revenue=r;}
    Sales_data& combine(const Sales_data&);
    Sales_data& operator+=(const Sales_data &rhs);
private:
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
    double avg_price() const;
    
};
Sales_data add(const Sales_data &,const Sales_data&);
std::ostream &print(std::ostream& ,const Sales_data&);
std::istream &read(std::istream& ,Sales_data&);
// string &bn(Sales_data& item){
//     return &(item.isbn());
// }
double us(const Sales_data&item){
    return item.us();
}
double re(const Sales_data&item){
    return item.re();
}
string bn(const Sales_data&item){
    return item.isbn();
}
inline 
Sales_data& __doapl(Sales_data *ths,const Sales_data &rhs){
    ths->units_sold+=rhs.units_sold;
    ths->revenue+=rhs.revenue;
    return *ths;
}
inline 
Sales_data &Sales_data::operator +=(const Sales_data &rhs){
    return __doapl(this,rhs);
}
inline 
ostream &operator<<(ostream &os,const Sales_data&rhs){
   return  os<<bn(rhs)<<" "<<us(rhs)<<" "<< re(rhs)<<" "<<rhs.avg()<<" ";
}
inline 
istream &operator>>(istream &is ,Sales_data &rhs){
    double price=0;
    string bn_s;
    double _us;
    is>>bn_s>>_us>>price;
    rhs.setbn(bn_s);
    rhs.setu(_us);
    rhs.setr(price*_us);
    return is;
}
double Sales_data::avg_price() const{
    if(units_sold){
        return revenue/units_sold;
    }
    else{
        return 0;
    }
}
Sales_data& Sales_data::combine(const Sales_data& rhs){
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
std::istream &read(istream &is,Sales_data &item){
    double price=0;
    is >> item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}
std::ostream &print(std::ostream& os,const Sales_data& item){
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
// int main(){
//     cout<<"请输入交易记录（ISBN、销量、原价、实际售价）："<<endl;
//     Sales_data total;
//     if(read(cin,total)){
//         Sales_data trans;
//         while (read(cin,trans))
//         {
//             if(total.isbn()==trans.isbn()) total+=trans;
//             else{
//                 print(cout,total);
//                 cout<<endl;
//                 total=trans;
//             }
//         }
//         print(cout,total);
//         cout<<endl;
        
//     }
//     else{
//         cout<<"No data?!"<<endl;
//         return -1;
//     }
// return 0;
// }


// int main(){
//     Sales_data data1;
//     Sales_data data2("zy-0101");
//     Sales_data data3("zy-0101",100,128);
//     Sales_data data4(cin);
//     cout<<"book is :"<<endl;
//     cout<<data1<<"\n"<<data2<<"\n"<<data3<<"\n"<<data4<<"\n";
//     return 0;
// }
class Person
{
private:
    string name;
    string address;
public:
    string get_name()const {return name;}
    string get_address()const {return address;}
    Person()=default;
    Person(const string &n,const string &a):name(n),address(a){}
    Person(istream &is){
        is>>this->name>>this->address;
    }
};


// class Sales_data{
// public:
//     Sales_data()=default;
//     Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
//     Sales_data(const std::string &s):bookNo(s){}
//     Sales_date(std::istream&);
//     std::isbn()const{return bookNo;}
//     Sales_data &combine(const Sales_data&);
// private:
//     double avg_price() const {
//         return units_sold?revenue/units_sold:0;
//     }
//     std::string bookNo;
//     unsigned units_sold=0;
//     double revenue=0.0;
// }



class Screen{
public:
typedef string::size_type pos;
//using pos=string::size_type;
private:
    string contents;
    pos cursor=0;
    pos width=0,height=0;
    mutable size_t access_ctr=0;
public:
    Screen()=default;
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}
    char get() const{ return contents[cursor];}
    char get(pos ht,pos wd)const;
    Screen &move(pos r,pos c);
    void some_member()const{
        ++access_ctr;
    }
};
inline 
Screen &Screen::move(pos r,pos c){
    pos row=r*width;
    cursor=row+c;
    return *this;
}
inline 
char Screen::get(pos r,pos c)const {
    pos row =width*r;
    return contents[row+c];
}

int main(){

}