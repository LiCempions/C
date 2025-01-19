#include<stdlib.h>
#include<stdio.h>
#include"lista-nodi.h"

nodeList initList(){
    return NULL;
}

node* searchList(nodeList L, float key){
    node* curr=L;
    while (curr!=NULL && curr->data!=key)
        curr = curr->next;
    
    return curr;
}
node* getNode(nodeList L, int index){
    int i;
    node* curr;

    for (i=0, curr=L; curr!=NULL && i<index; i++, curr=curr->next){}

    return curr;
}
node* getLast(nodeList L){
    if (L==NULL)
        return L;
    
    while (L->next!=NULL)
        L = L->next;
    
    return L;
}

nodeList push(nodeList list, float value){
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = list;
    newNode->prev = NULL;
    if (list != NULL)
        list->prev = newNode;

    return newNode;
    // Insert node after, copy first to second and override first: many more pointer overrides
}
nodeList inject(nodeList L, node* at, float value){
    node* prevNode = (at==NULL) ? getLast(L) : at->prev;
    node* newNode = push(at, value);
    newNode->prev = prevNode; // push is meant to insert at pos 0, so it set newNode->prev to NULL
    if (prevNode==NULL){
        return newNode; // if "at" was the first node, return newNode as the nodeList
    } else {
        prevNode->next = newNode;   // the previous node still points to "at"
        return L;                   // the address of the first node did not change
    }
}
nodeList injectThe(nodeList L, float key, float value){
    node* at = searchList(L, key);
    return inject(L, at, value);
}
nodeList injectAt(nodeList L, int index, float value){
    node* at = getNode(L, index);
    return inject(L, at, value);
}

nodeList chop(nodeList L){
    if (L==NULL)
        return NULL;

    node* firstNode = L;
    nodeList choppedL = firstNode->next;
    if (choppedL!=NULL)
        choppedL->prev = NULL;
    free(firstNode);

    return choppedL;
}
nodeList dropNode(nodeList L, node* node){
    if (node == NULL)
        return L;
    
    if (node->prev!=NULL)
        node->prev = chop(node);
    else
        node = chop(node);
    
    return (node->prev==NULL) ? node : L;
}
nodeList dropThe(nodeList L, float key){
    node* node = searchList(L, key);
    return dropNode(L, node);
}
nodeList dropAt(nodeList L, int index){
    node* node = getNode(L, index);
    return dropNode(L, node);
}

void printNList(nodeList L){
    node* curr = L; // L è l'indirizzo del primo nodo

    printf("\n==============\nValori lista a nodi:\t");
    while (curr!=NULL) {
        printf(" %.2f -o-", curr->data);
        curr = curr->next;
    }
    printf("_\n");
}
