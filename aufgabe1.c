#include <stdio.h>

int primfac(int array[], int size){
	int rest = size;
	int currentidex = 0;
	// Teilziel 1: Primfaktorzerlegung von s berechnen und in a speichert

	// solange die Zahl noch teilbar ist
		// suche nach Teiler der Zahl
				// teile die Zahl
				// lege Teiler in Array
				// merke dir die nächste Zelle
	while(rest != 1){
		for(int i = 2; i<=size; i++){
			if (rest % i == 0){
				rest = rest / i;
				array[currentidex] = i;
				
				currentidex++;
				break;
			}
		}
	}
	// Teilziel 2: Anzahl der Faktoren in der Primfaktorzerlegung von s zurückgeben
	return currentidex; 
}

/* Gibt ein gegebenes Array auf der Kommandozeile aus */
void printArray(int array[], unsigned size){
	printf("[");
	for(int i = 0; i<size; i++){
		if(i == size-1){ // letzte Zelle
			// kein Komma nach der Zahl
			printf("%i", array[i]);
		} else { // alle anderen Zellen
			// fügt Komma an die Zahl an
			printf("%i, ", array[i]);
		}
	}
	printf("]\n");
}

int main(){
	int size = 24;
	int array[size];
	int anzahlPrim = primfac(array, size);
	printArray(array, anzahlPrim);

	// Rufe die Funktion auf

	// Gib das Ergebnis aus

	
	return 0;
}