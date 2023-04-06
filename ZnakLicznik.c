#include <stdio.h>


int Counter(char* Linia,char Znak){
    int C =0;
    for(int i=0;Linia[i]!='\0';i++){
        if(Linia[i] == Znak){
            C++;
        }
    }

    return C;
}

int main(){
    char Szukany;
    printf("Podaj szukany znak : ");
    Szukany = getchar();

    char Scieszka[100];
    printf("Podaj scieszke do pliku : ");
    scanf(" %s",Scieszka);

    printf("\n");
    
    FILE *Plik;
    Plik = fopen(Scieszka,"r");
    
    if( Plik == NULL ) 
    {
    printf("Blad otwarcia pliku");
    return 1;
    }

    char mem[100];
    int Licznik=0;
    while(fscanf(Plik,"%s",mem) !=EOF){
        Licznik+=Counter(mem,Szukany);
    }

    printf("Znaleziono %d wystapien znaku '%c' w pliku o scieszce '%s'\n",Licznik,Szukany,Scieszka);

    fclose(Plik);
    return 0;
}