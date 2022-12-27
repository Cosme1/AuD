#include <stdio.h> // for printf
#include <stdlib.h> // for malloc

typedef struct node* tree;
struct node { int key; tree left, right; };

tree createNode(int n, tree l, tree r);

void lRot(tree* rootPointer){
	// Überprüfe, ob der Pointer auf NULL zeigt oder ob der Baum leer ist
	// handle entsprechend
	

	// speichere den ursprünglichen Wurzelknoten
	
	// speichere den Teilbaum, der der linke Nachfolger des rechten Nachfolgers
	// von der Wurzel ist (der, den wir "umhängen" müssen)
	
	// rotiere den rechten Nachfolger des Wurzelknotens zum neuen Wurzelknoten
	
	// hänge links an den neuen Wurzelknoten den ursprünglichen Wurzelknoten
	
	// hänge rechts an den ursprünglichen Wurzelknoten den Teilbaum, den wir umhängen mussten
	if (rootPointer == NULL){
		return;
	}

	tree wurzelknoten = malloc(rootPointer);
	tree oldRoot = *rootPointer;
	tree change = (*rootPointer)->right->left;
	*rootPointer = (*rootPointer)->right;
	(*rootPointer)->left = oldRoot;
	oldRoot->right = change;


}

/*======================================
			Helper Funktionen
======================================*/

tree createNode(int n, tree l, tree r){
	tree t = malloc(sizeof(struct node));
	t->left = l;
	t->right = r;
	t->key = n;
	return t;
}

void printtree_rec(tree t, int level){
	printf("%*s", level, "");
	if(t == NULL){
		printf(">NULL\n");
	} else {
		printf(">%i\n", t->key);
		if(!(t->left == NULL && t->right == NULL)){
			printtree_rec(t->left, level+2);
			printtree_rec(t->right, level+2);
		}
	}
}

void printtree(tree t){
	printtree_rec(t, 0);
}


int main(){
	tree t = createNode(2,
				createNode(1,NULL,NULL),
				createNode(4,
					createNode(3,NULL,NULL)
					,NULL
				)
			);
	printf("Baum t:\n");
	printtree(t);
	printf("Baum t nach Linksrotation um 1:\n");
	lRot(&t);
	printtree(t);
}