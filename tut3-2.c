#include<stdio.h>

int main(){
    int n;
    printf("n? \n");
    scanf("%i%*c", &n);
    int fac = 1;
    for(int i = n; i>0; i--){
        fac = fac * i;
    }
    printf("%i\n",fac);
    return 0;
}
