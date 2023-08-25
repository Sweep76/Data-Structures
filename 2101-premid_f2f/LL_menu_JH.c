#include <stdio.h>
#include "LL_menu_J.c"

void main(){
    LIST L;
    init(&L);
    insertSorted(&L, "Joshua");
	insertSorted(&L, "James");
	insertSorted(&L, "Caitlin");
	insertSorted(&L, "Kyne");
	insertSorted(&L, "Teresa");
	insertSorted(&L, "Hannah");
	insertSorted(&L, "Bessa");
	insertSorted(&L, "Miguel");
	display(L);
	delete(&L, "Teresa");
    delete(&L, "Bessa");
    update(&L, "Caitlin", "Caitlin Lindsay");
	display(L);
	update(&L, "Joshua", "Joshua Chiu");
    update(&L, "Miguel", "Miguel Algarme");
	display(L); 
}