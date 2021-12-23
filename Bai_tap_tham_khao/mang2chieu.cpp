// Mang 2 chieu la ma tran
// Nhap vao 2 ma tran Do`ng x Co^.t, tinh tong va in ket qua
#include <stdio.h>
int nhapmt (int mt[10][10], int D , int C);
int inmt (int mt[10][10], int D , int C);
int congmt (int mt3[10][10], int mt1[10][10], int mt2[10][10], int D , int C);

int main (){
	int mt1[10][10], mt2[10][10] , mt3[10][10] , D, C;
	printf("Nhap kich thuoc DxC : "); scanf("%d%d",&D,&C);
	printf("Nhap ma tran 1 : \n");
	nhapmt(mt1, D, C);
	printf("Nhap ma tran 2 : \n");
	nhapmt(mt2, D, C);
// In ma tra	
	printf("\nMa tran 1 :\n");
	inmt (mt1,D,C);
	printf("\nMa tran 2 :\n");
	inmt (mt2,D,C);
// Cong 2 ma tran
	congmt(mt3,mt1,mt2,D,C);
	printf("\nTong mt1 + mt2 = \n");
	inmt(mt3,D,C);
}

int nhapmt (int mt[10][10], int D , int C)	{
	int i,j;
	for (i=0;i<D;i++)
		for (j=0;j<C;j++) {
			printf("Nhap phan tu [%d][%d] = ",i,j);
			scanf("%d",&mt[i][j]);
		}
}

int inmt (int mt[10][10], int D , int C) {
	int i,j;
	for (i=0;i<D;i++) {
		for (j=0;j<C;j++) 
			printf("%4d",mt[i][j]);
		printf("\n");
	}
}

int congmt (int mt3[10][10], int mt1[10][10], int mt2[10][10], int D , int C) {
	int i, j;
	for (i=0;i<D;i++) 
		for (j=0;j<C;j++) 
			mt3[i][j] = mt1[i][j] + mt2[i][j];
}
