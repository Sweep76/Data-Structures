#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct studtype{
	char Name[24], MI, Lname[16];
	unsigned int ID;
	char course[8];
	int yearLevel;
}studType;

typedef struct node{
	studType stud;
	struct node *link;
}*LinkedList;

typedef struct {
	studType stud[MAX];
	int count;
}ArrayList;

void displayArr(ArrayList arr);
void transferList(ArrayList *arr, LinkedList *L, char course[]);
void insertArr(ArrayList *arr, char Name[], char mi, char Lname[], int id, char course[], int year);
void displayLL(LinkedList L);
void main(){
    ArrayList arr ;
    LinkedList L;
    L = NULL;
    arr.count = 0;
    insertArr(&arr, "Angelou",'B',"Sereno",1000,"BSCS",2);
    insertArr(&arr, "Zane Joseph", 'O', "Bendebel", 1001, "BSIT", 1);
    insertArr(&arr, "Chinkee Venice", 'B', "Bayno", 1002, "BSIS", 3);
    insertArr(&arr, "Jamaica Pearl", 'O', "Bendebel", 1001, "BSIT", 1);
   transferList(&arr, &L, "BSIT");
   displayLL(L);
}



void displayArr(ArrayList arr){
    int x;
    printf("Linked List: \n");
    for (x = 0; x < MAX; x++){
        printf("------------------------\n");
        printf("Name: %s %c. %s\n", arr.stud[x].Name, arr.stud[x].MI, arr.stud[x].Lname);
        printf("ID: %d\nCourse: %s - %d\n", arr.stud[x].ID, arr.stud[x].course, arr.stud[x].yearLevel);
        printf("------------------------\n\n");
    }
}

void insertArr(ArrayList *arr, char Name[], char mi, char Lname[], int id, char course[], int year){
    int x = arr->count;
    strcpy(arr->stud[x].Name, Name);
    strcpy(arr->stud[x].Lname, Lname);
    arr->stud[x].MI = mi;
    strcpy(arr->stud[x].course, course);
    arr->stud[x].yearLevel = year;
    arr->stud[x].ID = id;
    arr->count += 1;
    
}

void transferList(ArrayList *arr, LinkedList *L, char course[]){
    int x, idx;
    LinkedList temp;
    for (x = 0; x < arr->count; x++){
        if (strcmp(arr->stud[x].course,course)==0){
            //printf("Found MAtch!\n");
            LinkedList* trav;
            for (trav = L; (*trav)!= NULL; (trav) = &(*trav)->link){}
            temp = malloc(sizeof(struct node));
            strcpy(temp->stud.Name, arr->stud[x].Name);
            temp->stud.MI = arr->stud[x].MI;
            strcpy(temp->stud.Lname, arr->stud[x].Lname);
            temp->stud.ID = arr->stud[x].ID;
            temp->stud.yearLevel = arr->stud[x].yearLevel;
            strcpy(temp->stud.course, arr->stud[x].course);
            
            *trav = temp;
            temp->link = NULL;
            for (idx = x; idx < arr->count; idx++){
                strcpy(arr->stud[idx].Name, arr->stud[idx+1].Name);
                strcpy(arr->stud[idx].Lname, arr->stud[idx+1].Lname);
                arr->stud[idx].MI = arr->stud[idx+1].MI;
                arr->stud[idx].yearLevel = arr->stud[idx+1].yearLevel;
                strcpy(arr->stud[idx].course, arr->stud[idx+1].course);
                arr->stud[idx].ID = arr->stud[idx+1].ID;
            }
            arr->count -+ 1;
            x--;
        }
    }
}

void displayLL(LinkedList L){
    LinkedList A;
    for (A = L; A!= NULL; A = A->link){
        printf("----------------------\n");
        printf("Name: %s %c. %s\n", A->stud.Name, A->stud.MI, A->stud.Lname);
        printf("ID: %d\nCourse: %s - %d\n", A->stud.ID, A->stud.course, A->stud.yearLevel);
        printf("------------------------\n\n");
    }
}
