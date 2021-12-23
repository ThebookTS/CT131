//BookTs
#include <stdio.h>
int main()
{
	int ng, t, n;
	printf("Nhap ngay thang nam: ");
	scanf("%d%d%d", &ng, &t, &n);
	switch(t)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
			if(ng>0 && ng <=30)
				printf("Ngay %d Thang %d Nam %d HOP LE", ng, t, n);
			else printf("Ngay %d Thang %d Nam %d KHONG HOP LE", ng, t, n); break;
		case 4: case 6: case 9: case 11:
			if(ng>0 && ng<=30)
				printf("Ngay %d Thang %d Nam %d HOP LE", ng, t, n);
			else printf("Ngay %d Thang %d Nam %d KHONG HOP LE", ng, t, n); break;
		case 2:
			if(ng>0 && ng <=28 || ng<=29)
				printf("Ngay %d Thang %d Nam %d HOP LE", ng, t, n);
			else printf("Ngay %d Thang %d Nam %d KHONG HOP LE", ng, t, n); break;
		default: printf("Ngay %d Thang %d Nam %d KHONG HOP LE", ng, t, n); break;
	}
	return 0;
}
