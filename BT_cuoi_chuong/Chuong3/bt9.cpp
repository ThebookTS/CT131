//BookTs
#include<stdio.h>
#include<conio.h>
int main()
{
	int dd,mm,yy;
	int hople=0;
	while(hople==0)
	{
		printf("Nhap ngay:");
		scanf("%d",&dd);
		if(dd>0 && dd<=31) hople=1;
	}
	hople=0;
	while(hople==0)
	{
		printf("Nhap thang:");
		scanf("%d",&mm);
		if(mm>0 && mm<=12) hople=1;
	}
	printf("Nhap nam:");
	scanf("%d",&yy);
	printf("\nIn ngay thang nam theo dang dd/mm/yy la %d/%d/%d",dd,mm,yy);
	getch();
	return 0;
}
