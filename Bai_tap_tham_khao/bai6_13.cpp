#include<stdio.h>
#include<conio.h>
// Bai tap 6.13
// Yêu cau: Sinh vien sua lai chuong trinh nhap mang a va mang b tu ban phim
// Viet chuong trinh con sap xep 2 mang a va b tang dan truoc khi ghep thanh mang c
int main(){
	int a[]={1,3,4,6,8,9,12} , b[] = {2,3,5,7,9,11,15} , c[20];
	int Na=sizeof(a)/sizeof(int), Nb=sizeof(b)/sizeof(int);
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
		
	
			
