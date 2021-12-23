//BooKTs

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

int main()
{
	//Khai bao bien
	int r;
	char ng, ng1, ng2, chedo, may, i[3];
	//Lay ngau nhien
	srand(time(NULL));			//srand(time(NULL)): ho tro cho ham random, tranh truong hop 2 lan random trung gia tri
	r=rand()%3+1; 	// random tu 1 den 3;
	
	//Giao dien tro choi
	printf("Chon che do: ");
	printf("\n1. Hai nguoi choi");
	printf("\n2. Nguoi choi voi may\n");
	scanf("%c",&chedo);
	system("cls");		//Xoa man hinh
	fflush (stdin);
	switch(chedo)
	{
		case '1':
			printf("\t   Che do hai nguoi choi \n\tNguoi choi thu nhat chon\n");
			printf("    [B]ua        [K]eo          Ba[O]\n");
			scanf("%c",&ng1);
			//kiem ra nguoi choi thu nhat co nhap sai khong 
			if ((ng1=='k')||(ng1=='b')||(ng1=='o'))
			{
			//Xoa man hinh
			system("cls");
			//Xoa ky tu enter	
			fflush (stdin);
			printf("\tNguoi choi thu 2 chon\n");
			printf("    [B]ua        [K]eo          Ba[O]\n");
			scanf("%c",&ng2);
			//Xoa man hinh
			system("cls");
			//Kiem tra nguoi choi thu hai co nhap sai khong
			if ((ng2=='k')||(ng2=='b')||(ng2=='o'))
				{
				switch(ng1)
				{
					case 'b': strcpy(i,"BUA"); break;
					case 'k': strcpy(i,"KEO"); break;
					case 'o': strcpy(i,"BAO"); break;
				}
				printf(" Nguoi thu nhat chon %s\n",i);
				switch(ng2)
				{
					case 'b': strcpy(i,"BUA"); break;
					case 'k': strcpy(i,"KEO"); break;
					case 'o': strcpy(i,"BAO"); break;
				}
				printf(" Nguoi thu hai chon %s\n",i);
					
			if (ng1==ng2) printf(" KET QUA HOA\n");
		    else if ((ng1=='b' && ng2=='k')||(ng1=='k' && ng=='o')||(ng1=='o' && ng=='b'))
		    	printf(" NGUOI CHOI THU NHAT THANG\n");
		    else
		    	printf(" NGUOI CHOI THU HAI THANG\n");
			break;
				}
			else
			  printf("Nguoi choi thu hai da nhap sai\n");
			}
			else{
			printf("Nguoi choi thu nhat da nhap sai\n");}
		break;
		case '2':
			printf("\t   Che do nguoi choi voi may \n\t\tNguoi choi chon\n\n");
			printf("    [B]ua        [K]eo          Ba[O]\n");
			scanf("%c",&ng);
			//chuyen chu nhap vao thanh chu thuong
			ng= tolower(ng);
			//Thuat toan
			switch(r)
				{
			    //chuyen gia tri so ngau nhien thanh chu tuong ung
				   case 1: may='b';
			       break;
			       case 2: may='k';
			       break;
			       case 3: may='o';
			       break;
			    }
			//kiem ra xem co nhap sai khong 
			if ((ng=='k')||(ng=='b')||(ng=='o'))
				{
			//In ra ket qua cua nguoi
			switch(ng)
				{
					//strcpy(): sao chep chuoi ky tu
					case 'b': strcpy(i,"BUA"); break;
					case 'k': strcpy(i,"KEO"); break;
					case 'o': strcpy(i,"BAO"); break;
			    }
			    printf(" Ban ra %s\n",i);
			//In ra ket qua cua may
			switch(may)
				{
					case 'b': strcpy(i,"BUA"); break;
					case 'k': strcpy(i,"KEO"); break;
					case 'o': strcpy(i,"BAO"); break;
				}
				printf(" May ra %s\n",i);
			//Chon nguoi Win
				if (ng==may) printf(" KET QUA HOA\n");
			    else if ((ng=='b' && may=='k')||(ng=='k' && may=='o')||(ng=='o' && may=='b'))
			    	printf(" CHUC MUNG BAN DA CHIEN THANG\n");
			    else
			    	printf(" RAT TIEC BAN DA THUA\n");
				}
			else
			  printf(" Ban da nhap sai\n");
		}
		getch();
		return 0;
}
