#include <stdio.h> //must have
int main(){ 
    for(int i=1;i<6;i++){
        for (int j=0;j<i;j++){
            printf("O");
        }
        printf("\n");
    }
    return 0;
}