//BookTs
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e
int main()
{
	float a,x0,x1,x2; char TL;
	printf("nhap so duong a = ");
	scanf("%f", &a);
	x0=(1+a)/2;
	do 
	{
		x1=x0;
		x2=(x0+a/x0)/2;
		x0=x2;
	}
	while (fabs((x2-x1)/x1)); // fabs lay tri tuyet doi
	printf("\nGia tri can bac 2 cua %.2f la %.2f", a,x2);
	getch ();
	return 0;
}


