//BookTs
#include <stdio.h> 
#include <math.h> 
int main()
{
    float a, b, c, S, CV, p;
    printf("Nhap a = ");
    scanf("%f",&a);
    printf("Nhap b = ");
    scanf("%f",&b);
    printf("Nhap c = ");
    scanf("%f",&c);
 	if ((a + b > c) || (a + c > b) || (b + c > a))
 	{
	    CV = a+b+c;
	    printf("Chu vi = %f\n",CV);
	    p = CV/2;
	    S = sqrt(p*(p-a)*(p-b)*(p-c));
	    printf("Dien tich = %f",S);
    }
    else 
	{ 
		printf (" Khong tao thanh tam giac. ");
	}
    return 0;
}
