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
    lista = inject(lista, NULL, 0.1);
    lista = injectAt(lista, 0, 8.9);
    lista = injectThe(lista, 0.1, 0.5);

    printNList(lista);

    lista = chop(lista);
    lista = dropThe(lista, 7.8);
    lista = dropAt(lista, 1);

    printNList(lista);

    node = getNode(lista, -1);
    if (node!=NULL)
        printf("%.2f\n", node->data);
    else
        printf("Node was NULL\n");
    printf("Terminato\n");
    return 0;
}