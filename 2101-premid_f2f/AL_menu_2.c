#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
  char list[100];
  int count;
} ArrayList;

ArrayList init() {
  ArrayList newArray;
  newArray.count = 0;
  
  return newArray;
}

// test push


void insert(ArrayList* arr, char element) {
    int i, j;
    if (arr->count >= MAX) {
        printf("ArrayList is full.\n");
        return;
    }
    arr->list[arr->count++] = element;

    // Sorting
    for (i = 0; i < arr->count; i++) {
        for (j = i+1; j < arr->count; j++) {
            if (arr->list[i] > arr->list[j]) {
                char temp = arr->list[i];
                arr->list[i] = arr->list[j];
                arr->list[j] = temp;
            }
        }
    }
}

void delete(ArrayList* arr, char element) {
    int i, j;
    for (i = 0; i < arr->count; i++) {
        if (arr->list[i] == element) {
            for (j = i+1; j < arr->count; j++) {
                arr->list[j-1] = arr->list[j];
            }
            arr->count--;
            printf("%c has been removed.\n", element);
            return;
        }
    }
    printf("%c was not found in ArrayList.\n", element);
}

void show(ArrayList* arr) {
    printf("Array content: ");
    int i;
    for (i = 0; i < arr->count; i++) {
        printf("%c ", arr->list[i]);
    }
    printf("\n");
}

void update(ArrayList* arr, char oldElement, char newElement) {
    int i, j;
    for (i = 0; i < arr->count; i++) {
        if (arr->list[i] == oldElement) {
            arr->list[i] = newElement;
            // Sorting
            for (j = 0; j < arr->count; j++) {
                if (arr->list[i] < arr->list[j]) {
                    char temp = arr->list[i];
                    arr->list[i] = arr->list[j];
                    arr->list[j] = temp;
                }
            }
            printf("%c has been updated to %c.\n", oldElement, newElement);
            return;
        }
    }
    printf("%c was not found in ArrayList.\n", oldElement);
}


int main() {
    ArrayList arr = init();

    insert(&arr, 'A');
    insert(&arr, 'B');
    insert(&arr, 'C');
    insert(&arr, 'D');
    insert(&arr, 'E');
    show(&arr);

    delete(&arr, 'D');
    show(&arr);

    update(&arr, 'A', 'X');
    show(&arr);

    return 0;
}