#include <stdio.h>
#include <stdlib.h>
#define MAX 40

typedef struct {
	int data[MAX];
	int link[MAX];
	int avail;
}VirtualHeap;

typedef int Cursor;

void initializeVH(VirtualHeap *VH);
void displayVH(VirtualHeap VH);
int allocSpace(VirtualHeap *VH);
void addNode(int data, Cursor* list, VirtualHeap *VH);
void addNodeSorted(int data, Cursor* list, VirtualHeap *VH);
void displayList(VirtualHeap VH, Cursor L);
void deleteNode(VirtualHeap *VH, int data, Cursor *L);
void freeSpace(VirtualHeap *VH, int idx);
int getUnion(VirtualHeap *VH, Cursor A, Cursor B);

void main() {
	VirtualHeap mem;
	initializeVH(&mem);
	displayVH(mem);

	Cursor L = -1;
	addNodeSorted(9, &L, &mem);
	addNodeSorted(8, &L, &mem);
	//addNodeSorted(2, &L, &mem);


	//deleteNode(&mem, 2, &L);

	Cursor A = -1;
	addNode(10, &A, &mem);
	addNode(10, &A, &mem);
	addNode(10, &A, &mem);
	addNode(10, &A, &mem);
	addNode(10, &A, &mem);
	addNode(15, &A, &mem);
	deleteNode(&mem,15, &A);
	printf("LIST L is: ");
	displayList(mem, L);
	printf("\n");
	//displayVH(mem);
	int unionlist = getUnion(&mem, L, A);
	displayVH(mem);
	printf("\nUnionList: ");
	displayList(mem, unionlist);
	
	
}

//for the virtual heap operations
void initializeVH(VirtualHeap *VH){
	int x;
	for (x = 0; x < MAX; x++){
		VH->data[x] = 0;
		VH->link[x] = x+1;
	}
	VH->link[x-1] = -1;
	VH->avail = 0;
}

void displayVH(VirtualHeap VH){
	int x;
	for (x = 0; x < MAX; x++){
		printf("%d\t%d\t%d\n", x, VH.data[x], VH.link[x]);
	}
}

int allocSpace(VirtualHeap *VH){
	int temp = VH->avail;
	VH->avail = VH->link[VH->avail];
	return temp;
}

void addNodeSorted(int data, Cursor* list, VirtualHeap *VH){
	int *temp;
	for (temp = list; *temp != -1 && VH->data[*temp] < data; temp = &(VH->link[*temp])){}
	int newnode = allocSpace(VH);
	if (newnode != -1){
		VH->data[newnode] = data;
		VH->link[newnode] = *temp;
		*temp = newnode;
		//*temp = newnode;
		
	}else{
		printf("\nMEMORY FULL!!");
	}

}

//adds at the end of the List
void addNode(int data, Cursor* list, VirtualHeap *VH){
	int *temp;
	for (temp = list; *temp != -1; temp = &(VH->link[*temp])){}
	int newnode = allocSpace(VH);
	if (newnode != -1){
		VH->data[newnode] = data;
		VH->link[newnode] = -1;
		*temp = newnode;
		
	}

}

void displayList(VirtualHeap VH, Cursor L){
	for (; L!=-1; L = VH.link[L]){
		printf("%d ", VH.data[L]);
	}
}

void freeSpace(VirtualHeap *VH, int idx){
	VH->link[idx] = VH->avail;
	VH->avail = idx;
}

void deleteNode(VirtualHeap *VH, int data, Cursor *L){
	int *A;
	for (A = L; *A!=-1 && VH->data[*A]!= data; A = &(VH->link[*A])){} 
	//this will find the specific data and if found removes it from the list

	if (*A!=-1){
		int temp = VH->link[*A];
		freeSpace(VH, *A);
		*A = temp;
	}
}

int findOccurence(VirtualHeap VH, Cursor L, int elem){
	int trav;
	for (trav = L; trav!= -1 && VH.data[trav]!= elem; trav = VH.link[trav]);
	printf("\nOccurence: %d\n", trav);
	//displayVH(VH);
	return (trav == -1)? 0 : 1;
}

int getUnion(VirtualHeap *VH, Cursor a, Cursor b){
	int set = -1;
	int A = a;
	int B = b;

	while (A != -1 || B != -1){
		if (A!=-1 && B != -1){
			if ((findOccurence(*VH, set, VH->data[A])==0)){
				addNodeSorted(VH->data[A], &set, VH);
			}
			if ((findOccurence(*VH, set, VH->data[B])==0)){
				addNodeSorted(VH->data[B], &set, VH);
			}

			A = VH->link[A];
			B = VH->link[B];
		}else if (A==-1 && B != -1){
			if ((findOccurence(*VH, set, VH->data[B])==0)){
				addNodeSorted(VH->data[B], &set, VH);
			}

			B = VH->link[B];
		}else if (A!=-1 && B== -1){
			if ((findOccurence(*VH, set, VH->data[A])==0)){
				addNodeSorted(VH->data[A], &set, VH);
			}
			A = VH->link[A];
		}
		
		//displayVH(*VH);
		//system("PAUSE");
	}

	return set;
}