//BookTs
#include<stdio.h>
#include<conio.h>
int main(){
    int r1,r2,r3;
    float r;
    printf("\nNhap gia tri cac dien tro R1,R2,R3:");
    scanf("%d%d%d",&r1,&r2,&r3);
    r=(float)(r1*r2*r3)/(r1*r2+r2*r3+r1*r3);
    printf("\nTong tro R la %f",r);
    getch();
    return 0;
}
