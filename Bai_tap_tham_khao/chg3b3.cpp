#include <stdio.h>
#include <math.h>
int main() {
	float a,b,c,cv,dt,p;
	printf("Nhap ba canh a b c : "); scanf("%f%f%f",&a,&b,&c);
	if ((a+b>c)&&(a+c>b)&&(b+c>a)) {
		cv = a+b+c;
		p = cv/2;
		dt = sqrt(p*(p-a)*(p-b)*(p-c));
		printf("\nChu vi = %f",cv);
		printf("\nDien tich = %f",dt);
	}
	else
		printf("Khong tao thanh tam giac");
}

