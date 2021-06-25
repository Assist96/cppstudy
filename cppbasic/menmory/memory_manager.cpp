#include<cstdlib>
#include<cmath>
#include<complex>
#include<ext/pool_allocator.h>
using namespace std;
int main(){
    void *p1=malloc(512);
    free(p1);
    complex<int>* p2=new complex<int>;
    delete p2;
    void *p3=::operator new(512);
    ::operator delete(p3);
    #ifdef _MSC_VER
     int* p4=allocator<int>().allocate(3,(int*)0);
     allocator<int>.deallocate(p4);
    #endif
    #ifdef __BORLANDC__
     int* p4=allocator<int>().allocate(3);
     allocator<int>.deallocate(p4);
    #endif
    #ifdef __GNUC__
     void* p4=allocator<int>().allocate(3);
     allocator<int>().deallocate((int*)p4,3);
        void *p5=__gnu_cxx::__pool_alloc<int>().allocate(5);
        __gnu_cxx::__pool_alloc<int>().deallocate((int*)p5,5);
    #endif
}