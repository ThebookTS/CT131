//BookTs
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
int main()
{
    int a,b,c,d;
    printf("\nNhap a,b: ");
    scanf("%d%d", &a, &b);
    c=a;
    d=b;
    while (a!=b)
    {
        if(a>b) a-=b;
        else    b-=a;
    }
    printf("\nUCLN=%d   BCNN=%d", a, c*d/a);
    getch();
    return 0;
}
