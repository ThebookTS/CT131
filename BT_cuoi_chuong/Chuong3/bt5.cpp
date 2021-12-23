//BookTs
#include <stdio.h>
#include <conio.h>
#include <math.h>

int x1,x2,h1,h2;
float hs,kc;

main()
{
  int i;
  printf("\t");
  for (i=1;i<30;i++) printf("* ");
  printf("\n\t\t CHUONG TRINH TINH HSG VA KC\n\n");

	printf("\t Nhap diem x1: "); scanf("%d",&x1);
	printf("\t Nhap diem x2: "); scanf("%d",&x2);
	printf("\t Nhap diem h1: "); scanf("%d",&h1);
	printf("\t Nhap diem h2: "); scanf("%d",&h2);
  	
	  hs=(h2-h1)/(x2-x1);
 	kc=sqrt((h2-h1)*(h2-h1)+(x2-x1)*(x2-x1));
 
 printf("\n\t -> He  so  goc = %.3f",hs);
 printf("\n\t -> Khoang cach = %.3f",kc);

 getch();
 return 0;
}
