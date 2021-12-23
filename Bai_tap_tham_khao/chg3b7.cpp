#include <stdio.h>
#include <math.h>
int main() {
	float R1,R2,R3,R,Rss;
	printf("\nNhap R1 = "); scanf("%f",&R1);
	printf("\nNhap R2 = "); scanf("%f",&R2);
	printf("\nNhap R3 = "); scanf("%f",&R3);
	R = (1/R1) + (1/R2) + (1/R3) ;
	Rss = 1/R;
	Rss = 1/((1/R1) + (1/R2) + (1/R3)) ;
	printf("\nTong tro Rss = %f ",Rss);
}

//#include <stdio.h>
//#include <math.h>
//int main() {
//	float R,Rss; //R1,R2,R3,R,Rss;
//	printf("\nNhap R1 = "); scanf("%f",&R);
//	Rss=1/R;
//	printf("\nNhap R2 = "); scanf("%f",&R);
//	Rss+=1/R;
//	printf("\nNhap R3 = "); scanf("%f",&R);
//	Rss+=1/R;	
////	R = (1/R1) + (1/R2) + (1/R3) ;
////	Rss = 1/R;
////	Rss = 1/((1/R1) + (1/R2) + (1/R3)) ;
//	printf("\nTong tro Rss = %f ",1/Rss);
//}
