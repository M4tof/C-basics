#include <stdio.h> //must have
#include <math.h>
#include <stdbool.h>

bool test(int A){
    int B = pow(A,2);
    B = B%10;
    
    if(B==A){
        return true;
        }
    else{
        return false;
    }
}

int main(){ 
    
    int Rang1,Rang2;
    printf("Podaj dolna granice : ");
    scanf("%d",&Rang1);
    printf("Podaj gorna granice : ");
    scanf("%d",&Rang2);

    for (int i=Rang1;i<=Rang2;i++){ //Od 1 do R
    bool W = test(i);
    if(W==true){
        printf("%d\n",i);
    }
    }

    return 0;
}
