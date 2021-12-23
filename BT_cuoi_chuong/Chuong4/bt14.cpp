//BookTs
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ktu;
	printf("Nhap  mot ky tu trong he thap luc phan: ");
	scanf("%c",&ktu);
	system("cls");
	switch(ktu)
	{
		case 'A': printf("Ky tu vua nhap co gia tri la 10"); break;
		case 'B': printf("Ky tu vua nhap co gia tri la 11"); break;
		case 'C': printf("Ky tu vua nhap co gia tri la 12"); break;
		case 'D': printf("Ky tu vua nhap co gia tri la 13"); break;
		case 'E': printf("Ky tu vua nhap co gia tri la 14"); break;
		case 'F': printf("Ky tu vua nhap co gia tri la 15"); break;
		default:
		{
			if((ktu>='0')&&(ktu<='9'))
				printf("ky tu vua nhap co gia tri la %c",ktu);
			else
				printf("He thap luc phan khong dung ky so nay");
		}
	}
	getch();
	return 0;
}

