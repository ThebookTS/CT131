#include <stdio.h>
#include <string.h>
int main (void) {
	char *a,*b;
	a = new char[50];
	b = new char[50];
	printf("Nhap ho ten: "); gets(a);
	// Cat bo khoang trang khong can thiet
	int i = 0 , j = 0 ;
	while (*(a+i)==' ') i++;	// Di chuyen qua cac khoang trang o dau chuoi
	while (*(a+i)!='\0') {
		if (*(a+i)!=' ') {
			*(b+j) = *(a+i);
			j++; i++;
		}
		else {
			*(b+j) = *(a+i); j++; i++;
			while (*(a+i)==' ') i++;
		}
	*(b+j) = '\0'; // Ket thuc chuoi b , j = strlen(b);
	}
	// Cat khoang trang cuoi chuoi
	j--;
	while (*(b+j)==' ') j--;
	j++;
	*(b+j) = '\0';
	
	printf("\nHo ten sau khi cat khoang trang: %s",b); printf("./.");
}
