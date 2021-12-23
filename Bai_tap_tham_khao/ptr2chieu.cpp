//Chuong trinh mau: ca'ch dung con tro 2 chieu
#include <stdio.h>
#include <conio.h>
void inmatran (int **a, int N , int M);
int main (void) {
	int N , M , i , j , **a ; // a la con tro 2 chieu
	printf("Nhap so dong \tN = "); scanf("%d",&N);
	// Cap phat N do`ng cho ma tran a
	// Mo^~i do`ng la` 1 con tro
	a = new int*[N];  
	printf("Nhap so cot \tM = "); scanf("%d",&M);	
	// Cap phat vu`ng nho*' : Moi do`ng co' M phan tu
	for (i=0;i<N;i++)
		*(a+i) = new int[M];

	// Nhap ma tran
	printf("\n\nNhap ma tran : \n");
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			printf("\nNhap phan tu a[%d][%d] = ",i,j);
			scanf("%d",(*(a+i)+j));
		}
	}
	// In ma tran
	printf("\nMa tran vua nhap : \n");
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) 
			printf("%d   ",*(*(a+i)+j));
		printf("\n");
	}
	
	printf("\nIn ma tran bang chuong trinh con : \n");
	inmatran(a,N,M);	
	//giai phong vung nho cap cho ma tran a
	for (i=0;i<N;i++)
		delete *(a+i);  // delete tung phan tu da cap phat cho con tro (a+i)
	delete a;			// delete con tro a
}

// Chuong trinh con inmatran
void inmatran (int **a, int N , int M) {
	int i , j ;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) 
			printf("%d   ",*(*(a+i)+j));
		printf("\n");
	}
}
