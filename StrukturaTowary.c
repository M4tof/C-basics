#include <stdio.h>

typedef struct Towar_t Towar;
typedef struct TablicaTowarow_t TablicaTowarow;

typedef struct Towar_t
{
    char NazwaTowaru;
    int LiczbaSztuk;
    int Cena1Sztuki;
};





int main(){
    TablicaTowarow A[50];

    Towar B;
    B.Cena1Sztuki=2137;
    B.LiczbaSztuk=2;
    B.NazwaTowaru="Abba";

    

    return 0;
}