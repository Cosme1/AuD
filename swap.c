#include<stdio.h>

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	int x = 3;
	int y = 6;
	printf("x=%i, y=%i\n", x,y);
	swap(&x, &y);
	printf("x=%i, y=%i",x,y);
	return 0;
}
