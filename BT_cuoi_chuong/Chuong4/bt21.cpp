//BookTs
#include <conio.h>
#include <stdio.h>

main()
{
	float a,tb=0,k=0;
	printf("Nhap day so thuc ket thuc bang -1 \n(Moi so thuc phan biet voi nhau bang phim Enter):\n" );
	scanf("%f",&a);fflush(stdin);
	while(a!=-1)
	{
		tb=tb+a;
		k++;
		scanf("%f",&a);
		fflush(stdin);
	}
	printf("Gia tri trung binh: %.2f",tb/k);	
	getch();
	return 0;
}
