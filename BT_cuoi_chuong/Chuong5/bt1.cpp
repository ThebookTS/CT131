//BookTs
#include<conio.h>
#include<stdio.h>
void solonnhat(int a,int b) // hàm tìm s? l?n nh?t trong 2 s?
{
	if(a>b)
	{
		printf("so lon nhat la ; %d\n",a);
	}
	else
	{
		printf("so lon nhat la: %d\n",b);
	}
}
main()
{
int a,b;
printf("nhap a va b\n");
scanf("%d %d",&a,&b);
solonnhat(a,b);
getch();
}
