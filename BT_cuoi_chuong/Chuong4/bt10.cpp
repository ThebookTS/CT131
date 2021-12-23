//BookTs
#include<stdio.h>

int main()
{
	int a,b,c,t;
	printf("Nhap so dien ke cu: ");
	scanf("%d",&a);
	printf("Nhap so dien ke moi: ");
	scanf("%d", &b);
	c = b - a;
	if (c>50)
	{
		if (c>100)
		{
			t = 50*700+100*910+(c-150)*1200;
			printf("So tien phai tra trong dinh muc la: %d\n",50*700);
			printf("So tien phai tra trong dinh muc la: %d\n",100*910+(c-150)*1200);
			printf("Tong so tien phai tra la %d", t+1000);
		}
		else 
		{
			t = 50*700+ (c-50)*910;
			printf("So tien phai tra trong dinh muc la: %d\n",50*700);
			printf("So tien phai tra trong dinh muc la: %d\n",(c-50)*910);
			printf("Tong so tien phai tra la %d", t+1000);
		}
	}
	else 
	{
		t = 700*c;
		printf("So tien phai tra trong dinh muc la: %d\n", t);
		printf("Tong so tien phai tra la %d", t+1000);
	}	
	return 0;
}


