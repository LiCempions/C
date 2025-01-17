int h(char* key){ // the address is copied in function calls
    int h=0;

    while (*key != '\0'){
        h = h + *key;
        key = key + sizeof(char);
    }

    return h;
}