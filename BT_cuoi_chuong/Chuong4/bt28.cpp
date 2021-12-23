//BookTs
#include <stdio.h>
#include <conio.h>
#include <math.h>

int n;
double a;
double e = 0.000001l; /* hang so cho truoc */
double mu(double a, int somu) /* tao ham tach mu */
{
	if (somu==0) return 1; 
	else return pow(a,somu-1)*a;
}
double newton(double x1) // ham newton
{
	double x2;
	x2 = (x1*(n-1) + a/mu(x1,n-1)) / n; 
	if (fabs(pow(x2,n)-a) < e) return x2; 
	else return newton(x2); 
}
int main()
{
	printf("Chuong trinh tinh can bac N cua a \n");
	printf("A = "); scanf("%lf", &a);
	printf("N = "); scanf("%d", &n);
	int c=(int)a;
	printf("Can bac %d cua %d la %lf", n, c, newton(a/n)); // gia tri ham newton
	getch();
	return 0;
}
