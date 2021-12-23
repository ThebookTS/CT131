//BookTs

#include <stdio.h>
 
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap vao phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
	}
}
int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}
 
int min(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}
int main()
{
    int a[1000];
    int n;
    int sum=0;
    printf("\nNhap n = ");
    scanf("%d", &n);
    nhap(a, n);
    for (int i = 0; i < n; i++)
    {
    sum=sum+a[i];
    }
    printf("\nGia tri lon nhat cua mang la = %d", max(a, n));
    printf("\nGia tri nho nhat cua mang la = %d", min(a, n));
    printf("\nTong gia tri cua cac phan tu trong mang la = %d", sum);
    return 0;
}
