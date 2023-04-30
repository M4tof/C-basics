#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double A[4][4]={{1,2,3},{4,5,6},{7,8,9}}; //Przykładowa macierz A

double B[50][50]={{}};

double A2B(double Aij){
    double Bij=3.31;
    
    if (Aij+1 >0){
    Bij = (pow(sin(Aij),2) -3) / (pow((Aij+1),0.5));
    }
    
    return Bij;
}

void main(){ 
    int n = sizeof(A)/sizeof(A[0]) ;
    int m = sizeof(A[0])/sizeof(A[0][0]);

    for(int y=0;y<n;y++){
        for (int x=0;x<m;x++){
            B[y][x]=A2B(A[y][x]);            
        }
    }

    for(int y=0;y<n;y++){
        for (int x=0;x<m;x++){
            printf(" %lf",B[y][x]);           
        }
        printf("\n");
    }

}