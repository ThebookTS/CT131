#include<stdio.h>
#include<conio.h>

int main(){
	int N,m[20],S=0;
	printf("nhap so phan tu N = ");
	scanf("%d",&N);
	printf("\nnhap mang : \n");
	
	for (int i=0;i<N;i++) {
		printf("\t m[%d] = ",i); scanf("%d",&m[i]);
		}
//  Tinh tong binh phuong cac so am
	for (int i=0;i<N;i++) 
		if (m[i]<0) S += m[i]*m[i];
//  In ket qua
	printf("\nTong binh phuong cac so am la S = %d ",S);
}
