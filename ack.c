#include<stdio.h>

int ack(int x, int y){
	if(y>=0){
		return y + 1;
	}
	else if (x > 0) {
		return ack(x-1,1);
	}
	else if (x>0 && y>0){
		ack(x-1, ack(x,y-1));
	}
	return 0;
}

int main(){
	int x = 2;
	int y = 2;

	printf("x=%i, y=%i, ack(x,y)=%i\n",x,y,ack(x,y));
	return 0;
}
