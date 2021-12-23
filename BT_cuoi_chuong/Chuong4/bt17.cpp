//BookTs

#include <stdio.h>
#include <conio.h>
#include <math.h>
 
int main()
{
    int n, max=0, a, vt;
    printf("\nMoi bn nhap n: ");
    scanf("%d", &n);
    for (int i=1; i<=n ; i++)
    {
        printf("\nNhap phan tu thu %d: ", i);
        scanf("%d",&a);
        if(a>max)
        {
            max=a;
            vt=i;
        }
    }
    printf("\nGia tri Max=%d o vi tri thu %d", max, vt);
    getch();
    return 0;
}
