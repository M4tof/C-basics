#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool ProgEnd = false;

typedef struct Towar
{
    char NazwaTowaru[50];
    int LiczbaSztuk;
    float CenaSztuki;
}Towar;

struct Towar TablicaTowarow[50];
int NuminTab = 0;

void Adder(int Place){
    char Name[50];
    int Liczba;
    float Price;
    printf("Podaj Nazwe towaru : ");
    scanf("%s", Name);
    printf("Podaj Liczbe Sztuk towaru : ");
    scanf("%d",&Liczba);
    printf("Podaj Cene dla sztuki towaru : ");
    scanf("%f",&Price);

    strcpy(TablicaTowarow[Place].NazwaTowaru, Name);
    TablicaTowarow[Place].LiczbaSztuk = Liczba;
    TablicaTowarow[Place].CenaSztuki = Price;

    free(Name);
    free(Liczba);
    free(Price);
}

void submain(){
    while(!ProgEnd){
        
        char Input;

        printf("Input : ");

        scanf(" %c",&Input);

        if( Input=='q'  || Input=='Q'){
            ProgEnd=true;
            break;
        }
        
        if (Input=='n' || Input=='N')
        {
            if(NuminTab >= 50){
                printf("Tab is full");
            }
            else{
                Adder(NuminTab);
                NuminTab++;
            }
        }
        
        if (Input=='w' || Input=='W')
        {
            for(int i=0;i<NuminTab;i++){
                printf("Towar %d: %s, %d available, price per one %.2f\n",i+1,TablicaTowarow[i].NazwaTowaru,TablicaTowarow[i].LiczbaSztuk,TablicaTowarow[i].CenaSztuki);
            }
        }

        if (Input=='r' || Input=='R')
        {
            double Suma;
            for(int i=0;i<NuminTab;i++){
                Suma+=(TablicaTowarow[i].CenaSztuki * TablicaTowarow[i].LiczbaSztuk);
                }
            printf("Suma wartosci towarow w tablicy = %lf\n",Suma);
        }

    }
}

int main(){
    printf("[N-new, W-Equipment, R-Sum of inventory, Q-quit]\n");
    submain();
    printf("Closing now");

    return 0;
}
