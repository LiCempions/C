#include"dictNodeList.c"
#include"djb2.c"

/* Dict functions */

nodeList* getSubList(dict* d, const char* key){
    int hashed = h(key) % d->lArrSize;
    return d->listArray + hashed/* *sizeof(nodeList) */;
        // hashed is evaluated correctly, but d->listArray + hashed is not
        // C automatically does *sizeof(type), mortacci sua
}

/* Initialize dictionary */
dict initDict(){
    dict d;

    d.lArrSize = DICTHASHSIZE;
    d.listArray = malloc( DICTHASHSIZE*sizeof(nodeList) );

    for(int i=0; i<DICTHASHSIZE; i++)
        d.listArray[i]=NULL;
    
    return d;
}

/* Dictionary element assignment */
void dictSet(dict* d, const char* key, const int value){
    // printf("Trying to set value...\n" );
    nodeList* subList = getSubList(d, key);

    node* dItem = searchList(*subList, key);


    if (dItem!=NULL){
        // printf("\tUpdating value of %s\n", key);
        dItem->value = value;
    } else {
        // printf("\tNo match found, pushing to front\n");
        push(subList, key, value);
    }
}

/* Remove dictionary element */
void dictPop(dict* d, const char* key){
    nodeList* subList = getSubList(d, key);
    pop( subList, searchList(*subList, key) );
}

/* Get value from an element */
int dictGet(dict* d, const char* key){
    return searchList( *getSubList(d, key), key )->value;
}

/* Print the contents of a dictionary */
void printDict(dict* d){
    node* curr;
    for (int i=0; i<d->lArrSize; i++){
        printf("subList[%d]: ", i);
        printf("subList is %s", d->listArray[i]==NULL ? "empty\n" : "full\n" );
        for (curr=d->listArray[i]; curr!=NULL; curr = curr->next)
            printf("\tkey: %s, value: %d\n", curr->key, curr->value);
    }
    printf("\n");
}
