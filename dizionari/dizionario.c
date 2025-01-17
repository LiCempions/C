#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashSum.c"
#define DICTMSIZE 7

/* ----- types ----- */

typedef struct ditem {
    char* k;
    int v;
} ditem;

typedef struct node {
    ditem data;
    struct node* next;
    struct node* prev;
} node;

typedef node* nodeList;

typedef struct dict {
    nodeList* outerList;
    /* outerList è una lista, quindi un puntatore al primo elemento => firstElement* outerList
    Ogni elemento è un puntatore al primo nodo => node* = nodeList
    Risultato: nodeList* outerList */
    int m;
} dict;

/* ----- methods ----- */

node* searchList(nodeList L, char* key){
    node* curr=L;
    while (curr!=NULL && strcmp(curr->data.k, key)!=0)
        curr = curr->next;
    
    return curr;
}
nodeList push(nodeList list, ditem* value){
    node* node = malloc(sizeof(node));
    node->data = *value;
    node->next = list;
    node->prev = NULL;
    if (list != NULL)
        list->prev = node;

    return node;
}

dict initDict();
dict dictAddItem(dict, const char*, int);

void printDict(dict);

int main(){
    dict diz = initDict();
    // printDict(diz);

    diz = dictAddItem(diz, "chiave0", 0);
    printDict(diz);
    diz = dictAddItem(diz, "chiave1", 1);
    // printDict(diz);
    diz = dictAddItem(diz, "chiave2", 2);
    // printDict(diz);
    diz = dictAddItem(diz, "chiave3", 3);
    diz = dictAddItem(diz, "chiave4", 4);

    printDict(diz);
}


/* ----- Definitions ----- */

void printNList(nodeList L){
    node* curr = L; // L è l'indirizzo del primo nodo

    while (curr!=NULL){
        printf("k: %s, \t v: %d\t", curr->data.k, curr->data.v);
        curr = curr->next;
    };

    printf("\n");
}


dict dictAddItem(dict d, const char* key, const int value){
    printf("hashing...\n");
    int i = h(key)%d.m;
    printf("hashed: %d\n", i);
    node* p = searchList(d.outerList[i], key);
    ditem itm = {NULL, value};
    printf("Individuato: ");
    printf( (p==NULL) ? "NULL\n": "non-NULL\n" );

    if (p!=NULL){ // se key è una chiave già esistente, aggiorno il valore
        printf("Key existed, updating value\n");
        p->data.v = value;
    } else {
        printf("Creating ditem\n");
        // ditem itm = {NULL, value};
        printf("Allocating %zd bytes\n", (strlen(key)+1)*sizeof(char));
        itm.k = malloc( (strlen(key)+1)*sizeof(char) ); // strlen non include '\0'
        printf( (itm.k==NULL) ? "malloc returned NULL\n": "malloc returned non-NULL\n" );
        printf("Copying string\n");
        strcpy(itm.k, key);
        printf("Copied %s\n", itm.k);
        printf("Pushing new node\n");
        d.outerList[i] = push(d.outerList[i], &itm);
        printf("Returning\n\n");
    }

    return d;
}

dict initDict(){
    // dict d = {NULL, DICTMSIZE};
    dict d;
    int i;

    d.m = DICTMSIZE;
    d.outerList = malloc(d.m * sizeof(nodeList));

    for (i=0; i<d.m; i++){
        d.outerList[i] = NULL;
    }

    return d;
}

void printDict(dict d){
    int i;

    for (i=0; i<d.m; i++){
        printf("outerList[%d]: \t", i);
        printNList(d.outerList[i]);
    }
}
