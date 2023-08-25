#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
}*BST, nodetype;

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER,
}displaytype;

void init(BST *tree){
    *tree = NULL;
}

void insert(BST *tree, int data){
    BST *trav, temp;
    for(trav = tree;(*trav) != NULL && (*trav)->data != data; 
    trav = (data > (*trav)->data) ? &(*trav)->right : &(*trav)->left);
    
    if(*trav == NULL){
        temp = malloc(sizeof(nodetype));
        temp->data = data;
        *trav = temp;
        (*trav)->left = NULL;
        (*trav)->right = NULL;
    }
}

void display(BST tree, displaytype displaytype){
    if(displaytype == PREORDER){
        printf("%d ", tree->data);
    } if (tree->left != NULL){
        display(tree->left, displaytype);
    } if (displaytype == INORDER){
        printf("%d ", tree->data);
    } if (tree->right != NULL){
        display(tree->right, displaytype);
    } if(displaytype == POSTORDER){
        printf("%d ",tree->data);
    }
}

void delete(BST *tree, int data){
    BST *trav = tree;
    int retval;

    while((*trav) != NULL && tree != (*trav)->data){
        if(tree < (*trav)->data){
            trav = &(*trav)->left;
        } else {
            trav = &(*trav)->right;
        }
    }

}

int main(){
    BST tree;
    init(&tree);
    displaytype t1 = 0;
    displaytype t2 = 1;
    displaytype t3 = 2;

    init(&tree);
    insert(&tree, 10);
    insert(&tree, 19);
    insert(&tree, 18);
    insert(&tree, 12);
    insert(&tree, 1);
    insert(&tree, 3);

    printf("\n PREORDER IS: \t");
    display(tree, t1);
    printf("\n INORDER IS: \t");
    display(tree, t2);
    printf("\n POSTORDER IS: \t");
    display(tree, t3);

}