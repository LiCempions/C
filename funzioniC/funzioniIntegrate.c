#include <stdio.h>

int main(){
    int a = 3, b = 2;
    float c = a/b; // c = 1.0
    float d = (1.0f * a)/b; // d = 1.5: a*1.0 diventa float
    float e = (float) a/b;

    printf("c = %f\nd = %f\ne = %f");
}