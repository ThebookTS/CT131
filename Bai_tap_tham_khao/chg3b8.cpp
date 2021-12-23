#include <stdio.h>
#include <math.h>
int main() {
	float T,L,H,tb;
	printf("Nhap diem 3 mon T L H : ");
	scanf("%f%f%f",&T,&L,&H);
	if ( (T>=0)&&(T<=10)&&(L>=0)&&(L<=10)&&(H>=0)&&(H<=10) ) {
		tb = (T+L+H)/3;
		printf("\nDiem trung binh = %.2f ",tb);
	}
	else
		printf("\nDiem khong hop le");
}
