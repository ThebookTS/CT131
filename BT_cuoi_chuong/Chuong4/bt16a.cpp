//BookTs
#include <stdio.h>//cach 1
#include <conio.h>

int main()
{
    int i=0, s=0,n;
    printf("Nhap vao so n:");
    scanf("%d", &n);
    while(i++<n)
        s=s+i;
    printf("Tong la: %d\n", s);
    getch();
    return 0;
}

#include <stdio.h>//cach 2
#include <conio.h>

int main()
{
	int n,S;
	printf("Nhap n: ");
	scanf("%d",&n);
	S = (n*(1 + n))/2;
	printf("Tong cua cac so tu 1 den %d la: %d", n,S);
}
