//BookTs
#include<stdio.h>

int main()
{
	float b;
	int i,R;
	int dientro[20]={10,22,33,47,68,100,220,330,680,1000,2200,3300,4700,6800,22000,33000,47000,68000,680000,1000000};
	printf("Nhap R: ");
	scanf("%d",&R);
	for (i=0;i<=20;i++)
	{
		b=R/dientro[i];
		if(b>=0.95)
		printf("\nGia tri la %d",dientro[i]);
		else 
		printf("\nkhong co gia tri");
	}
	return 0;
}


