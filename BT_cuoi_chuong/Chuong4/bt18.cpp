//BookTs

//in day fibonacci
#include<stdio.h>

int fibonacci(int n) 
{
    int f0 = 0;
    int f1 = 1;
    int fn = 1;
    int i;
 
    if (n < 0) 
	{
        return -1;
    } 
	else if (n == 0 || n == 1) 
	{
        return n;
    } 
	else 
	{
        for (i = 2; i < n; i++) 
		{
            f0 = f1;
            f1 = fn;
            fn = f0 + f1;
        }
    }
    return fn;
}

int main() {
 int i;
    printf("10 so dau tien cua day so Fibonacci: \n");
    for (i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
}
/*
#include <stdio.h>
#include <conio.h>
#include <math.h>
 
int main()
{
    int n, f, f1, tam=1;
    printf("\nNhap n: ");
    scanf("%d", &n);
    for (int i=2; i<=n ; i++)
    {
        f1=tam;
        if(i<=2) f=1;
        else
        {    
            tam=f;   //f(moi) = f(la f n-1)+f1 (f n-2)
            f+=f1;
       
        }
        printf(",%d ",f);
    }
    getch();
    return 0;
}*/

/*
#include<stdio.h>  
#include<conio.h>  
// khai bao ham indayFibonacci
void indayFibonacci(int n){  
    static int n1=0,n2=1,n3;  
    if(n>0){  
         n3 = n1 + n2;  
         n1 = n2;  
         n2 = n3;  
         printf("%d ",n3);  
         indayFibonacci(n-1);  
    }  
}  

// ham main de in day Fibonacci
int main(){  
    int n;  

    printf("Ban hay nhap so phan tu trong day Fibonacci: ");  
    scanf("%d",&n);  

    printf("Hien thi day Fibonacci tren man hinh\n\n");  
    printf("%d %d ",0,1);  
    indayFibonacci(n-2);  //n-2 boi vi 2 phan tu dau tien da duoc in 
    getch();  
}  
*/

