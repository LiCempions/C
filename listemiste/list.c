#include<stdio.h>
#include<stdlib.h>

/* typedefs lista */

typedef struct {
    char type; // 'd' intero, 'f' float, 'c' char, 's' stringa
    void* addr;
} element;

typedef struct {
    element* arr;
    int n; // dimensione
    int c; // capacità
} dyn_list;

/* decl funzioni lista */

dyn_list init_list();
dyn_list append(dyn_list, element);
dyn_list insert(dyn_list, element, int);
dyn_list pop(dyn_list);
dyn_list dropExNovo(dyn_list, int);
dyn_list drop(dyn_list L, int index);

/* decl creazione elementi */

element intElement(int);
element floatElement(float);
element charElement(char);
element stringElement(char*);
void printList(dyn_list);

/* decl input */

char parseBuffer(char*);

/* main */

int main(){
    char buffer[1024], bufferT;
    char* format = "% ";
    int i, success = 0, elementNum;
    dyn_list mixList;

    int intInp;
    float floatInp;
    char* strInp;
    element toAppend;

    mixList = init_list();

    printf("Digita il numero di elementi da aggiungere alla lista: ");
    while (success!=1){
        success = scanf("5d", &elementNum);
        if (success==0)
            printf("Impossibile leggere il numero, riprova: ");
    }

    printf("Inserisci qualunque cosa: ");
    scanf("%s", &buffer);

    for (i=0; i<elementNum; i++){
        bufferT = parseBuffer(buffer);  // per individuare il tipo di input esaminiamo il buffer
        format[1] = bufferT;
        
        switch (bufferT){
        case 'd':
            sscanf(buffer, format, &intInp);
            toAppend = intElement(intInp);
            break;

        case 'f':
            sscanf(buffer, format, &floatInp);
            toAppend = floatElement(floatInp);
            break;
        
        case 's':
            toAppend = stringElement(buffer);
            break;
        
        default:
            printf("Tipologia input non riconosciuta, terminazione programma...\n");
            return -1;
        }

        mixList = append(mixList, toAppend);

        printf("Inserisci il prossimo valore: ");
        scanf("%s", &buffer);
    }

    printList(mixList);

    return 0;
}

/* test funzioni lista */

int main1(){
    dyn_list lista = init_list();
    lista = append(lista, intElement(10));
    // intElement crea un elemento (gianni) che punta a 10 e passa questo elemento a append
    // append copia i campi di gianni nell'array di elementi e ritorna
    // gianni (variabile locale di append) viene cancellato, ma l'indirizzo di 10 si trova ora nell'array
    lista = append(lista, floatElement(3.14));
    lista = append(lista, floatElement(1.414));
    lista = append(lista, floatElement(9.81));
    lista = append(lista, intElement(64));
    lista = append(lista, charElement('e'));
    lista = append(lista, stringElement("I sassi grassi"));
    lista = append(lista, stringElement("I sassi enormi"));
    lista = append(lista, stringElement("I sassi giganti"));
    lista = append(lista, stringElement("I sassi cosmici"));
    lista = append(lista, stringElement("I sassi cosmetici"));
    printList(lista);

    while (lista.n > 5)
        lista = pop(lista);
    
    printList(lista);

    lista = drop(lista, 1);
    printList(lista);

    return 0;
}

/* creazione elementi */

element intElement(int number){
    element e = {'d', NULL};
    e.addr = malloc(sizeof(int));
    *((int*)e.addr) = number;

    return e;
}

element floatElement(float number){
    element e = {'f', NULL};
    e.addr = malloc(sizeof(float));
    *((float*)e.addr) = number;

    return e;
}

element charElement(char chr){
    element e = {'c', NULL};
    e.addr = malloc(sizeof(char));
    *((char*)e.addr) = chr;

    return e;
}

element stringElement(char* string){
    element e = {'s', NULL};
    e.addr = string;

    return e;
}

/* funzioni lista */

dyn_list init_list(){
    dyn_list lista_vuota = {NULL, 0, 1};
    lista_vuota.arr = malloc( sizeof(element) );

    return lista_vuota;
}


dyn_list append(dyn_list L, element e){
    if (L.c == L.n){    // se la dimensione sta per superare la capacità, alloca più memoria
        L.c = 2*L.c;
        L.arr = realloc(L.arr, L.c * sizeof(element));
    }
    L.arr[L.n] = e;     // assegna l'elemento e incrementa la dimensione
    L.n++;

    return L;
}

dyn_list insert(dyn_list L, element e, int index){
    L = append(L, e);

    for (int i = L.n-1; i>index && i>0; i--){   // && i>0: se index<0 l'elemento viene messo in testa all'array
        L.arr[i] = L.arr[i-1];
        L.arr[i-1] = e;         // In questo modo non abbiamo bisogno di aggiungere un altro if
    }

    /*
    questo non serve

    if ( index<L.n && index>=0 ){
        L.arr[index] = e
    }
    */

   return L;
}


dyn_list pop(dyn_list L){
    if ( L.n>0 ){       // se l'array contiene elementi
        if (L.arr[L.n-1].type != 's')
            free(L.arr[L.n-1].addr);
            // eseguiamo il free solo su non-stringhe, in quanto
            // risiedono in uno spazio non assegnato da noi
        L.n--;

        if (L.n <= L.c/4){
            L.c = L.c/2;
            L.arr = realloc(L.arr, L.c * sizeof(element));
        }
        // lasciamo sempre una capacità almeno doppia alla dimensione
    }
    return L;
}

dyn_list dropExNovo(dyn_list L, int index){
    if ( index>=0 && index<L.n){        // se l'indice fornito è legale
        if (L.arr[index].type != 's')   // se non è tipo stringa, libera la memoria
            free(L.arr[index].addr);
        
        while (index < L.n - 1){        // scala di 1 indietro gli elementi prima dell'ultimo
            L.arr[index] = L.arr[index+1];
            index++;
        }

        L.n--;                          // diminuisci la dimensione
        if (L.n <= L.c/4){              // dealloca memeoria se la dimensione è molto ridotta
            L.c = L.c/2;
            L.arr = realloc(L.arr, L.c * sizeof(element));
        }
    }
    return L;
}

dyn_list drop(dyn_list L, int index){
    int i;
    element tmp = L.arr[index];

    for ( i=index; i<L.n-2; i++ ){
        L.arr[i] = L.arr[i+1];
    }
    L.arr[L.n-1] = tmp;
    L = pop(L);

    return L;
}


void appendByPointer(dyn_list* L, element e){
    if ((*L).c == (*L).n){
        (*L).c = 2*(*L).c;
        (*L).arr = realloc((*L).arr, (*L).c);
    }
    (*L).arr[(*L).n] = e;
    (*L).n++;
}


void printList(dyn_list L){
    printf("\n===================\n");
    printf("\nElementi: %d, capacita': %d\n", L.n, L.c);
    for (int i = 0; i < L.n; i++){
        printf("-----\nRilevato '%c' in posizione %d\n", L.arr[i].type, i);

        switch (L.arr[i].type){
        case 'd':
            printf("%d\n", *((int*)L.arr[i].addr));
            // con (int*) forniamo all'operatore * il tipo di dato
            // (segnato void nella struct)
            break;

        case 'f':
            printf("%f\n", *((float*)L.arr[i].addr));
            break;

        case 'c':
            printf("%c\n", *((char*)L.arr[i].addr));
            break;

        case 's':
            printf("%s\n", (char*)L.arr[i].addr);
            // in questo caso addr contiene l'indirizzo alla stringa, ciò che è richiesto
            break;
        
        default:
            printf("Tipo di dato sconosciuto\n");
            break;
        }
    }
    printf("===================\n\n");
}


/* ----- input ----- */

char parseBuffer(char* string){
    int i;
    int foundOneDot = 0;

    for (i=0; string[i] != '\0'; i++){
        if ( string[i]=='.' ){
            if (foundOneDot) // 0 viene interpretato come false, ogni altro valore come true
                return 's';
            else
                foundOneDot = 1;

        } else {
            if ( (string[i]<'0' || string[i]>'9') && !(string[i]=='-' && i==0) )
                return 's';
        }
    }
    if (string[0] == '\0')
        return 's';

    return (foundOneDot) ? 'f' : 'd';
}