//BookTs
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int k=0;
    int n;
    printf("Nhap gia tri n:");
    scanf("%d",&n);
    while (pow(2,k) <n) k++;
	printf("So nguyen duong k la: %d",k-1);
   getch();
   return 0;
}
