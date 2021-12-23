//BookTs
#include<stdio.h> //thu vien chua ham printf,scanf
#include<conio.h> //thu vien chua ham getch
#include<math.h>

int main(){
    int a,b,c,cv;
    float p,s;
    printf("\nNhap vao do dai 3 canh cua tam giac: ");
    scanf("%d%d%d",&a,&b,&c);
    cv = a+b+c;
    p = cv / 2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("\nChu vi cua tam giac la: %d",cv);
    printf("\nDien tich cua tam giac la: %.2f",s);
    getch();
    return 0;
}

