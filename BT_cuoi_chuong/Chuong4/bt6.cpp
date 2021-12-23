//BookTs
#include<stdio.h>

int main()
{
	int thang,nam;
	printf("nhap vao thang can kiem tra: ");
	scanf("%d",&thang);
	printf("nhap nam");
	scanf("%d",&nam);
	switch(thang)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: printf("thang nay co 30 ngay! \n");break;
		case 4:
		case 6:
		case 9:
		case 11: printf("thang nay co 31 ngay! \n");break;
		case 2:
				if(nam % 4 ==0)
				printf("nam nay la nam nhuan co 29 ngay \n");
				else
				printf("thang nay co 28 ngay\n");
				break;
		
		
	}
	return 0;
}
