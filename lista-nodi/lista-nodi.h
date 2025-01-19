
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
node* searchList(nodeList, float);
/* Get the address of a node by index */
/* Will return NULL if the index is out of range or the first node if the index is negative */
node* getNode(nodeList, int);
/* Get the last node of the list */
/* Will return NULL if the list is empty */
node* getLast(nodeList);


/* Add a node at the beginning of the list */
nodeList push(nodeList, float);
/* Add a node before the one pointed by "at" */
/* Will add the node at the end if "at" is NULL */
nodeList inject(nodeList, node*, float);
/* Add a node before the one containing "value" */
nodeList injectThe(nodeList L, float, float);
/* Add a node at an index */
nodeList injectAt(nodeList L, int, float);

/* Delete the first node */
nodeList chop(nodeList);
/* Delete a node by address */
nodeList dropNode(nodeList, node*);
/* Delete a node specified by value */
nodeList dropThe(nodeList, float);
/* Delete a node at an index */
nodeList dropAt(nodeList, int);

/* Print the value of each node to the standard output */
void printNList(nodeList);
