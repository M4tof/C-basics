#include <stdio.h> //must have
int main(){ 
    int Rang;
    printf("Podaj gorna granice : ");
    scanf("%d",&Rang);

    for (int i=1;i<=Rang;i++){ //Od 1 do R
    int Sum=0;
        for(int dz=1;dz<i;dz++){

            if (i%dz == 0){
                Sum+=dz;

            }
        }
        //printf("%d,%d\n",i,Sum);
        if (i!=Sum){
            int Sum2=0;
            for (int dz2=1;dz2<Sum;dz2++){
                if (Sum%dz2 == 0){
                    Sum2+=dz2;
                }
            }
            if (i == Sum2){
                printf("%d,%d\n",i,Sum);
            }
        }
    }
    return 0;
}
