//BookTs
#include<stdio.h>
#include<math.h>
int main()
{
	char r;
	int a, n, S,b;
	printf("chon phuong thuc gui: ");//theo hinh thuc lai don
	printf("\n1. Gui khong ki han");
	printf("\n2. Gui co ki han");
	scanf("%c", &r);
	switch (r)
	{
		case '1':
			printf("\nGui khong ki han");
			printf("\nNhap so tien muon gui\n");
			scanf("%d", &a);
			printf("\nNhap vao so thang: \n");
			scanf("%d", &n);
			S = a*(1 + n*2.4*0.01);
			printf("\nSo tien ca von lan lai la: %d", S);
			break;
	case '2':
			printf("\nGui co ki han");
			printf("\nNhap so tien muon gui\n");
			scanf("%d", &a);
			printf("\nNhap vao so thang: \n");
			scanf("%d", &n);
			b = n / 3;
			S = a*(1 + b*4*0.01);
			printf("\nSo tien ca von lan lai la: %d", S);
	
}
	return 0;
}

/*
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
int main()
{
    int n;
    float v,t;
    printf("\nMoi bn nhap tien von va thoi gian gui (thang): ");
    scanf("%f%d", &v, &n);
    while (n!=0)
    {
        if(n%3==0)
        {
            v*=(1+0.045);
            n-=3;
        }
        else
        {
            v*=(1+0.004);
            n-=1;
        }
    }
    printf("\nTong ca von va lai la: %.2f",v);
    getch();
    return 0;
}
*/
