#include <stdio.h>
#include <string.h>

int palindrom(char str[], int length){
	for (int i = 0; i < length / 2; i++){
		if(str[i] != str[length-i-1]){
			return 0;
		}
	}
	
	return 1;
}

int palindrom2(char str[], int lo, int hi){
	if(lo >= hi){
		return 1;
	}

	if(str[lo] != str[hi]){
		return 0;
	}

	return palindrom2(str, lo+1, hi-1);
}

int main(){
	printf("leeres Wort ist Palindrom =\t%i\t%i \n", palindrom("", 0), palindrom2("", 0, 0));
	printf("abcdcba ist Palindrom =\t\t%i\t%i \n", palindrom("abcdcba", 7), palindrom2("abcdcba", 0, 6));
	printf("abccba ist Palindrom =\t\t%i\t%i \n", palindrom("abccba", 6), palindrom2("abccba", 0, 5));
	printf("hallollah ist Palindrom =\t%i\t%i \n", palindrom("hallollah", 9), palindrom2("hallollah", 0, 8));
	printf("Hallo Welt ist Palindrom =\t%i\t%i \n", palindrom("Hallo Welt", 10), palindrom2("Hallo Welt", 0, 9));
	return 0;
}