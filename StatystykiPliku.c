#include <stdio.h>   
#include <string.h>   
#include <stdlib.h> 
#include <math.h>


void Count_Numbers(FILE* origianl,FILE* new_file){
    int Suma[1000]={0};
    int Licznosc[1000]={0};
    int final=0;
    char line[1000];
    char *iteam;
    int numer;

    while(fgets(line,100,origianl)!=NULL){
        int current=0;
        numer=0;
        iteam = strtok(line, " \n");
        while (iteam != NULL){
            Suma[numer]+=atoi(iteam);
            Licznosc[numer]++;
            current++;
            iteam = strtok(NULL, " \n");
        }
        if (current > final){
            final=current;
        }
    }
    //TODO//
    

    fprintf(new_file,"Suma:");
    for(int i=0;i<=final;i++){
        fprintf(new_file," %d",Suma[i]);
    }
    fprintf(new_file,"\n");

    fprintf(new_file,"Srednia:");
    for(int g=0;g<=final;g++){
        fprintf(new_file," %d",(Suma[g]/Licznosc[g]));
    }

}


int main(){
    char Scieszka[100];  
    printf("Podaj sciezke do pliku : ");   
    scanf("%s",Scieszka);    

    FILE* original = fopen(Scieszka,"r");   
    if (original == NULL){
        printf("Blad otwarcia pliku\n");   
        return 1;
    }

    char converted[100];   
    strncpy(converted,Scieszka,strlen(Scieszka)-4);   
    strcat(converted, "_Wyjsciowy.txt"); 

    FILE* new_file = fopen(converted,"w");  
    if (new_file == NULL){
        printf("Blad stworzenia pliku\n");  
        return 1;
    }

    Count_Numbers(original,new_file);
    printf("Done\n");

    fclose(original);   
    fclose(new_file);   

    return 0;   
}   