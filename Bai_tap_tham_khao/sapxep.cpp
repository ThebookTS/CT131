// Nhap vao 1 mang gom N phan tu
// Sap xep theo thu tu tang day
#include <stdio.h>
#include <conio.h>
int main (){
	int N, mang[100], tam;
	printf("Nhap so N = ");	scanf ("%d",&N);
	printf("\nNhap mang: \n");
	for (int i=0;i<N;i++) {
		printf("Phan tu %d = ",i);
		scanf("%d",&mang[i]);
	}
// Sap xep day so
	int i,j;
	for (i=0;i<N-1;i++)
		for (j=i+1;j<N;j++) 
			if (mang[i]>mang[j]) {
				tam = mang[i];	mang[i] = mang[j];	mang[j] = tam;
			}
//In mang da sap xep
	printf("\nMang sau khi sap xep :");
	for (i=0;i<N;i++)
		printf("%5d",mang[i]);					
}

