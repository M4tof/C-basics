#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void op1(int n,int m, double Ma[n][m],double Mb[n][m],double Mr[n][m]){
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            Mr[y][x]=0;
            if(Ma[y][x]==Mb[y][x]){
                Mr[y][x]=1;
            }
        }
    }
}

void op2(int n,int m, double Ma[n][m],double Mb[n][m],double Mp[n][m]){
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            Mp[y][x]=0;
            if(Ma[y][x] > Mb[y][x]){
                Mp[y][x]=1;
            }
        }
    }
}

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
    
    for(int y=0;y<n;y++){
        printf("Podaj dane do wiersza %d macierzy A: ",y);
        for(int x=0;x<m;x++){
            scanf(" %lf",&A[y][x]);
        }
    }
    
    for(int y=0;y<n;y++){
        printf("Podaj dane do wiersza %d macierzy B: ",y);
        for(int x=0;x<m;x++){
            scanf(" %lf",&B[y][x]);
        }
    }

    op1(n,m,A,B,R);
    op2(n,m,A,B,P);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%lf ",R[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%lf ",P[i][j]);
        }
        printf("\n");
    }


}