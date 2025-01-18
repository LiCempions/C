#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define DICTHASHSIZE 7
#define CHARSIZE sizeof(char)

/* Each element of the dictionary */
typedef struct node {
    char* key;
    void* value;
    struct node* next;
    struct node* prev;
} node;

/* Pointer to the first element */
typedef node* nodeList;

/* Dictionary struct */
typedef struct dict{
    nodeList* listArray;
    int lArrSize;
} dict;
