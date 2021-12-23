//BookTs

#include <conio.h>
#include <stdio.h>

main()
{
//trang tri chuong trinh
  int i;
  printf("\t");
  for (i=1;i<30;i++) printf("* ");
  printf("\n\t\t TIM N NHO NHAT THOA 1+1/2+1/3+...+1/N>S\n\n");

 int n;
 float plus,s;

 printf("\t- Nhap vao so S= "); scanf("%f",&s);

 plus=1;
 n=2;

 while (plus<=s)
    {
  plus=plus+float((float(1)/n));
  n+=1;
 }

 printf("\n\t=> N= %d la so nho nhat can tim!",n-1);

 getch();
 return 0;

}
