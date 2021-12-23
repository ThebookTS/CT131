//BookTs
#include <stdio.h>
#include <conio.h>
 
int main()
{
    int a, b, div;
    printf("\nNhap a,b: ");
    scanf("%d%d", &a, &b);
    div=a;
    while(div>=b)
    {
        div-=b; //div=div-b
    }
    printf("\n%d DIV %d = %d", a, b, div);
    getch();
    return 0;
}

