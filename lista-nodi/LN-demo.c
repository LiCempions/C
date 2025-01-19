#include"lista-nodi.c"

int main(){
    printf("Started\n");
    node* node;
    nodeList lista = initList();

    lista = push(lista, 1.2);
    lista = push(lista, 2.3);
    lista = push(lista, 3.4);
    lista = push(lista, 4.5);
    lista = push(lista, 5.6);
    lista = push(lista, 6.7);
    lista = push(lista, 7.8);

    printNList(lista);
    node = getNode(lista, 30);
    if (node!=NULL)
        printf("%.2f\n", node->data);
    printf("Terminato\n");
    return 0;
}