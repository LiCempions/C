#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a>b){
        c=a;
        b=a;
        b=c;
    }
    printf("%d", b);

    return 0;
}