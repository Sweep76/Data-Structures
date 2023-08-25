#include <stdio.h>
#include <stdlib.h>

#define SIZE 0XF

typedef struct {
    char FName[24];
    char MI;
    char LName[16];
}nameType;

typedef struct {
    nameType name;
    char gender;
}personType;

typedef struct{
    personType people[SIZE];
    int count;
}ArrayList;

typedef struct{
    personType person;
    struct node *next;
}detype, *LinkList;

void insert(LinkList* li, char element);
void display(LinkList li);

int main(){
    LinkList c = NULL;
    insert(&c, 'F');
    insert(&c, 'F');
    insert(&c, 'M');
    insert(&c, 'M');
    insert(&c, 'M');
    display(c);
}



void insert(LinkList* li, char element){
    LinkList temp = (LinkList)malloc(sizeof(detype));
    if(temp != NULL){
        temp->person.gender = element;
        temp->next = *li;
        *li = temp;
    }
}


void display(LinkList li){
    printf("{");
    while(li != NULL){
        printf(" %c", li->person.gender);
        if(li->next != NULL){
            printf(" -> ");
        }
        li = li->next;
    }
    printf("}\n");
}