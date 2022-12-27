#include<stdio.h>

int main(){
    int z1;
    int z2;
    printf("Zahl 1? \n");
    scanf("%i%*c", &z1);
    printf("Zahl 2? \n"); 
    scanf("%i%*c", &z2);
    if(z1 > z2){
        printf("Mazimum: %i\n", z1);
    }
    else printf("Maximum: %i\n", z2);

    for (int i = 0; i < 5; i++)
    {
        
    }
    

    return 0; 
}