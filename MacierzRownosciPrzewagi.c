#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){ 
    int n;
    int m;
    int test =0;
    printf("Podaj dane do macierzy: \n");
    while(test==0){
        printf("Wartosc n:");
        scanf(" %d",&n);
    
        if(n<=0 || n>=15){
        printf("Zla wartosc\n");
        }
        
        else{
            test=1;
        }

    }
    test=0;
        while(test==0){
        printf("Wartosc m:");
        scanf(" %d",&m);
    
        if(m<=0 || m>=15){
        printf("Zla wartosc\n");
        }
        
        else{
            test=1;
        }

    }
    double A[n][m];
    double B[n][m];
    double R[n][m];
    double P[n][m];
    


}