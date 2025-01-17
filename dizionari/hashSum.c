int h(char* key){
    int h=0, i=0;

    while (key[i] != '\0'){
        h = h + key[i];
        i++;
    }

    return h;
}