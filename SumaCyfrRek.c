#include <stdio.h> //must have
#include <math.h>

int SumofDigit(int A,int B){
    if (A >=10){
        B+=(A%10);
        A=A/10;
        SumofDigit(A,B);
    }
    else{
        B+=(A%10);
        return B;
    }
}

int main(){ 
    int BigNum;
    printf("Podaj liczbe n : ");
    scanf("%d",&BigNum);

    printf("The sum of digits for this number is :");
    printf("%d",(SumofDigit(BigNum,0)));

    return 0;
}
