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


int main(){

    arraylist L;
    for(L.numcount = 0; L.numcount < MAX; L.numcount++){
        printf("Integer %d: ", L.numcount);
        scanf("%d", &L.num[L.numcount]);
    }

    for(L.strcount = 0; L.strcount < MAX; L.strcount++){
        printf("String %d: ", L.strcount);
        scanf(" %c", &L.str[L.strcount]);
    }

    arraydisplay(L);
    return 0;
}

void arraydisplay(arraylist L){
    for(L.numcount = 0; L.numcount < MAX; L.numcount++){
        printf("%d", L.num[L.numcount]);
    }

    for(L.strcount = 0; L.strcount < MAX; L.strcount++){
        printf("%c", L.str[L.strcount]);
    }
}

