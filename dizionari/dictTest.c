#include"dizionariov2.c"

int main(){
    dict diz = initDict();

    dictSet(&diz, "chiave0", 0);
    dictSet(&diz, "chiave1", 1);
    dictSet(&diz, "chiave2", 2);
    dictSet(&diz, "chiave3", 3);
    dictSet(&diz, "chiave4", 4);
    dictSet(&diz, "chiave4", 7);

    printDict(&diz);

    dictPop(&diz, "chiave2");
    dictPop(&diz, "chiave3");
    dictPop(&diz, "chiave0");

    printDict(&diz);

    return 0;
}