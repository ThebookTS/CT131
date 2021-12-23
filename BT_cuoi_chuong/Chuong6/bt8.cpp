//BookTs
#include <stdio.h>
#include <conio.h>
void Nhap(int a[],int N)
{ int i;
  for(i=0;i<N;i++)
  {
   printf("Phan tu thu %d=\t",i); scanf("%d",&a[i]);
  }
}
void InMang(int a[],int N)
{
 int i;
 for(i=0;i<N;i++)   printf("%d ",a[i]);
 printf("\n");
}
void Tong(int a[],int N)
{
 int i,S;
 { S=0;
   for(i=0;i<N;i++)
   if(a[i]<0)       S+=a[i]*a[i];
 } printf("\nTong binh phuong cua cac so am co trong mang la: %d",S);
}
int main()
{
 int a[20],i,N;
 printf("Nhap so luong phan tu thuc te cua mang: ");   scanf("%d",&N);
 Nhap(a,N);  printf("Mang vua nhap la: ");
 InMang(a,N);
 Tong(a,N);
 getch();
 return 0;
}
