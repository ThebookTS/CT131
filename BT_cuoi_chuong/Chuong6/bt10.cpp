//BookTs
#include <stdio.h>
#include <conio.h>
void Tong2MaTran(int a[][100],int b[][100],int c[][100],int m,int n);
main()
{
int a[100][100],b[100][100],c[100][100],i,j,m,n;
printf("\n Nhap vao hai so m va n: ");
scanf("%d%d",&m,&n);
printf(" Nhap tung phan tu cua ma tran a co %d hang va %d cot:\n\t",m,n);
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("\t");
}
printf("\r Nhap tung phan tu cua ma tran b co %d hang va %d cot:\n\t",m,n);
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
scanf("%d",&b[i][j]);
printf("\t");
}
Tong2MaTran(a,b,c,m,n);
printf("\r Ma tran c la tong cua 2 ma tran a va b.\n");
printf(" => Ma tran c la:\n\t");
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
printf("%5d",c[i][j]);

}
getch();
return main();
}
void Tong2MaTran(int a[][100],int b[][100],int c[][100],int m,int n)
{
int i,j,k;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
c[i][j]=a[i][j]+b[i][j];
}
