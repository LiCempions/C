#include"ptrDict.c"

int main(){
    dict diz = initDict();
    char* testElement = "Questa stringa e' nel dizionario";

    dictSet(&diz, "chiave0", testElement);
    dictSet(&diz, "chiave1", testElement);

    printDict(&diz);

    dictPop(&diz, "chiave0", 0);

    printDict(&diz);

    printf("Stringa contenuta in chiave1:\n\t%s\n", (char*)dictGet(&diz, "chiave1"));

    return 0;
}