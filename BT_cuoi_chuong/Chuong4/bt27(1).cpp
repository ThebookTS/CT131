//BookTs
#include<stdio.h>

#include<math.h>

void Ngto(int n) 
{
	int i, j;
	int ngt=1;
	if(n==1)
	printf("K");
	else{
	for(i=2; i<n; i++) 
	{
		ngt=1;
		for(j=2; j<=sqrt(i); j++) 
		{
			if(i%j==0) 
			{
				ngt=0;
				break;
			}
		}
	if(ngt==1)
	printf("\t %d",i);
	}
	}
}

int main() {
int n;
	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
	}while(n<0);
	printf("Cac so nguyen to la: ");
	Ngto(n);
}
