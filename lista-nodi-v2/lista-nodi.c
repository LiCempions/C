#include<stdlib.h>
#include<stdio.h>
#include"lista-nodi.h"

nodeList initList(){
    return NULL;
}

node* searchList(nodeList* L, float key){
    node* curr=*L;
    while (curr!=NULL && curr->data!=key)
        curr = curr->next;
    
    return curr;
}
node* getNode(nodeList* L, int index){
    int i;
    node* curr;

    for (i=0, curr=*L; curr!=NULL && i<index; i++, curr=curr->next){}

    return curr;
}
node* getLast(nodeList* L){
    node* curr = *L;
    if (curr==NULL)
        return curr;
    
    while (curr->next!=NULL)
        curr = curr->next;
    
    return curr;
}

void push(nodeList* list, float value){
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = *list;
    newNode->prev = NULL;
    if (*list != NULL)
        (*list)->prev = newNode;

    *list = newNode;
    // Insert node after, copy first to second and override first: many more pointer overrides
}
void inject(nodeList* L, node* at, float value){
    node* prevNode = (at==NULL) ? getLast(L) : at->prev;
    node* newNode = at; // not really needed but it's more understanable
    push(&newNode, value);
    newNode->prev = prevNode; // push is meant to insert at pos 0, so it set newNode->prev to NULL
    
    if (prevNode==NULL)
        *L = newNode; // if "at" was the first node, return newNode as the nodeList
    else
        prevNode->next = newNode;   // the previous node still points to "at"
}
void injectThe(nodeList* L, float key, float value){
    node* at = searchList(L, key);
    inject(L, at, value);
}
void injectAt(nodeList* L, int index, float value){
    node* at = getNode(L, index);
    inject(L, at, value);
}

void chop(nodeList* L){
    if (*L==NULL)
        return;

    node* firstNode = *L;
    nodeList choppedL = firstNode->next;
    if (choppedL!=NULL)
        choppedL->prev = NULL;
    free(firstNode);

    *L = choppedL;
}
void dropNode(nodeList* L, node* drop){
    if (drop == NULL)
        return;
    
    node* nextNode = drop->next;
    node* prevNode = drop->prev;
    
    if (prevNode == NULL){
        chop(L);
        return;
    } // else

    chop( &(prevNode->next) );
    nextNode->prev = prevNode;
        // No need if drop is the first node (nextNode->prev is NULL):
        // chop already set nextNode->prev to NULL
}
void dropThe(nodeList* L, float key){
    node* node = searchList(L, key);
    dropNode(L, node);
}
void dropAt(nodeList* L, int index){
    node* node = getNode(L, index);
    dropNode(L, node);
}

void printNList(nodeList* L){
    node* curr = *L; // L è l'indirizzo del primo nodo

    printf("\n==============\nValori lista a nodi:\n\t");
    while (curr!=NULL) {
        printf(" %.2f -o-", curr->data);
        curr = curr->next;
    }
    printf("_\n");
}

void printNListRvrs(nodeList* L){
    node* curr = getLast(L); // L è l'indirizzo del primo nodo

    printf("\n==============\nValori lista a nodi (rovesciata):\n\t");
    while (curr!=NULL) {
        printf(" %.2f -o-", curr->data);
        curr = curr->prev;
    }
    printf("_\n");
}
