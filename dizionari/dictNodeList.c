#include"commonDictDefs.h"

/* Auxiliary dictionary function */
node* searchList(nodeList l, const char* key){
    while (l!=NULL && strcmp(l->key, key)!=0)
        l = l->next;
    
    return l;
}

/* Auxiliary dictionary function */
void push(nodeList* l, const char* key, const int value){
    node* newNode = malloc(sizeof(node));

    newNode->next = *l;
    newNode->prev = NULL;
    newNode->key = malloc( (strlen(key)+1)*CHARSIZE );
    strcpy(newNode->key, key);
    newNode->value = value;

    if (*l!=NULL)
        (*l)->prev = newNode;

    *l = newNode;
}

/* Auxiliary dictionary function */
void pop(nodeList* l, node* popNode){
    if (popNode==NULL)
        return;
    
    if (popNode->next != NULL)
        popNode->next->prev = popNode->prev;
    
    if (popNode->prev != NULL)
        popNode->prev->next = popNode->next;
    else
        *l = popNode->next;
    

    free(popNode->key);
    free(popNode);
    
}
