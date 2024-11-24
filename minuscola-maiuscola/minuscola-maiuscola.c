#include<stdio.h>
#define CAPS_DIST 32

char maiuscolaMinuscola(char c){
    if (c>='A' && c<='Z'){
        return c+CAPS_DIST;
    } else
        return c;
}

int main(){
    char ch = 'A';

    printf("I caratteri sono: %c, %c e le posizioni sono %d, %d\n", ch, maiuscolaMinuscola(ch), ch, maiuscolaMinuscola(ch));
    printf("Hihihihi sono simp %c", maiuscolaMinuscola('!'));
}