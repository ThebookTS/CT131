//BookTs
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int tong=0;
	int du;
	do
	{
		printf("\nNhap vao so nguyen 3 chu so: ");
		scanf("%d",&n);
		if(n<100||n>999)
		{
			printf("\nSo ban vua nhap khong hop le!. Nhan Enter de nhap lai!");
			getch();
		}
	}while(n<100||n>999);
	do
	{
		tong+=n%10;
		n/=10;
	}while(n);
	do
	{       
		du=tong%3;
		if(du==0)
		printf("\n\tSo ban vua nhap chia het cho 3");
		else
		printf("\n\tSo ban vua nhap khong chia het cho 3");
	}while(0);
	getch();
	return 0;
}
