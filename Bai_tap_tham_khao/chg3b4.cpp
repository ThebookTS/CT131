#include <stdio.h>
#include <math.h>
int main() {
	float a,x,kq;
	printf("Nhap a , x : ");
	scanf("%f%f",&a,&x);
	if ( (x>0)&&(a>0)&&(a!=1) ) {
		kq = log(x)/log(a);
		printf("\nlog(%.3f)/log(%.3f) = %.2f",x,a,kq);
//		printf("\n%10f%10f%10f",a,x,kq);
	}
	else
		printf("\nSo nhap khong hop le");
}
