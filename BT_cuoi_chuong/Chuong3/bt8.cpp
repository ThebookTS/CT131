//BookTs
#include<stdio.h>
#include<conio.h>
int main()
{
	 float toan,ly,hoa;
	 int hople=0;
	 while(hople==0)
	 {
		printf("\nNhap diem mon Toan:");
		scanf("%f",&toan);
		if(toan>=0 && toan<=10) hople=1;
	}
	hople=0;
	while(hople==0)
	{
		printf("\nNhap diem mon Ly:");
		scanf("%f",&ly);
		if(ly>=0 && ly<=10) hople=1;
	}
	hople=0;
	while(hople==0)
	{
		printf("\nNhap diem mon Hoa:");
		scanf("%f",&hoa);
		if(hoa>=0 && hoa<=10) hople=1;
	 }
	 printf("\nDiem trung binh la: %.2f",(toan+ly+hoa)/3);
	 getch();
	 return 0;
}
