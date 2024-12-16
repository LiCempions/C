// Assumption: keys are strings
#include<stdlib.h>
#include<stdio.h>

typedef struct node {
    float data;
    node* next;
} node;
typedef node* nodeList;

nodeList initList();

nodeList push(nodeList);
node* searchList(nodeList, float);

void printNList(nodeList);

int main(){

}

nodeList initList(){
    node* node = malloc(sizeof(node));
    if (node == NULL)
        return NULL;

    (*node).data=0.0;
    node->next=NULL;
    return node;
}

nodeList push(nodeList list, float value){
    node* node = malloc(sizeof(node));
    node->data = value;
    node->next = list;

    return node;
}
node* searchList(nodeList L, float key){
    node* curr=L;
    while (curr!=NULL && curr->data!=key)
        curr = curr->next;
    
    return curr;
}

void printNList(nodeList L){
    node* curr = L; // L è l'indirizzo del primo nodo

    do {
        printf("Valore nodo: %f\n", curr->data);
        curr = curr->next;
    } while (curr!=NULL);
}
