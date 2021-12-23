//BookTs
#include <stdio.h>
 
int main()
{
    float a, b, c;
    printf("\nNhap 3 so a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    float Max = a;
    if(b > Max)
	{
        Max = b;
    }
    if(c > Max)
	{
        Max = c;
    }
 	printf("so lon nhat la: %f", Max);
 	return 0;

}
