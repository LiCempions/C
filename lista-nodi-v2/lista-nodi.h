
/* ----- types ----- */

/* A node */
typedef struct node {
    float data;
    struct node* next;
    struct node* prev;
} node;

/* The first node in a list */
typedef node* nodeList;

/* ----- methods ----- */

/* Initialize the node list (useless) */
nodeList initList();

/* Get the address of the first node containing "key" */
/* Will return NULL if no node contains "key" */
node* searchList(nodeList*, float);
/* Get the address of a node by index */
/* Will return NULL if the index is out of range or the first node if the index is negative */
node* getNode(nodeList*, int);
/* Get the address of the last node */
/* Will return NULL if the list is empty */
node* getLast(nodeList*);

/* Add a node at the beginning of the list */
void push(nodeList*, float);
/* Add a node before the one pointed by "at" */
/* Problem: can't inject in the last position */
void inject(nodeList*, node*, float);
/* Add a node before the one containing "value" */
void injectThe(nodeList*, float, float);
/* Add a node at an index */
void injectAt(nodeList*, int, float);

/* Delete the first node */
void chop(nodeList*);
/* Delete a node by address */
void dropNode(nodeList*, node*);
/* Delete a node specified by value */
void dropThe(nodeList*, float);
/* Delete a node at an index */
void dropAt(nodeList*, int);

/* Print the value of each node to the standard output */
void printNList(nodeList*);
/* Print the value of each node to the standard output in reverse order */
void printNListRvrs(nodeList*);
