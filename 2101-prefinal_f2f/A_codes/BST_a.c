#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *LC;
    struct node *RC;
}*BST;

void initialize(BST* T);
void Insert(int e, BST* T);
void DisplayInOrder(BST T);
void DisplayPreOrder(BST T);
void DisplayPostOrder(BST T);
int IsMember(int e, BST T);
int Delete(int e, BST *T);

void main(){
    BST Tree;
    initialize(&Tree);
    Insert(10, &Tree);
    Insert(19, &Tree);
    Insert(18, &Tree);
    Insert(12, &Tree);
    Insert(1, &Tree);
    Insert(3, &Tree);
    Insert(3, &Tree);
    Insert(3, &Tree);
    printf("In Order: ");
    DisplayInOrder(Tree);
    printf("\nPre Order: ");
    DisplayPreOrder(Tree);
    printf("\nPost Order: ");
    DisplayPostOrder(Tree);


    int val = IsMember(4, Tree);
    if (val == 1){
        printf("true\n");
    }else{
        printf("false\n");
    }

    val = IsMember(3, Tree);
    if (val == 1){
        printf("true\n");
    }else{
        printf("false\n");
    }

    val = Delete(3, &Tree);
    printf(" %d\n", val);
    DisplayInOrder(Tree);
    Insert(3, &Tree);


    DisplayPreOrder(Tree);
    val = Delete(19, &Tree);
    printf(" %d\n", val);
    printf("\n");
    DisplayPreOrder(Tree);

    MakeNull(&Tree);
    DisplayInOrder(Tree);
}

void initialize(BST *T){
    *T = NULL;
}

void Insert(int e, BST* T){
    BST* trav = T;
    while(*trav!= NULL && (*trav)->data != e){
        if (e < (*trav)->data){
            trav = &(*trav)->LC;
        }else{
            trav = &(*trav)->RC;
        }
    }

    if (*trav == NULL){
        *trav = malloc(sizeof(struct node));
        (*trav)->data = e;
        (*trav)->LC = NULL;
        (*trav)->RC = NULL;
        printf("Inserted: %d \n", e);
    }else{
         printf("Duplicate not Inserted: %d \n", e);
    }
}

void DisplayInOrder(BST T){
    if (T){
        DisplayInOrder(T->LC);
        printf("%d ", T->data);
        DisplayInOrder(T->RC);
    }
}

void DisplayPreOrder(BST T){
    if (T){
        printf("%d ", T->data);
        DisplayPreOrder(T->LC);
        DisplayPreOrder(T->RC);
    }
}

void DisplayPostOrder(BST T){
    if (T){
        DisplayPostOrder(T->LC);
        DisplayPostOrder(T->RC);
        printf("%d ", T->data);
    }
}

int IsMember(int e, BST T){
    printf("\nFinding Member : %d ", e);
    BST trav = T;
    while (trav != NULL && trav->data != e){
        if (e < trav->data){
            trav = trav->LC;
        }else{
            trav = trav->RC;
        }
    }
    return (trav != NULL)? 1 : 0;
}

int Delete(int e, BST* T){
    BST *trav = T, del = NULL;
    int retval;

    while((*trav)!=NULL && e != (*trav)->data){
        if(e < (*trav)->data){
            trav = &(*trav)->LC;
        }else{
            trav = &(*trav)->RC;
        }
    }

    if(*trav == NULL){
        retval = e;
        printf("\nNOT FOUND, UNABLE TO DELETE: ");
    }else if ((*trav)->LC == NULL && (*trav)->RC == NULL){
        del = *trav;
        retval = del->data;
        free(del);
        *trav = NULL;
        printf("\nDeleted: ");
    }else if ((*trav)->LC != NULL && (*trav)->RC != NULL){
        retval = (*trav)->data;
        //Immediate Predecessor
        /*int predecessor;
        BST A = ((*trav)->LC);
        while (A->RC != NULL){
            A = A->RC;
        }
        predecessor = A->data;
        Delete(predecessor, T);
        (*trav)->data = predecessor;
        printf("\nDeleted: ");*/

        //Immediate Successor
        int successor;
        BST A = ((*trav)->RC);
        while (A->LC!= NULL){
            A = A->LC;
        }
        successor = A->data;
        Delete(successor, T);
        (*trav)->data = successor;
        printf("\nDeleted: ");
        
    }else if ((*trav)->LC != NULL && (*trav)->RC == NULL){
        del = *trav;
        retval = del->data;
        (*trav) = (*trav)->LC;
        free(del);
        printf("\nDeleted: ");
    }else if((*trav)->LC == NULL && (*trav)->RC != NULL){
        del = *trav;
        retval = del->data;
        (*trav) = (*trav)->RC;
        free(del);
        printf("\nDeleted: ");
    }

    return retval;
}

void MakeNull(BST* T){
    if ((*T)!= NULL){
        MakeNull(&(*T)->LC);
        MakeNull(&(*T)->RC);
        BST temp = (*T);
        free(temp);
        (*T) = NULL;
    }
    return;
}

// this is the code from angelou