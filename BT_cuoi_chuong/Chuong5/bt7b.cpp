//BookTs
#include<stdio.h>
#include<math.h>
int main()
{
	int i1,i2,s2,s1,s,n,a;
	s1=0;
	s2=0;
	i1=1;
	i2=0;
	printf("Nhap n");
	scanf("%d",&n);
	printf("Nhap a");
	scanf("%d",&a);
	while (i1<=n)
	{
		s1=s1-(pow(a,i1));
		i1=i1+2;
	}
	while (i2<=n)
	{
		s2=s2+(pow(a,i2));
		i2=i2+2;
	}
	s=s1+s2;
	printf("Tong s la: %d",s);
	return 0;
}


