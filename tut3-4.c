#include<stdio.h>
#include<stdbool.h>

int main(){
    int n = 1000;
    for(int i = 2; i<n+1; i++){
        bool allesOk = true;
        for(int j = 2; j<i; j++){
            if(i%j == 0){
                allesOk = false;
            }
        }
        if (allesOk == true){
            printf("%i\t", i);
        }
    }

    return 0;
}