#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct{
    char data[100];
    int count;
}ArrayList;

void insert(ArrayList *L, char str);
void show(ArrayList *L);
void update(ArrayList* A, char oldElement, char newElement);

//methods here
ArrayList init(){
    ArrayList A;
    A.count = 0;

    return A;
}

void insert(ArrayList *A, char str){
    int i, j;
    if (A->count >= MAX) {
        printf("ArrayList is full.\n");
        return;
    }
   
    A->data[A->count++] = str;

    for (i = 0; i < A->count; i++) {
        for (j = i+1; j < A->count; j++) {
            if (A->data[i] > A->data[j]) {
                char temp = A->data[i];
                A->data[i] = A->data[j];
                A->data[j] = temp;
            }
        }
    }
}

void delete(ArrayList *A, char element){
    int i, j;
    for(i=0;A->count;i++){
        if(A->data[i] == element) {
            for(j=i+1;j<A->count; j++){
                A->data[j-1] = A->data[j];
            }
            A->count--;
            printf("%c has been deleted from records\n", element);
            return;
        }
    }
    printf("%c is not found\n", element);
}

void update(ArrayList* A, char oldElement, char newElement) {
    int i, j;
    for (i = 0; i < A->count; i++) {
        if (A->data[i] == oldElement) {
            A->data[i] = newElement;
            for (j = 0; j < A->count; j++) {
                if (A->data[i] < A->data[j]) {
                    char temp = A->data[i];
                    A->data[i] = A->data[j];
                    A->data[j] = temp;
                }
            }
            printf("%c has been updated to %c.\n", oldElement, newElement);
            return;
        }
    }
}


void show(ArrayList *L){
    int x;
    printf("\t--------------------\n");
    printf("\tARRAY LIST DISPLAY\n");
    printf("\tIndex\tletter\n");
    printf("\t--------------------\n");
    for(x=0;x<L->count;x++){
        printf("\t%d\t%c\n", x,  L->data[x]);
    }
    printf("\tcount: %d\n\n", L->count);
   
}

int main(){
    ArrayList L = init();

    insert(&L, 'R');
    insert(&L, 'A');
    insert(&L, 'D');
    show(&L);
    insert(&L, 'F');
    insert(&L, 'T');
    insert(&L, 'P');
    show(&L);
    
    delete(&L, 'D');
    show(&L);

    update(&L, 'R', 'B');
    show(&L);
    return 0;
}