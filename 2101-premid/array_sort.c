#include <stdio.h>
#define SIZE 10

int main(){
    int arr[SIZE] = {1,2,3,4,5};
    int count = 6;
    arrdisplay(arr, count);
    insert(&arr,3,9,&count);
    printf("\n%d", count);
    arrdisplay(arr, count);
    insert(&arr,4,8,&count);
    printf("\n%d", count);
    arrdisplay(arr, count);

}

int insert(int arr[], int pos, int element, int *count){
    if(pos >=0 && pos < SIZE){
        for(int i = *count; i>pos; i--){
            arr[i] = arr[i-1];
        }
        *count += 1;
        arr[pos]=element;
    }
}

int arrdisplay(int arr[], int count){
    printf("\n");
    for(int i=0; i<count; i++){
        printf("%d ",arr[i]);
    }
}