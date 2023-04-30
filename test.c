#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void op(int m, int n, double A[n][m]){
    A[0][0] = 9;
}

int main(){ 
    
    double A[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    
    op(3,3,A);
    
    printf("%lf",A[0][0]);
    return 0;
}