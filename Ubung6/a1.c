#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

typedef struct element* list; // list is a pointer to a struct element
struct element { int value; list next; };

/*
Geben Sie eine Funktion void append(list ∗lp, int n) an, welche ein neues Element e mit Schlüsselwert n erzeugt, dieses hinten an eine gegebene Liste ∗lp anhängt, und den Nachfolger von e auf NULL setzt.
Gehen Sie davon aus, dass lp != NULL ist.
*/
void append(list* lp, int n){
	while(*lp != NULL) {
		lp = &((*lp)->next);
	}
	*lp = malloc(sizeof(struct element)); // allocates memory and saves it into the struct l that points to element
	(*lp)->value = n;
	(*lp)->next = NULL;

	// int i = 4;
	// int *p = &i;
	// int j = *p;

	// el -> value; // the same thing than '(*el).value'
}

/*
Implementieren Sie eine Funktion sum , welche die Werte einer solchen Liste aufsummiert.
*/
int sum(list l){ // beachte: wir bekommen anders als bei append keinen Pointer auf eine Liste übergeben, sondern eine Liste!
	int sum = 0;
	while(l != NULL){
		sum += l->value;
		l = l->next;
	}
}

/*
Implementieren Sie eine Funktion rmEvens , welche aus einer Liste alle Elemente mit einer geraden Zahl entfernt. Dabei soll die bestehende Liste verändert werden.
*/
void rmEvens(list* lp) {
	while (*lp != NULL) {
		if ((*lp)->value % 2 == 0) {
			struct element* tmp = *lp; // oder: list tmp
			*lp = (*lp)->next;
			free(tmp);
		} else {
			lp = &((*lp)->next);
		}
	}
}

void rmEvens_rec(list *lp) {
	if (lp == NULL || *lp == NULL) return;
	if ((*lp)->value % 2 == 0) {
		list tmp = *lp;
		*lp = (*lp)->next;
		free(tmp);
	} else {
		lp = &((*lp)->next);
	}
	rmEvens_rec(lp);
}

void printlist(list l){
	printf("[");
	int first = 1;
	while(l != NULL){
		if(!first){
			printf(", ");
		} else { first = 0; }	
		printf("%i", l->value);
		l = l->next;
	}
	printf("]\n");
}

int main(){
	list l = NULL;
	// Geben Sie Aufrufe der Funktion append an, sodass eine Liste mit den Elementen 4, 2, 0 erzeugt wird.
	append(&l, 4);
	append(&l, 2);
	append(&l, 1);
	append(&l, 0);

	printf("Liste 1 =");
	printlist(l);

	// Teilaufgabe b) Summe
	// printf("Summe der Listen-Elemente = %i\n", sum(l));

	// Teilaufgabe c) gerade Zahlen entfernen
	// printf("Liste 1 nach rmEvens =");
	// rmEvens(&l);
	// printlist(l);
	return 0;
}
