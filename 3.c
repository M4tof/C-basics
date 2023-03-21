#include <stdio.h>
#include <math.h>
int main(){
    double R,L;
    int n,m;
    L=1;
    printf("Podaj n : ");
    scanf("%d",&n);

    printf("Podaj m : ");
    scanf("%d",&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            L=L*((pow(i,2) + pow(j,2) -1)/(2*i+3*j+4));
            //printf("%lf\n",L);
        }
    R=R+L;
    //printf("R=");
    //printf("%lf\n",R);
    L=1;
    }
    printf("Ostatecznie : ");
    printf("%lf",R);
    return 0;
}
