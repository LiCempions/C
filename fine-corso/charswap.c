void chrSwap(char*str, int a, int b){
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}