//BookTs
#include <stdio.h>
#include <conio.h>
 
int main()
{
    int n, dem=1;
    printf("\nNhap n: ");
    scanf("%d", &n);
    while(n/10!=0)
    {
        n/=10; // Neu n/10 khac 0 thi tach bo 1 so cuoi cua n
        dem++; //ap dung tinh chat so nguyen
    }
    printf("\nso chu so cua n la %d", dem);
    getch();
    return 0;
}
