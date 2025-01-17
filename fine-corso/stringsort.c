#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// #include"charswap.c"
#include"mergesort.c"

void sortString(char*);
int isVowel(char);

int main(){
    const char* string = "a quick, sly and brown fox JUMPS over the lazy, quiet dog!";
    // const char* string = "IHDAJIDHfhiddHF ORHOAi hfIFIFIRPUITO4825UR98!a$&/())";
    char* sorted;
    sorted = malloc(30*sizeof(char));
    strcpy(sorted, string);
    sortString(sorted);

    printf("Original: %s\nSorted: %s\n", string, sorted);
}


int isVowel(char c){
    if (c<65 || c>122) // c is not a letter
        return 0;

    c = c|0b00100000; // to lowercase

    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

void sortString(char* toSort){
    int vowelsFound=0, sortLen;

    sortLen = strlen(toSort);

    for (int i=0; i<sortLen; i++){
        if ( isVowel(toSort[i]) ){
            chrSwap(toSort, i, vowelsFound);
            vowelsFound++;
        }
    }

    mergeSort(toSort, 0, vowelsFound);
    mergeSort(toSort, vowelsFound, sortLen);
}