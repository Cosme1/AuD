#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

typedef struct node* tree;
struct node { int value; tree left, right; };

/*
Geben Sie eine Funktion tree createNode(int n, tree l, tree r) an, welche einen Binärbaum erzeugt, sodass dessen Wurzel den Schlüsselwert n hat und die Nachfolger der Wurzel l und r sind.
*/
tree createNode(int n, tree l, tree r){
	struct node* t = malloc(sizeof(struct node));
	t->value = n;
	t->left = l;
	t->right = r;
	return t;
}

/*
Geben Sie eine Funktion void insertl(tree* tp, int n) an, welche einen Knoten mit dem Schlüsselwert n als am weitesten linksstehenden Knoten in den Baum *tp einfügt.
Gehen Sie davon aus, dass tp != NULL ist.
*/
void insertl_iter(tree* tp, int n){
	while (*tp != NULL)
	{
		tp = &((*tp)->left);
	}
	*tp = createNode(n, NULL, NULL);
	
}

void insertl_rec(tree* tp, int n){
	if(*tp != NULL){
		insertl_rec(&((*tp)->left), n);
	} else {
		*tp = createNode(n, NULL, NULL);
	}
}


/*
Ein Blatt ist ein Knoten, dessen linker und rechter Teilbaum jeweils leer ist. Implementieren Sie eine Funktion int leafprod(tree t) , welche für einen Eingabebaum t das Produkt
der Knotenbeschriftungen der Blätter in t berechnet!
*/
int leafprod(tree t){
	if(t == NULL){
		return 1;
	}
	if (t->left == NULL && t->right == NULL){
		return t->value;
	}

	return leafprod(t->left) * leafprod(t->right);
}


/*
Schreiben Sie eine Funktion treeToList , welche aus einem beliebigen Binärbaum t des oben genannten Typs eine Liste l der geraden Schlüsselwerte ( value ) von t generiert. Dabei soll l die Schlüsselwerte in folgender Reihenfolge enthalten:
• zunächst die geraden Schlüsselwerte im linken Teilbaum von t,
• dann gegebenenfalls den Schlüsselwert am Wurzelknoten, und
• zuletzt die geraden Schlüsselwerte im rechten Teilbaum von t.
Geben Sie alle dazu erforderlichen Variablendeklarationen und einen Aufruf Ihrer Funktion an.
Hinweis: Nutzen Sie die Funktion append aus der vorherigen Aufgabe.
*/

typedef struct element* list;
struct element { int value; list next; };

void append(list* lp, int n){
	while (*lp != NULL)
		lp = &((*lp)->next);
	(*lp) = (list) malloc(sizeof(struct element));
	(*lp)->value = n;
	(*lp)->next = NULL;
}

void treeToListRec(tree t, list* lp){
	if(t== NULL) {
		return;
	}
	treeToListRec(t->left, lp);

	if(t->value % 2 == 0) {
		append(lp, t->value);

	}

	treeToListRec(t->right, lp);
}

list treeToList(tree t){
	list l = NULL;
	treeToListRec(t, &l);
	return NULL;
}

void printtree_rec(tree t, int level){
	printf("%*s", level, "");
	if(t == NULL){
		printf(">NULL\n");
	} else {
		printf(">%i\n", t->value);
		if(!(t->left == NULL && t->right == NULL)){
			printtree_rec(t->left, level+2);
			printtree_rec(t->right, level+2);
		}
	}
}

void printtree(tree t){
	printtree_rec(t, 0);
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
	// Geben Sie Aufrufe der Funktion an, um den Baum 3(1,2(1, )) zu erzeugen.
	tree t = createNode(4,
		createNode(2, NULL, NULL),
		createNode(6, NULL, NULL)
	);// TODO
	printtree(t);
	printf("\n");
	
	insertl_iter(&t, 27);
	printtree(t);
	printf("\n");
	
	printf("Blattprodukt:%i\n", leafprod(t));

	list l = treeToList(t);
	printf("\n");
	printlist(l);

	return 0;
}
