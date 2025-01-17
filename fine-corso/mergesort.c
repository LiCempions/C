#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#include"charswap.c"

void mergeSort(char* str, const int from, const int to){
    char* temp;
    int half, i, j, cursor=0;

    if ( to-from<=2 ){
        if(to-from==2 && str[to-1]<str[from])
            chrSwap(str, to-1, from);
        printf("Sorted %c and %c\n", str[from], str[to-1]);
        return;


    } else {
        half = (from+to)/2;
        printf("Sorting from %c to %c\n", str[from], str[to-1]);
        mergeSort(str, from, half);
        mergeSort(str, half, to);
        printf("Back up\n");

        i=from;
        j=half;
        temp = malloc( (to-from)*sizeof(char) +1 ); // WARNING: string terminator not included;

        while (i<half && j<to){
            if (str[i]<=str[j]){
                temp[cursor] = str[i];
                i++;
            } else {
                temp[cursor] = str[j];
                j++;
            }
            cursor++;
        }

        while(i<half){
            temp[cursor] = str[i];
            i++;
            cursor++;
        }
        while(j<to){
            temp[cursor] = str[j];
            j++;
            cursor++;
        }

        temp[cursor] = '\0';

        printf("Temporary sorted string: %s\n", temp);

        for (cursor=0; cursor<to-from; cursor++)
            str[from+cursor] = temp[cursor];

        free(temp);
    }
}

void mergeSortW(char* str){ // merge sort whole string
    mergeSort(str, 0, strlen(str));
}