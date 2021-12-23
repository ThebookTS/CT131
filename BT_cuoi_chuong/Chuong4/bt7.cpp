//BookTs
#include<stdio.h>
#include<math.h>

int main()
{
	char r;
	int a, n, S,b;
	printf("chon phuong thuc gui: ");
	printf("\n1. Gui khong ki han");
	printf("\n2. Gui co ki han\n");
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

