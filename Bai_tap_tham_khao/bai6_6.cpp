#include<stdio.h>
#include<conio.h>
// Yeu cau: Sinh vien chuyen doan lenh In ma tran thanh 1 chuong trinh con
int main(){
	int m,n,mt[10][10],cv[10][10];
	printf("nhap so dong m, so cot n : ");
	scanf("%d%d",&m,&n);
	printf("\nnhap ma tran : \n");
	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++) {
			printf("\t mt[%d][%d] = ",i,j); scanf("%d",&mt[i][j]);
		}
//  Chuyen vi ma tran
	for (i=0;i<m;i++)
		for (j=0;j<n;j++) 
			cv[j][i]=mt[i][j];
//  In ma tran da nhap
	printf("\nMa tran da nhap : \n");
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) 
			printf("%4d",mt[i][j]);
		printf("\n");
	}
//  In ma tran da chuyen vi
	printf("\nMa tran da chuyen vi : \n");
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) 
			printf("%4d",cv[i][j]);
		printf("\n");
	}
}
