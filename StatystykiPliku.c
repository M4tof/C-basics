#include <stdio.h>   
#include <string.h>   
#include <stdlib.h> 
#include <math.h>


void Count_Numbers(FILE* origianl,FILE* new_file){
    char line[1000];
    double Suma[1000]={0};
    int Licznosc[1000]={0};
    int maxim=0;

    while(fgets(line,100,origianl)!=NULL){
        int current =0;
        int position =0;
        char* iteam = strtok(line," ");
        
        while (iteam != NULL){
            current = atoi(iteam);
            
            Suma[position]+=current;
            Licznosc[position]++;
            position++;
            
            iteam = strtok(NULL, " ");
        }
        if (position>maxim){
            maxim=position;
        }
    }
    fprintf(new_file,"SUMA:");
    printf("SUMA:");
    for(int i=0;i<maxim;i++){
        int A_int;
        A_int = (int) Suma[i];
        fprintf(new_file," %d",A_int);
        printf(" %d",A_int);
    }
    fprintf(new_file,"\n");
    printf("\n");

    fprintf(new_file,"SREDNIA:");
    printf("SREDNIA:");
    for(int g=0;g<maxim;g++){
        fprintf(new_file," %.2lf",(Suma[g]/Licznosc[g]));
        printf(" %.2lf",(Suma[g]/Licznosc[g]));
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