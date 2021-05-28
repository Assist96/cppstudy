#include"Chapter6.h"
int fact(int n){
    if (n<0){
        return -1;
    }
    int res=1;
    while (n>=1)
    {
        res=res*n;
        --n;
    }
    return res;
}