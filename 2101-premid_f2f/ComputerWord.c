#include <stdio.h>

typedef unsigned int set;

void add(set* set, int data) {
    *set |= 1<<data;
}

void unadd(set* set, int data) {
    *set &= ~(1<<data);
}

set unite(set set1, set set2) {
    return set1 | set2;
}

set intersect(set set1, set set2) {
    return set1 & set2;
}

void display(set set) {
    for (int temp=0 ; set>>temp!=0 ; temp++) {
        if ((set>>temp)%2==1) printf("%d ", temp);
    }
    printf("\n");
}

void displaybitpattern(set A){
    unsigned int mask;
    for(mask=1<<sizeof(A)*2; mask>0;mask>>=1){
        printf("%d", (A&mask) == 0 ? 0 : 1);
    }
    printf("\n");
}

int main() {
    set set1 = 0, set2 = 0;
    
    add(&set1, 1);  
    add(&set1, 2);
    add(&set1, 3);
    add(&set1, 4);
    add(&set1, 5);
    
    unadd(&set1, 4);
    
    add(&set2, 1);
    add(&set2, 3);
    add(&set2, 5);
    add(&set2, 7);
    add(&set2, 9);
    
    display(set1);
    // 1 2 3  5
    display(set2);
    // 1 3 5 7 9
    display(unite(set1, set2));
    // 1 2 3 4 5 7 9
    display(intersect(set1, set2));
    // 1 3 5

    displaybitpattern(set1);
    displaybitpattern(set2);

    return 0;
}