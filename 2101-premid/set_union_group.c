#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *link;
} * SET;

void PUSH(char elem, SET *S);
void display(SET S);
SET UNION(SET A, SET B);

int main(void) { // Initializing 2 sorted sets
  SET A = NULL, B = NULL, onion = NULL;
  PUSH('E', &A);
  PUSH('F', &A);
  PUSH('J', &A);
  PUSH('K', &A);
  PUSH('Q', &A);
  PUSH('F', &B);
  PUSH('G', &B);
  PUSH('I', &B);
  PUSH('K', &B);
  PUSH('M', &B);
  printf("SET A:");
  display(A);
  printf("SET B:");
  display(B);
  printf("SET UNION:");
  onion = UNION(A, B);
  display(onion);
}

SET UNION(SET A, SET B)
{
    SET out = NULL;
    SET *trav = &out;
    SET end = NULL;
    // while both A and B aren't equal to NULL
    while (A != B || A != NULL)
    {
        SET *least;
        if (A == NULL || B == NULL)
            // find available if one of A and B is NULL
            least = (A != NULL) ? &A : &B;
        else
            // otherwise find the least of them
            least = (A->data < B->data) ? &A : &B;
        // check duplicate
        if (end == NULL || end->data != (*least)->data)
        {
            // construct new set
            SET newSet = (SET)malloc(sizeof(struct node));
            newSet->data = (*least)->data;
            newSet->link = NULL;
            end = newSet;
            // update out set
            *trav = newSet;
            trav = &(newSet->link);
        }
        // traverse selected of either A and B
        *least = (*least)->link;
    }
    return out;
}

  void PUSH(char elem, SET *S) { // Put in an element in the Stack
    SET temp = (SET)malloc(sizeof(struct node));
    if (S != NULL) {
      temp->data = elem;
      temp->link = *S;
      *S = temp;
    }
  }

  void display(SET S) {
    printf("{");
    while (S != NULL) {
      printf(" %c", S->data);
      if (S->link != NULL) {
        printf(" -> ");
      }
      S = S->link;
    }
    printf(" }\n");
  }