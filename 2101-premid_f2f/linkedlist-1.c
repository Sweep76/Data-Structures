#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int e;
    char trantype;
    char priority;
    struct node* link;
}Node;
typedef struct service{
    	int loan;
    	int ctr;
    	int membership;
    	int contribution;
}service;

Node* push(Node* list, service* s);
Node* append(Node* list);
Node* dequeue(Node* list, char priority);
void peek(Node *head);
void display(Node* list);

void main (){
    Node* head = NULL;
    service s;
	
	s.loan = 0;
	s.ctr = 0;
	s.contribution = 0;
	s.membership = 0;
	
    int choice;
    do{
    system("CLS");
    printf("1. Add\n2. Display All\n3. Append\n4. Dequeue\n5. Show Next\n0. Exit\n");
    scanf(" %d", &choice);
    switch(choice){
        case 1:
            head = push(head, &s);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = append(head);
            break;
        case 4:
            head = dequeue(head, 'N');
            break;
        case 5:
            peek(head);
        case 0:
            break;
        default:
            printf("Invalid Input!\n");
            system("PAUSE");
    }
    }while(choice!= 0);
}

Node* push(Node* list, service* s){
    Node* a = malloc(sizeof(struct node));
    Node* trav;
    int exit = 0, count;
    if (a == NULL){
        printf("\nFAILED TO ALLOCATE MEMORY!");
        system("PAUSE");
        return list;
    }else{
        if (list == NULL){
        //ask for cust transaction
        	do{
        	printf("\nSelect Customer Transaction:\n1. Loan\n2. Membership\n3. Contribution\n> ");
        	scanf(" %c", &a->trantype);
        	switch (a->trantype){
        		case '1':
        			count = s->ctr;
        			a->e = ++count;
        			s->ctr = count;
        			a->trantype = 'L';
        			exit = 1;
        			break;
        		case '2':
        				count = s->ctr;
	        			a->e = ++count;
	        			s->ctr = count;
        			exit = 1;
        			a->trantype = 'M';
        			break;
        		case '3':
        			count = s->ctr;
	        			a->e = ++count;
	        			s->ctr = count;
	        			a->trantype = 'C';
        			exit = 1;
        			break;
        		default:
        			printf("\nIncorrect Input. Try Again!\n");
        			system("PAUSE");
			}
		}while(exit != 1);
		
		//ask for cust type
		do{
        	printf("\nSelect Customer Type:\n1. Normal\n2. Pregnant\n3. Disabled\n4. Senior Citizen\n> ");
        	scanf(" %c", &a->priority);
        	switch (a->priority){
        		case '1':
        			a->priority = 'N';
        			exit = 1;
        			break;
        		case '2':
        			a->priority = 'P';
        			exit = 1;
        			break;
        		case '3':
        			a->priority = 'D';
        			exit = 1;
        			break;
        		case '4':
        			a->priority = 'S';
        			exit = 1;
        			break;
        		default:
        			printf("\nIncorrect Input. Try Again!\n");
        			system("PAUSE");
			}
		}while(exit != 1);
		
        printf("\nAdded customer: \n%d\nTransaction: %c\nPriority: %c \n", a->e, a->trantype, a->priority);  
        a->link = NULL;
        system("PAUSE");
        return a;
    }else{
	    	do{
	        	printf("\nSelect Customer Transaction:\n1. Loan\n2. Membership\n3. Contribution\n> ");
	        	scanf(" %c", &a->trantype);
	        	switch (a->trantype){
	        		case '1':
	        			count = s->ctr;
	        			a->e = ++count;
	        			s->ctr = count;
	        			a->trantype = 'L';
	        			exit = 1;
	        			break;
	        		case '2':
	        			count = s->ctr;
	        			a->e = ++count;
	        			s->ctr = count;
	        			a->trantype = 'M';
	        			exit = 1;
	        			break;
	        		case '3':
	        			count = s->ctr;
	        			a->e = ++count;
	        			s->ctr = count;
	        			a->trantype = 'C';
	        			exit = 1;
	        			break;
	        		default:
	        			printf("\nIncorrect Input. Try Again!\n");
	        			system("PAUSE");
				}
			}while(exit != 1);
			
			//ask for cust type
			do{
	        	printf("\nSelect Customer Type:\n1. Normal\n2. Pregnant\n3. Disabled\n4. Senior Citizen\n> ");
	        	scanf(" %c", &a->priority);
	        	switch (a->priority){
	        		case '1':
	        			a->priority = 'N';
	        			exit = 1;
	        			break;
	        		case '2':
	        			a->priority = 'P';
	        			exit = 1;
	        			break;
	        		case '3':
	        			a->priority = 'D';
	        			exit = 1;
	        			break;
	        		case '4':
	        			a->priority = 'S';
	        			exit = 1;
	        			break;
	        		default:
	        			printf("\nIncorrect Input. Try Again!\n");
	        			system("PAUSE");
				}
			}while(exit != 1);
			a->link = NULL;
			for (trav = list; trav->link!=NULL; trav = trav->link);
			trav->link = a;
	        printf("\nAdded customer: \n%d\nTransaction: %c\nPriority: %c \n", a->e, a->trantype, a->priority);  
	        system("PAUSE");
        	return list;
    }
    
    }
    
    

}

Node* append(Node* list){
    Node *a = malloc(sizeof(struct node));
    Node *trav = list;
    if (list == NULL){
        printf("Enter value to be inserted: ");  
        scanf(" %d", &a->e);
        a->link = NULL;
        printf("\nADDED: %d\n", a->e);
        system("PAUSE");
        return a;
    }else{
        printf("Enter value to be inserted: ");  
        scanf(" %d", &a->e);
        a->link = NULL;
        while(trav->link!=NULL){
            trav = trav->link;
        }
        trav->link = a;
        printf("\nADDED: %d\n", a->e);
        system("PAUSE");
        return list;
    }
    
}

void display(Node* list){
    Node* trav;
    printf("\nList:\n");
    if (list == NULL){
        printf("LIST IS EMPTY!\n");
    }else{
        for (trav = list; trav != NULL; trav = trav->link){
            printf("\nCustomer %d \nTransaction Type: %c \nPriority: %c \n-------------------------------------------\n", trav->e, trav->trantype, trav->priority);
        }
    }
    
    system("PAUSE");
}


Node* dequeue(Node* list, char trantype){
    Node *trav, *temp;
    if (list == NULL){
        printf("\nList is EMPTY nothing to dequeue\n");  
        system("PAUSE");
        return NULL;
    }else if (list->link == NULL){
        printf("\nYou are about to dequeue %d\n", list->e);
        system("PAUSE");
        free(list);
        return NULL;
    }
    else{///// This is unfinished here!!!! 
        for (trav = list; trav->trantype!= trantype && trav->priority != 'N'; trav = trav->link);
        if (trav == NULL){
        	if (list->trantype == trantype){
        		temp = list->link;
				free(list);
				return temp;
			}else{
				for (trav = list; trav->link->trantype!= trantype; trav = trav->link);
				printf("\nYou are about to dequeue customer: %d \nTransaction: %c\nPriority: %c\n", trav->link->e, trav->link->priority);
				 system("PAUSE");
        		temp = trav->link->link;
        		free(trav->link);
        		trav->link = temp;
			}
        	
		}
        
        return list;
    }
        
    
    
}

void peek(Node *head){
    Node *trav;
    if (head == NULL){
        printf("\nList is empty!\n");
        system("PAUSE");
    }else{
        for (trav = head; trav->link!=NULL; trav = trav->link);
        printf("\nNext in queue is: %d\n", trav->e);
        system("PAUSE");
    }
    
}
