#include <stdio.h> //must have
int main(){ 
    printf("Podaj wysokosc trojkata : ");
    int h,s,r,k=0;
    scanf("%d",&h);

    for(int i=1;i<=h;i++,k=0){

    for (s=1;s<=h-i;s++){
        printf(" ");
    }
    while ( k!=2 *i-1){
        printf("X");
        ++k;
    }
    printf("\n");
    }
    return 0;
}
