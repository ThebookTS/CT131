//BookTs
#include "stdio.h"
#include "conio.h"
int main()
{
	char ktu;
	printf("Nhap vao mot ky tu: ");
	scanf("%c",&ktu);
	if (ktu>='a'&&ktu<='z') 
		printf("Chu cai in thuong");
	else if (ktu>='A'&& ktu<='Z') 
		printf("Chu cai in hoa");
	else if ( ktu>='1'&& ktu<='9') 
		printf("Chu so");
	else 
		printf("Ki tu dac biet");
	getch();
	return 0;
}
