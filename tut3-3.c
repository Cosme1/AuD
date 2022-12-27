#include<stdio.h>

int main(){
    int n;
    printf("n? \n");
    scanf("%i%*c", &n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            printf("%i\t", i*j);
            
        }
        printf("\n");
    }
    return 0;
}