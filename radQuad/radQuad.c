#include<stdio.h>

float absCustom(float);

float sqrt(float, int);

float absCustom(float x) {
    if(x<0)
        return -x;
    else
        return x;
}

float sqrt(float x, const int max_iter) {
    float g = x/2;
    int iter = 0;

    while ( absCustom( g*g-x ) > 0.00001 && iter < max_iter ) {
        g = ( g + x/g )/2;
        iter ++;
    }

    return g;
}

int main(){
    float x;

    printf("Started!\n");
    printf("Radice quadrata di ", sqrt(x, 5));
    scanf("%f", &x);
    printf("Radice di %f = %f", x, sqrt(x, 5));
}