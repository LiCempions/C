#include"lista-nodi.c"

int main(){
    printf("Started\n");
    node* node;
    nodeList lista = initList();

    push(&lista, 1.2);
    push(&lista, 2.3);
    push(&lista, 3.4);
    push(&lista, 4.5);
    push(&lista, 5.6);
    push(&lista, 6.7);
    push(&lista, 7.8);
    inject(&lista, NULL, 0.1);
    injectAt(&lista, 0, 8.9);
    injectThe(&lista, 0.1, 0.5);

    printNList(&lista);
    printNListRvrs(&lista);

    chop(&lista);
    dropThe(&lista, 7.8);
    dropAt(&lista, 1);

    printNList(&lista);
    printNListRvrs(&lista);

    node = getNode(&lista, -1);
    if (node!=NULL)
        printf("%.2f\n", node->data);
    else
        printf("Node was NULL\n");
    printf("Terminato\n");
    return 0;
}