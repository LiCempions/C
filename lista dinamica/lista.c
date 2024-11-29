#include<stdio.h>
#include<stdlib.h>

struct lista_f {
    float* arr;
    int n;
    int c;
};
typedef struct lista_f lista_f;

lista_f append(lista_f, float);
lista_f init_list();

int main(){
    
}

lista_f init_list(){
    lista_f lista_vuota = {NULL, 0, 1};
    lista_vuota.arr = malloc( sizeof(float) );

    return lista_vuota;
}

lista_f append(lista_f L, float e){
    if (L.c == L.n){
        L.c = 2*L.c;
        L.arr = realloc(L.arr, L.c);
    }
    L.arr[L.n] = e;
    L.n++;

    return L;
}