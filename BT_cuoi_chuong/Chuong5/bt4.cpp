//BookTs
#include<conio.h>
int tong1(int so)
{
    int i,tong=0;
    for (i=0;i<=so;i++)
    tong+=i;
    return tong;
}
int tong2(int so)
{
    int k, tong=0;
    while (so)
    {
          k=so%10;
          tong+=k;
          so/=10;
    }
    return tong;
}
int main()
{
    int n;
    do
    {
	printf("Moi nhap 1 so nguyen duong bat ky:");
    scanf("%d",&n);
    }while (n<0);
    printf("Tong cac chu so la: %d\n",tong1(n));
    printf("Tong cac so be hon %d la: %d",n,tong2(n));
    getch();
    return 0;
} 
