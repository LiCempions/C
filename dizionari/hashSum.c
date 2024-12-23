int h(char* key){
    int h=0;

    while (*key != '\0'){
        h = h + *key;
        key = key + sizeof(char);
    }

    return h;
}