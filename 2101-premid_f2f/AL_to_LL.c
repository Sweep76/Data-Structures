#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char FName[24], MI[5], LName[16];
    unsigned int ID;
    char course[8]; //BSCS,BSIT,BSMATH
    int yearLevel;
}studtype;

typedef struct node{
    studtype stud;
    struct node *link;
}*LinkedList;

#define SIZE 20

typedef struct {
    studtype stud[SIZE];
    int count;
}ArrayList;

//for ArrayList functions
void insertArray(ArrayList *A, char *fname, char *mi, char *lname, int id, char *course, int year);
void displayAL(ArrayList *A);
void init(ArrayList *A);

//for Linked List Functions
void displayL(LinkedList L, ArrayList A);
void insertLL(LinkedList *L, ArrayList *A, char *course);

//Main
void main(){
    ArrayList A;
    LinkedList L = NULL;
    init(&A);
    insertArray(&A, "joshua", "g", "zonk", 6969, "BSCS", 2002);
    insertArray(&A, "yuhn", "g", "SLEEP", 1234, "BSCS", 2003);
    insertArray(&A, "yere", "t", "turn", 8765, "BSIS", 2004);
    insertArray(&A, "bere", "t", "burn", 8765, "BSCS", 2004);
    displayAL(&A);
    insertLL(&L, &A, "BSCS");
    displayL(L,A);
}


//list of functions

void insertLL(LinkedList *L, ArrayList *A, char *course){
LinkedList temp,*trav; 
	int x,j=A->count;
	for(x=0;x<j;x++){
		if(strcmp(A->stud[x].course,course) == 0){
			A->count--;
			
			
			for (trav = L; *trav != NULL && strcmp((*trav)->stud.FName,A->stud[x].FName) <= 0 ;trav = &(*trav)->link){}
				temp = (LinkedList)malloc(sizeof(struct node));
				if (temp != NULL){
				temp->stud = A->stud[x];
				temp->link = *trav;
				*trav = temp;
			}
			
		}
	}
}

   void displayL(LinkedList L, ArrayList A){
    LinkedList trav; int i;
    printf("LINKED LIST DISPLAY\n");
    for (trav = L; trav != NULL; trav = trav->link){
        printf("%s->" ,trav->stud.FName);
    }
    printf("NULL");
    printf("\nonly %d student left in the array", A.count);
}


void init(ArrayList *A){
    A->count = 0;
}

void insertArray(ArrayList *A, char *fname, char *mi, char *lname, int id, char *course, int year){
    strcpy(A->stud[A->count].FName, fname);
    strcpy(A->stud[A->count].MI, mi);
    strcpy(A->stud[A->count].LName, lname);
    A->stud[A->count].ID = id;
    strcpy(A->stud[A->count].course, course);
    A->stud[A->count].yearLevel = year;
    A->count++;
}


void displayAL(ArrayList *A){
    int x;
    printf("\tARRAY LIST DISPLAY\n\n");
    printf("\tIndex|\tFirstName|\tMiddleName|\tLastName|\tID|\t\tCourse|\t\tYear|\n");
    for(x=0;x<A->count;x++){
        printf("\t%d\t%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d\n\n", x, A->stud[x].FName,A->stud[x].MI,
                                             A->stud[x].LName,A->stud[x].ID,
                                             A->stud[x].course,A->stud[x].yearLevel);
    }
}