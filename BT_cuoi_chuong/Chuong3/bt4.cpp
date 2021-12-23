// BookTs	
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main()
{
	int a,x;
	do
	{
		system("cls");
		printf("nhap a: ");
		scanf("%d",&a);
		printf("nhap x: ");
		scanf("%d",&x);
	} while ((a<0)||(x<0));
	printf("gia tri cua loragit co so %d cua %d là %f", a, x, log(x)/log(a));
	return 0;
}
