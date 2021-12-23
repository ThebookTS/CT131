//BookTs
#include <stdio.h> 
#include <conio.h>

int  main () 
{ 
	int  i, n; 
	float S; 
	S = 0; 
	i = 1; 
	do 
	{ 
		printf(" \n Nhap n:"); 
		scanf("% d" , &n); 
		if (n < 1) 
		{ 
			printf ("\n N phai lon hon hoac bang 1. Xin nhap lai!"); 
		} 
	}while (n < 1);

	while(i <= n) 
	{ 
		S = S + ((float)i / (i + 1)); 
		i ++ ; 
	} 
	printf("\n Tong la %f", S);

	getch (); 
	return  0 ; 
}
