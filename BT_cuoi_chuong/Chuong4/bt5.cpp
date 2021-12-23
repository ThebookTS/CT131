//BookTs
#include<stdio.h>
#include<conio.h>
int main()
{
char r;
int a, b;
	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);
	fflush (stdin);	//xóa ký tu enter trong vung dem truoc khi nhap phép toán
	printf("Nhap vao mot ky tu + - * / : ");
	scanf("%c", &r);
	switch(r)
	{
		case '+':
		printf("Tong cua hai so %d, %d la: %d", a, b, a+b);	break;
		case '-':
		printf("Hieu cua hai so %d, %d la: %d", a, b, a-b);	break;
		case '*':
		printf("Tich cua hai so %d, %d la: %d", a, b, a*b);	break;
		case '/':
		printf("Thuong cua hai so %d, %d la: %d", a, b, a/b);
	}
	getch();
	return 0;
}

