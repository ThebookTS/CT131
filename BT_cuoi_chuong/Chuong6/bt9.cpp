//BookTs
#include "stdio.h"
#include "conio.h"

//Nhap Mang
void NhapMang(int a[100], int n)
{
   for(int i = 0; i<n; i++)
   {
      printf("\tNhap phan tu [%d]: ",i);
      scanf("%d",&a[i]);
   }
}

//Dao mang
void DaoMang(int a[],int n)
{
   for(int i=0;i<n/2;i++)
    {
      int temp=a[i];
         a[i]=a[n-1-i];
         a[n-1-i]=temp; 
   }
}

//Xuat Mang
void XuatMang(int a[100], int n)
{
   for(int i = 0; i<n; i++)
   {
      printf("%4d",a[i]);
   }
}

//Chuong Trinh Chinh
int main()
{
   int a[100],n;
   printf("\n\t\tNhap mang, dao mang va xuat mang mot chieu");
   printf("\nNhap vao n phan tu: ");
   scanf("%d",&n);
   NhapMang(a,n);
   printf("\nMang vua nhap la: ");
   XuatMang(a,n);
   DaoMang(a,n);
   printf("\nMang bay gio la: ");
   XuatMang(a,n);
   getch();
   return 0;
}
