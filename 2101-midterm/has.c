#include <stdio.h>
#include <string.h>

int hash(char L[]);

int main(){
    char L [10] = "Charlie";
    printf("output is: %d", hash(L));
}

int hash(char L[]){
    return L[0] % 65;
}