#include <stdio.h>
#include <conio.h>
int main (void){
	int N , i , j , *a ; //a[10]
	printf("Nhap N = "); scanf("%d",&N);
	// Cap phat vung nho cho A
	a = new int[N]; // <ten con tro> = new <kieu du lieu>[so phan tu]
		
	for (i=0;i<N;i++) {
		printf("Nhap phan tu a[%d] = ",i);
		scanf("%d",(a+i)); //&a[i]);
}
	printf("\n\n Mang vua nhap : ");
	
	for (i=0;i<N;i++) 
		printf("%d   ", *(a+i));
		
	delete a;
	int b[10]={1,2,3,4,5,6,7,8,9,0};
	printf("\n\n Noi dung mang b : ");
	
	for (i=0;i<10;i++) 
//		printf("%d   ", *(b+i));
		printf("%d   ", b[i]);	
}
