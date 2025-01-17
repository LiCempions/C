int h(const char* key){
    int h = 5831, i=0;

    while (key[i] != '\0'){
        // h = 33*h + *key;
        // h = 32*h + h + *key; Con questo formato potremmo utilizzare il formato seguente
        h = (h<<5) + h + key[i];
        // più veloce della normale moltiplicazione
        // in decimale: h<<5 è h * 2^5
        i++;
    }

    return h;
}