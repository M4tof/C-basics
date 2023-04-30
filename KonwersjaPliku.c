#include <stdio.h>   
#include <string.h>   
#include <stdlib.h> 
#include <math.h>

void convertFile(FILE* origianl,FILE* new_file){
    char line[100];
    int asterisk_levels[100]={0};
    int current =0;
    
    while(fgets(line,100,origianl)!=NULL){
        int i=0;
        while(line[i]=='*'){
            i++;               
        }

        int level=i-1;

        while (current > level){
            asterisk_levels[current]=0;
            current--;
        }

        current=level;

        asterisk_levels[level]++;
    
        for (int g=0;g<level;g++){
            fprintf(new_file,"  ");
        }
        for (int j = 0; j < level; j++) {
            fprintf(new_file, "%d.", asterisk_levels[j]);
        }
        fprintf(new_file, "%d. %s", asterisk_levels[level], line + i);
    }
}

void convertFile2(FILE* origianl,FILE* new_file){
    char line[100];
    int asterisk_levels[100]={0};
    int current =0;
    
    while(fgets(line,100,origianl)!=NULL){
        int i=0;
        while(line[i]=='*'){
            i++;
        }

        int level=i-1;

        while (current > level){
            asterisk_levels[current]=0;
            current--;
        }

        current=level;

        asterisk_levels[level]++;
    
        for (int g=0;g<level;g++){
            fprintf(new_file,"  ");
        }
        switch (level)
        {
        case 0:
            fprintf(new_file, "%c. %s", (64+asterisk_levels[level]), line + i);
            break;
        case 1:
            fprintf(new_file, "%d. %s", asterisk_levels[level], line + i);
            break;
        case 2:
            fprintf(new_file, "%c. %s", (96+asterisk_levels[level]), line + i);
            break;
        default:
            if(level%2==1){
                    for(int it=0;it<(level/2);it++){
                        fprintf(new_file,"(");
                    }
                    fprintf(new_file,"%d",asterisk_levels[level]);
                    for(int it=0;it<(level/2);it++){
                        fprintf(new_file,")");
                    }
                fprintf(new_file, " %s",line + i);
            }
            else{
                for(int it=0;it<(level/2)-1;it++){
                        fprintf(new_file,"(");
                    }
                fprintf(new_file,"%c",(96+asterisk_levels[level]));
                for(int it=0;it<(level/2)-1;it++){
                        fprintf(new_file,")");
                    }            
                fprintf(new_file, " %s",line + i);


            }
            break;
        }
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
    strcat(converted,"PoKonwersji.txt");  

    FILE* new_file = fopen(converted,"w");  
    if (new_file == NULL){
        printf("Blad stworzenia pliku\n");  
        return 1;
    }

    int Choice;
    printf("Wybierz format konwersji\n");
    printf("[1]Liczbowa, [2]Wyrazowa : ");
    scanf("%d",&Choice);
    
    if(Choice==1){
    convertFile(original, new_file);   
    printf("Zakonczono pomyslnie.\n");
    }
    
    if(Choice==2){
        convertFile2(original, new_file);
        printf("Zakonczono pomyslne.\n");
    }

    fclose(original);   
    fclose(new_file);   

    return 0;   
}   