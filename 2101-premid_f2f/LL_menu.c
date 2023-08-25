#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node{
	char data[MAX];
	struct node *link;
}*LIST;

void init(LIST *L);
void display(LIST L);
void delete(LIST *L, char *str);
void update(LIST *L, char *oldstr, char *newstr);
void insertSorted(LIST *L, char *str);

void init(LIST *L){
	*L = NULL;
}

void insertSorted(LIST *L, char *str){
	LIST *trav, temp;
	for(trav = L; (*trav)!= NULL && (strcmp((*trav)->data, str) < 0); trav = &(*trav)->link);
	temp = malloc(sizeof(struct node));
        if (temp != NULL){
            strcpy(temp->data, str);
            temp->link = (*trav);
            *trav = temp;
        }else{
            printf("\nFAILED TO ALLOCATE MEMORY\n");
        }
}

void display(LIST L){
	LIST trav;
    printf("\nLINKED LIST DISPLAY\n");
	for (trav = L; trav!=NULL; trav = trav->link){
		printf("|%s| -> ", trav->data);
	}
    printf("NULL\n");
    printf("-------------------------\n");
}

void delete(LIST *L, char *str){
	LIST *trav;
	LIST temp;
	for(trav = L; (*trav)!= NULL && (strcmp((*trav)->data,str)!=0); trav = &(*trav)->link){}
        if (*trav!=NULL){
            temp = *(trav);
            *trav = (*trav)->link;
            free(temp);
        }else{
            printf("\nNOT FOUND!\n");
        }
}
void update(LIST *L, char *oldstr, char *newstr){
	LIST *trav;
	LIST temp;
	for(trav = L; (*trav)!= NULL && (strcmp((*trav)->data,oldstr)!=0); trav = &(*trav)->link){}
        if (*trav!=NULL){
            strcpy((*trav)->data, newstr);
        }else{
            printf("\nNOT FOUND!\n");
        }
}

void main(){
	LIST L;
	init(&L);
	insertSorted(&L, "Joshua");
	insertSorted(&L, "James");
	insertSorted(&L, "Caitlin");
	insertSorted(&L, "Kyne");
	insertSorted(&L, "Teresa");
	insertSorted(&L, "Hannah");
	insertSorted(&L, "Bessa");
	insertSorted(&L, "Miguel");
	display(L);
	delete(&L, "Teresa");
	display(L);
	update(&L, "Joshua", "Joshua Chiu");
	display(L);
}