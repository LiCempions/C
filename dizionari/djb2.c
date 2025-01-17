int h(char* key){
    int h = 5831;

    while (*key != '\0'){
        // h = 33*h + *key;
        // h = 32*h + h + *key; Con questo formato potremmo utilizzare il formato seguente
        h = (h<<5) + h + *key;
        // più veloce della normale moltiplicazione
        // in decimale: h<<5 è h * 2^5
        key = key + sizeof(char);
    }

    return h;
}