#include <stdio.h>   
#include <string.h>   
#include <stdlib.h> 

double Srednia(double pomiary[]){
    double suma=0.0;
    for (int i=0; i<4; i++){
        suma+=pomiary[i];
    }

    return suma/4;
}

double Maks(double pomiary[]){
    double maks = pomiary[0];
    for(int i=0;i<4;i++){
        if(pomiary[i] > maks){
            maks=pomiary[i];
        }
    }
    return maks;
}

double Mini(double pomiary[]){
    double mini = pomiary[0];
    for(int i=0;i<4;i++){
        if(pomiary[i] < mini){
            mini=pomiary[i];
        }
    }
    return mini;
}

int main(){ 
    double (*przetwarzanie[3])(double[]);
    przetwarzanie[0]=Srednia;
    przetwarzanie[1]=Maks;
    przetwarzanie[2]=Mini;

    FILE* original = fopen("./Pomiary.txt", "r");
    FILE* output = fopen("./Wyniki.txt", "w");
    if (original == NULL || output == NULL) {
        printf("Blad otwarcia pliku\n");
        return 1;
    }

    char line[100];
    int Current=1;
    int NrSeri;
    double Pomiary[4];

    while(fgets(line,100,original)!=NULL){
        if(Current==1){
            NrSeri=atoi(line);
        }
        if(Current>1 && Current<6){
            Pomiary[Current-2]=atof(line);
        }
        Current++;
        if(Current==7){
            printf("Seria = %d, ",NrSeri);
            printf("%lf ",Pomiary[0]);
            printf("%lf ",Pomiary[1]);
            printf("%lf ",Pomiary[2]);
            printf("%lf",Pomiary[3]);
            printf(" Kod przetwarzania = %d \n", atoi(line));
            Current=1;
            
            double wynik = przetwarzanie[atoi(line)](Pomiary);

            fprintf(output, "%d\n%lf\n%d\n",NrSeri,wynik,atoi(line));
        }

    }
    fclose(output);
    fclose(original);
    
    return 0;
}