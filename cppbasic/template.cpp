template<typename T>
class complex{
public:
    complex(T r=0,T i=0)
    :re(r),im(i){}
private:
    T re;
    T im;
};
// int main(){
//     complex<double>c1(0.5,2.7);
// }


//function type
template <class T>
inline 
const T& min(const T&a,const T& b){
    return  b<a?b:a;
}
class stone{
public:
    stone();
    stone(int w,int h,int we)
    :_w(w),_h(h),_weight(we){}
    bool operator<(const stone& st) const{
        return _weight<st._weight;
    }
private:
    int _w,_h,_weight;
};
int main(){
    stone r1(2,3,4),r2(1,2,3),r3;
    r3=min(r1,r2);//不需要声明类型  
}
 