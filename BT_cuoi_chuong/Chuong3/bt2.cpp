//BookTs
#include<stdio.h> //thu vien chua ham printf,scanf
#include<conio.h> //thu vien chua ham getch

const double pi = 3.14159254;
int main(){
    int r;
    float cv,s;
    printf("\nNhap vao ban kinh R cua hinh tron: ");
    scanf("%d",&r);
    cv = r*2*pi;
    s = pi*r*r;
    printf("\nChu vi cua hinh tron ban kinh %d la: %.2f",r,cv);
    printf("\nDien tich cua hinh tron ban kinh %d la: %.2f",r,s);
    getch();
    return 0;
}

