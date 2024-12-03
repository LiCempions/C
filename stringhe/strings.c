#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int str_len(char *a){
    int c = 0;
    while (a[c] != 0){
        c++;
    }
    return c;
}

int str_cmp(char* a, char* b){
    /*
    a e b sono due stringhe
    ritorna f-1 se a precede b nell'ordinameto lessicografico:
    se i è la prima posizione in cui a e b divergono, a[i]<b[i]

    ritorna 1 se b precede a

    ritorna 0 se a e b sono uguali
    */

    int i = 0;
    int na = strlen(a), nb = strlen(b);

    while (i<na && i<nb && a[i]==b[i]){ // controlli dell'indice eseguiti prima
        i++;
    }   // i punta ai caratteri diversi

    if (i==na){         // i caratteri di a e b sono uguali per tutta la lunghezza di a
        if (i<nb){      // b è più lunga => a precede b
            return -1;
        } else {        // sono uguali 
            return 0;
        }
    }

    if (i==nb){         // i caratteri di a e b sono uguali per tutta la lunghezza di b
        return 1;       // abbiamo già controllato se a e b sono uguali, quindi b precede a
    }

    if (a[i]<b[i]){     // confronto del carattere diverso
        return -1;
    } else {
        return 1;
    }
}

int main(){
    char a[] = "una stringa";
    char b0[20];
    a[3] = '\0';
    strcpy(b0, a);
    
    printf("Senza indici: %s %s", a, b0);

    /*
    Scrivere una funzione con il seguente prototipo
    char* strclone(char* source)
    che copi source in una nuova stringa allocata dinamicamente
    e ne ritorni l'indirizzo o null se non è possibile

    Testare se a e b0 sono uguali come stringhe, non come array
    */
}