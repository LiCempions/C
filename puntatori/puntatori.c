#include<stdio.h>

int main(){
    float* p;
    float f = 3.14;

    p = &f;

    printf("%f, %f", f, *p);
    return 0;
}