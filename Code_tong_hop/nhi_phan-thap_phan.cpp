//BookTs

//chuyen nhi phan sang thap phan
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
 
void main ()
{
    int a[10];
    int b;
    printf("\nChuong trinh chuyen co so 2 sang co so 10\n");
    printf("\n Nhap so nguyen co so 2 voi vi tri thu tu sau: \n");
    for(int i=0;i<10;i++)
    {
        printf("\na[%d]=",i+1);
        scanf("%d",&a[i]);
 
    }
    b=0;
    if(a[0]==0)
    {
        for (int i=1;i<10;i++)
        {
            if(a[i]==1)
                b+=pow((float)2,9-i);
        }
    }
    else
    {
        b+=-pow((float)2,(int)9);
        for (int i=1;i<10;i++)
        {
            if(a[i]=='1')
                b+=pow((float)2,9-i);
        }
    }
    printf("\n Chuyen thanh co so 10 la: %d",b);
    getch();
}
