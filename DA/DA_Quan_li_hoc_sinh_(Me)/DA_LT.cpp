#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>	// thu vien ham Sleep
#include <math.h>

// khai bao
struct hocSinh;
void hienThiDSHS(struct hocSinh*, int);
void hienThiTruong();


// kieu cau truc ho va ten
struct hoTen {
	char ho[20];
	char dem[30];
	char ten[20];
};
// kieu cau truc diem mon hoc 
struct diemMH {
	float toan;
	float van;
	float anh;
	float dtb;
};
// kieu cau truc hoc sinh
struct hocSinh {
	int stt;
	struct hoTen hoVaTen;
	int tuoi;
	char gioiTinh[10];
	struct diemMH diem;
};

// ham nhap diem cac mon hoc
void nhapDiem(struct diemMH* diem) {
	printf("Toan: ");
	scanf("%f", &diem->toan);
	printf("Van: ");
	scanf("%f", &diem->van);
	printf("Anh: ");
	scanf("%f", &diem->anh);
	diem->dtb = (diem->toan + diem->van + diem->anh) / 3;
}
// ham nhap ho va ten
void nhapHoTen(struct hoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Dem: ");
	getchar();
	gets(ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}
// ham nhap hoc sinh
struct hocSinh nhapHS() {
	struct hocSinh hs;	// khai cau truc hocSinh va bien la hs	
	printf("Nhap stt: ");
	scanf("%d", &hs.stt);
	nhapHoTen(&hs.hoVaTen);
	printf("Tuoi: ");
	scanf("%d", &hs.tuoi);
	printf("Gioi tinh: ");
	scanf("%s", hs.gioiTinh);
	nhapDiem(&hs.diem);
	return hs;
}
// ham hien thi thong tin hoc sinh
void hienThiTTHS(struct hocSinh hs) {
	printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	hs.stt, hs.hoVaTen.ho, hs.hoVaTen.dem, hs.hoVaTen.ten, hs.tuoi, hs.gioiTinh,
	hs.diem.toan, hs.diem.van, hs.diem.anh, hs.diem.dtb);
}
// ham sap xep hoc sinh theo ten
void sapXepTheoTen(struct hocSinh* dshs, int slhs) {
	int i, j;
	for(i = 0; i < slhs - 1; i++) {
		for(j = slhs - 1; j > i; j --) {
			if(strcmp(dshs[j].hoVaTen.ten, dshs[j-1].hoVaTen.ten) < 0) {
				struct hocSinh hs = dshs[j];
				dshs[j] = dshs[j - 1];
				dshs[j - 1] = hs;
			}
		}
	}
}
// ham sap xep hoc sinh theo diem
void sapXepTheoDiem(struct hocSinh* dshs, int slhs) {
	int i, j;
	for(i = 0; i < slhs - 1; i++) {
		for(j = slhs - 1; j > i; j --) {
			if(dshs[j].diem.dtb > dshs[j - 1].diem.dtb) {
				struct hocSinh hs = dshs[j];
				dshs[j] = dshs[j - 1];
				dshs[j - 1] = hs;
			}
		}
	}
}
// ham tim kiem theo ten hoc sinh
void timTheoTen(struct hocSinh* dshs, int slhs) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTruong();
	int i, timHS = 0;
	for(i = 0; i < slhs; i++) {
		if(strcmp(ten, dshs[i].hoVaTen.ten) == 0) {
			hienThiTTHS(dshs[i]);
			timHS = 1;
		}
	}
	if(timHS == 0) {
		printf("Khong co hoc sinh %s trong danh sach!\n", ten);
	}
}
// ham ghi file text
void ghiFile(struct hocSinh* dshs, int slhs) {
	getchar();
	char fileName[26];
	printf("Nhap ten file: ");
	gets(fileName);
	FILE* f = fopen(fileName, "a");
	int i;
	fputs("STT        HO         DEM                 TEN        TUOI      GIOI "
	"TINH   DIEM TOAN  DIEM VAN   DIEM ANH   DIEM TB\n", f);
	for(i = 0; i < slhs; i++) {
		struct hocSinh hs = dshs[i];
		fprintf(f, "%-10d %-10s %-20s %-10s %-10d %-10s"
		" %-10.2f %-10.2f %-10.2f %-10.2f\n",
		hs.stt, hs.hoVaTen.ho, hs.hoVaTen.dem, hs.hoVaTen.ten, hs.tuoi, hs.gioiTinh,
		hs.diem.toan, hs.diem.van, hs.diem.anh, hs.diem.dtb);
	}
	fclose(f);
	printf("file %s da duoc luu thanh cong ", fileName);
}
// ham luu du lieu (tuong tu ghi fle text)
void luuDulieu(struct hocSinh* dshs, int slhs) {
	FILE* f = fopen("hSinh.txt", "w+");
	int i;
	for(i = 0; i < slhs; i++) {
		struct hocSinh hs = dshs[i];
		fprintf(f, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		hs.stt, hs.hoVaTen.ho, hs.hoVaTen.dem, hs.hoVaTen.ten, hs.tuoi, hs.gioiTinh,
		hs.diem.toan, hs.diem.van, hs.diem.anh, hs.diem.dtb);
	}
	fclose(f);
}
// ham doc du lieu tu file text
void docFile(struct hocSinh* dshs, int* slhs) {
	FILE* f = fopen("hSinh.txt", "r");
	int i = 0;
	if(f) {
		for(;;) {
			struct hocSinh hs;
			fscanf(f, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&hs.stt, hs.hoVaTen.ho, hs.hoVaTen.dem, hs.hoVaTen.ten, &hs.tuoi, hs.gioiTinh,
			&hs.diem.toan, &hs.diem.van, &hs.diem.anh, &hs.diem.dtb);
			
			dshs[i++] = hs;
			if(feof(f)) { 	// cuoi file se thoat khoi vong lap 
				break;	// thoat chuong trinh
			}
		}
	}
	
	fclose(f);
	*slhs = i;
}
// ham hien thi ten cot
void hienThiTruong() {
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", 
	"STT", "Ho", "Dem", "Ten", "Tuoi", "Gioi Tinh", "Diem Toan", "Diem Van", 
	"Diem Anh", "Diem TB");
}
// ham hien thi danh sach hoc sinh
void hienThiDSHS(struct hocSinh* dshs, int slhs) {
	hienThiTruong();
	int i;
	for(i = 0; i < slhs; i++) {
		hienThiTTHS(dshs[i]);
	}
	printf("---------------------------------------------------------------"
			"------------------------------------------------------\n");
}
// ham diem so lan thuc hien chuong trinh
int demSoLan() {	
	int n;
	FILE *f;
    if((f = fopen("solandem.dat","rb+")) == NULL) {
       printf("Error! opening file");
       exit(1);
    }   
    fread(&n,1, 1, f); 
  	fclose(f); 
  	return n;
}
// ham reset so lan thuc hien chuong trinh
void reset() {	
	int dem=0;
	FILE* f = fopen("solandem.dat","wb+");
	fwrite(&dem,1,1, f); 
	fclose(f);
}


//chuong trinh chinh
int main()
{
	int dem, slhs=0, luaChon,t;
	struct hocSinh dshs[100];
	// Ten nguoi dung va mat khau hien co
    char username1[] = "admin";			 char passwrod1[] = "1";
    char username2[] = "gv";			 char passwrod2[] = "2";
    char username3[] = "Nguyen Van A";	 char passwrod3[] = "1";
    char username4[] = "Nguyen Van B";	 char passwrod4[] = "2";
    char username5[] = "Nguyen Van C";	 char passwrod5[] = "3";
    // Ten nguoi dung va mat khau dang nhap
    char user[50], pass[50], c,b; 
	dem=demSoLan();
	dem++;
	// ghi file dem so lan thuc hien
	FILE *f;
	if ((f = fopen("solandem.dat","w+b")) == NULL) {
		printf("Error! opening file");
	}
	else {
	   	fwrite(&dem,1,1, f); 
	}
	fclose(f);
	dangNhap:
	system("cls");
	int count = 0; // so lan dang nhap
	printf("So lan thuc hien chuong trinh la %d\n", dem);
    printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
	// dang nhap
	do {
		if(count > 0) {
			printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
			printf("\nTen nguoi dung hoac mat khau khong chinh xac lan %d \n",count);
		}
		if(count > 3) {
			int i;
			for (i = pow(count,2) -1 ; i>=0; i--) { 	// i=count^2-1 -> i>=0 
				system("cls");
				printf("So lan thuc hien chuong trinh la %d\n", dem);
				printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
				printf("\nTen nguoi dung hoac mat khau khong chinh xac lan %d \n",count);
				printf("Thoi gian con lai: %ds \n", i);
				Sleep(1000);	// tao thoi gian ngu cho chuong trinh la 1s
			}
		}
		printf("Enter your username: ");
		fflush(stdin);	// xoa ky tu trong bo nho dem
		gets(user);
		printf("Enter your password: ");
		fflush(stdin);	
        gets(pass);
        count++;
        system("cls");	// ham xoa man hinh
		printf("So lan thuc hien chuong trinh la %d\n", dem); 
    }
	while((strcmp(user, username1) != 0 || strcmp(pass, passwrod1) != 0)
		&&(strcmp(user, username2) != 0 || strcmp(pass, passwrod2) != 0)
		&&(strcmp(user, username3) != 0 || strcmp(pass, passwrod3) != 0)
		&&(strcmp(user, username3) != 0 || strcmp(pass, passwrod3) != 0)
		&&(strcmp(user, username4) != 0 || strcmp(pass, passwrod4) != 0)
		&&(strcmp(user, username5) != 0 || strcmp(pass, passwrod5) != 0)); 
		// tai khoan ADMIN		
    	if(strcmp(user, username1) == 0 && strcmp(pass, passwrod1) == 0) {
			printf("Dang nhap thanh cong tai khoan admin\n");
			//Hien thi cac menu
			troLai:
			do {
				printf("\n");
				printf("\t\t--------------[ MENU ]--------------");
				printf("\n\t\t1. Them Hoc Sinh vao danh sach.");
				printf("\n\t\t2. Hien thi danh sach hoc sinh.");
				printf("\n\t\t3. Sap xep theo ten.");
				printf("\n\t\t4. Sap xep theo diem giam dan.");
				printf("\n\t\t5. Tim hoc sinh theo ten.");
				printf("\n\t\t6. Ghi thong tin hoc sinh ra file.");
				printf("\n\t\t7. Xoa toan bo danh sach hoc sinh.");
				printf("\n\t\t8. Reset so lan thuc hien.");
				printf("\n\t\t9. Dang xuat.");
				printf("\n\t\t0. Thoat chuong trinh.");
				printf("\n\nChon chuc nang\n");
				scanf("%d", &luaChon);
				struct hocSinh hs;
				system("cls");	//Xoa man hinh
				printf("So lan thuc hien chuong trinh la %d\n", dem);
				switch(luaChon) {
					case 0:	// thoat chuong trinh
							printf("Ban da thoat chuong trinh");
							break;	
					case 1:	// them hoc sinh vao danh sach
							printf("\t\t\t\t\tChuc nang them hoc sinh vao danh sach\n");
							docFile(dshs, &slhs);
							hs = nhapHS();
							dshs[slhs++] = hs;
							luuDulieu(dshs, slhs);
							break;
					case 2: // hien thi danh sach hoc sinh
							printf("\t\t\t\t\tChuc nang hien thi danh sach hoc sinh\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		   					"------------------------------------------------\n");
							hienThiDSHS(dshs, slhs);
							break;	
					case 3:	// sap xep hoc sinh theo ten tu a-z
							printf("\t\t\t\t\tChuc nang sap xep hoc sinh theo ten\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		   					"------------------------------------------------\n");
							sapXepTheoTen(dshs, slhs);
							printf("\nDanh sach hoc sinh sau khi sap xep theo ten a-z:\n");
							hienThiDSHS(dshs, slhs);
							break;	
					case 4:// sap xep hoc sinh theo diem giam dan
							printf("\t\t\t\t\tChuc nang sap xep hoc sinh theo diem\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		  					 "------------------------------------------------\n");
							sapXepTheoDiem(dshs, slhs);
							printf("\nDanh sach hoc sinh sau khi sap xep theo diem giam dan:\n");
							hienThiDSHS(dshs, slhs);
							break;
					case 5:// tim kiem hoc sinh theo ten
							printf("\t\t\t\t\tChuc nang tim kiem hoc sinh theo ten\n");
							docFile(dshs, &slhs);
							timTheoTen(dshs, slhs);
							break;	
					case 6:// ghi file danh sach hoc sinh
							printf("\t\t\t\t\tChuc nang ghi file danh sach hoc sinh\n");
							docFile(dshs, &slhs);
							ghiFile(dshs, slhs);
							break;
					case 7:// xoa toan bo danh sach hoc sinh
							printf("\t\t\t\t\tChuc nang xoa toan bo danh sach hoc sinh\n");
							printf("\tBan co chac muon xoa khong (y/n) \n");
							fflush(stdin);
							scanf("%c",&b);
							if(b=='y'|b=='Y') {
							luuDulieu(dshs, slhs);
							Sleep(500);
							printf("Da xoa thanh cong !!!");
							goto troLai;	// quay ve menu
							}
							else if(b=='n'|b=='N') {
								break;
							}
							else 
								printf("Ban da nhap sai cu phap!");
					case 8: 
							reset();
							system("cls");
							printf("So lan thuc hien chuong trinh la %d\n", dem);
							break;
					case 9:
							printf("Ban co chac dang xuat khong (y/n) ");
							fflush(stdin);
							scanf("%c",&c);
							if (c=='y'||c=='Y') {
								goto dangNhap;
							}
							else if (c=='n'||c=='N') {
								break;
							}
							else {
								printf("Ban da nhap sai cu phap!");
							}
							break;
					default:
							printf("Ban chon sai, vui long chon lai!\n");
							break;
				}	
			}
			while(luaChon);
		}
		// tai khoan GV
		else if	(strcmp(user, username2) == 0 && strcmp(pass, passwrod2) == 0) {
			printf("Dang nhap thanh cong tai khoang giao vien\n");
			do {
				printf("\n");
				printf("\t\t--------------[ MENU ]--------------");
				printf("\n\t\t1. Hien thi danh sach hoc sinh.");
				printf("\n\t\t2. Sap xep theo ten.");
				printf("\n\t\t3. Sap xep theo diem giam dan.");
				printf("\n\t\t4. Tim hoc sinh theo ten.");
				printf("\n\t\t5. Ghi thong tin hoc sinh ra file.");
				printf("\n\t\t6. Dang xuat.");
				printf("\n\t\t0. Thoat chuong trinh.");
				printf("\n\nChon chuc nang\n");
				scanf("%d", &luaChon);
				struct hocSinh hs;
				system("cls");	//Xoa man hinh
				printf("So lan thuc hien chuong trinh la %d\n", dem);
				switch(luaChon) {
					case 0:	// thoat chuong trinh
							printf("Ban da thoat chuong trinh");
							break;	
					case 1: // hien thi danh sach hoc sinh
							printf("\t\t\t\t\tChuc nang hien thi danh sach hoc sinh\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		  					"------------------------------------------------\n");
							hienThiDSHS(dshs, slhs);
							break;	
					case 2:	// sap xep hoc sinh theo ten tu a-z
							printf("\t\t\t\t\tChuc nang sap xep hoc sinh theo ten\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		   					"------------------------------------------------\n");
							sapXepTheoTen(dshs, slhs);
							printf("\nDanh sach hoc sinh sau khi sap xep theo ten a-z:\n");
							hienThiDSHS(dshs, slhs);
							break;	
					case 3: // sap xep hoc sinh theo diem giam dan
							printf("\t\t\t\t\tChuc nang sap xep hoc sinh theo diem\n");
							docFile(dshs, &slhs);
							printf("-----------------------------------------------[ DANH SACH HOC SINH ]"
		   					"------------------------------------------------\n");
							sapXepTheoDiem(dshs, slhs);
							printf("\nDanh sach hoc sinh sau khi sap xep theo diem giam dan:\n");
							hienThiDSHS(dshs, slhs);
							break;
					case 4: // tim kiem hoc sinh theo ten
							printf("\t\t\t\t\tChuc nang tim kiem hoc sinh theo ten\n");
							docFile(dshs, &slhs);
							timTheoTen(dshs, slhs);
							break;	
					case 5: // ghi file danh sach hoc sinh
							printf("\t\t\t\t\tChuc nang ghi file danh sach hoc sinh\n");
							docFile(dshs, &slhs);
							ghiFile(dshs, slhs);
							break;
					case 6:	// dang xuat tai khoan
							printf("Ban co chac dang xuat khong (y/n) ");
							fflush(stdin);
							scanf("%c",&c);
							if (c=='y'||c=='Y') {
								int count = 0;
								goto dangNhap;
							}
							else if (c=='n'||c=='N') {
								break;
							}
							else {
								printf("Ban da nhap sai cu phap");
							}
							break;
					default:
							printf("Ban chon sai, vui long chon lai!\n");
							break;
				}	
			}
			while(luaChon);
		}
		// tai khoan hoc sinh A
		else if	(strcmp(user, username3) == 0 && strcmp(pass, passwrod3) == 0) {
			printf("Dang nhap hoc sinh A\n");
			docFile(dshs, &slhs);
			char ten[]="A";
			hienThiTruong();
			int i;
			for(i = 0; i < slhs; i++) {
				if(strcmp(ten, dshs[i].hoVaTen.ten) == 0) {
					hienThiTTHS(dshs[i]);
				}
			}
			printf("\n\tBam phim [ 0 ] de dang xuat \n");
			fflush(stdin);
			scanf("%d",&t);
			if(t==0) {
				int count = 0;
				goto dangNhap;
			}
			else
				printf("\nBam nhap sai cu phap");
		}
		// tai khoan hoc sinh B
		else if	(strcmp(user, username4) == 0 && strcmp(pass, passwrod4) == 0) {
			printf("Dang nhap hocc sinh B\n");
			docFile(dshs, &slhs);
			char ten[20]="B";
			hienThiTruong();
			int i;
			for(i = 0; i < slhs; i++) {
				if(strcmp(ten, dshs[i].hoVaTen.ten) == 0) {
					hienThiTTHS(dshs[i]);
				}
			}
			printf("\n\tBam phim [ 0 ] de dang xuat\n");
			fflush(stdin);
			scanf("%d",&t);
			if(t==0) {
				int count = 0;
				goto dangNhap;
			}
			else
				printf("\nBam nhap sai cu phap");
		}
		// tai khoan hoc sinh C
		else if	(strcmp(user, username5) == 0 && strcmp(pass, passwrod5) == 0) {
			printf("Dang nhap hoc sinh C\n");
			docFile(dshs, &slhs);
			char ten[20]="C";
			hienThiTruong();
			int i;
			for(i = 0; i < slhs; i++) {
				if(strcmp(ten, dshs[i].hoVaTen.ten) == 0) {
					hienThiTTHS(dshs[i]);
				}
			}
			printf("\n\tBam phim [ 0 ] de dang xuat \n");
			fflush(stdin);
			scanf("%d",&t);
			if(t==0) {
				int count = 0;
				goto dangNhap;
			}
			else
				printf("\nBam nhap sai cu phap");
		}
	getch();
    return 0;
}
