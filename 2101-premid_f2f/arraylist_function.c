#include <stdio.h>
#include <stdlib.h>
#define MAX 3


typedef struct {
    int num[MAX];
    char str[MAX];
    int numcount;
    int strcount;
}arraylist;

void arraydisplay(arraylist L);
void insert(arraylist *L);


int main(){

    arraylist L; 
    insert(&L);
    arraydisplay(L);
    return 0;
}


void insert(arraylist *L){
    for(L->numcount = 0; L->numcount < MAX; L->numcount++){
        printf("Integer %d: ", L->numcount);
        scanf("%d", &L->num[L->numcount]);
    }

    for(L->strcount = 0; L->strcount < MAX; L->strcount++){
        printf("String %d: ", L->strcount);
        scanf(" %c", &L->str[L->strcount]);
    }

}

void arraydisplay(arraylist L){
    int x,y;
    for(x = 0; x < MAX; x++){
        printf("%d", L.num[x]);
    }

    for(y = 0; y < MAX; y++){
        printf("%c", L.str[y]);
    }
}

