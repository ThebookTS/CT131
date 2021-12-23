#include<stdio.h>
#include<conio.h>
// Bai tap 6.13
// Yêu cau: Sinh vien sua lai chuong trinh nhap mang a va mang b tu ban phim
// Viet chuong trinh con sap xep 2 mang a va b tang dan truoc khi ghep thanh mang c
int sapxep (int a[], int N);
int main(){
	int a[10], b[10], c[20], Na, Nb;
	printf("\nNhap chieu dai Na , Nb : "); scanf("%d%d",&Na,&Nb);
//  Nhap mang a
	printf("\nNhap mang a = \n");
	for (int i=0;i<Na;i++) {
		printf("\t a[%d] = ",i); scanf("%d",&a[i]);
	}
	sapxep(a,Na);
//  Nhap mang b
	printf("\nNhap mang b = \n");
	for (int i=0;i<Nb;i++) {
		printf("\t b[%d] = ",i); scanf("%d",&b[i]);
	}
	sapxep(b,Nb);
	int ia=0, ib=0, ic=0, i;
	while ((ia<Na)&&(ib<Nb))
		if (a[ia]<b[ib]) {
			c[ic]=a[ia]; ic++; ia++;
		}
		else {
			c[ic]=b[ib]; ic++; ib++;
		}
	while (ia<Na) {c[ic]=a[ia]; ic++; ia++; }
	while (ib<Nb) {c[ic]=b[ib]; ic++; ib++; }
	
//  In ket qua
	printf("\nDay a = ");
	for (i=0;i<Na;i++) printf("%3d",a[i]);	
	printf("\nDay b = ");
	for (i=0;i<Nb;i++) printf("%3d",b[i]);	
	printf("\nDay c = ");
	for (int i=0;i<Na+Nb;i++) printf("%3d",c[i]);	
}

int sapxep (int a[], int N) {
	int i,j,t;
	for (i=0;i<N-1;i++)
		for (j=i+1;j<N;j++) 
			if (a[i]>a[j]) {
				t=a[i]; a[i]=a[j]; a[j]=t;
			}
}
		
	
			
