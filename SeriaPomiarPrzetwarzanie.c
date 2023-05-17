#include <stdio.h>   
#include <string.h>   
#include <stdlib.h> 





int main(){ 
    FILE* original = fopen("./Pomiary.txt","r");   
    if (original == NULL){
        printf("Blad otwarcia pliku\n");   
        return 1;
    }
    char line[100];

    int Current=1;
    int NrSeri;
    char Trash;
    double Pomiary[4];

    while(fgets(line,100,original)!=NULL){
        if(Current==1){
            NrSeri=atoi(line);
        }
        if(Current>1 && Current<6){
            Pomiary[Current-2]=strtod(line,&Trash);
        }
        Current++;
        if(Current==7){
            printf("%d h,",NrSeri);
            printf("%lf ",Pomiary[0]);
            printf("%lf ",Pomiary[1]);
            printf("%lf ",Pomiary[2]);
            printf("%lf\n",Pomiary[3]);
            Current=1;
        }
    }





    return 0;
}