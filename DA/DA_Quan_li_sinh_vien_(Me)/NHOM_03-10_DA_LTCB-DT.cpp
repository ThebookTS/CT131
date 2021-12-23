//BookTs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

// Khai bao
struct sinhVien;
void printDSSV(struct sinhVien*, int);
void printCot();

// Dinh nghia cau truc tai khoan
struct taiKhoan {
	char username[20];
	char password[20];
	char loaiTK[20];
};
// Dinh nghia cau truc ho ten
struct hoTen {
	char ho[20];
	char dem[30];
	char ten[20];
};
// Dinh nghia cau truc ngay thang
struct ngayThang {
   unsigned int Ngay;
   unsigned int Thang;
   unsigned int Nam;
};
// Dinh nghia cau truc sinh vien
struct sinhVien {
	char lop[10];
	char mssv[10];
	struct hoTen hoVaTen;
	char gioiTinh[10];
	ngayThang ngaySinh;
	char queQuan[40];
};

// Ham luu tai khoan
void luuTaiKhoan(struct taiKhoan* dstk, int sltk) {
	FILE* fOut = fopen("mytk.txt", "w");
	int i;
	for(i = 0; i < sltk; i++) {
		struct taiKhoan tk = dstk[i];
		fprintf(fOut,"%-30s %-30s %-30s\n", tk.username, tk.password, tk.loaiTK);
	}
	fclose(fOut);
}
// Ham doc tai khoan
void docTaiKhoan(struct taiKhoan* dstk, int* sltk) {
	FILE* fOut = fopen("mytk.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct taiKhoan tk;
			fscanf(fOut,"%30s %30s %30s\n",tk.username,tk.password,tk.loaiTK);
			dstk[i++] = tk;
			if(feof(fOut)) {
				break;
			}
		}
	}
	fclose(fOut);
	*sltk = i;
}
// Ham hien thi thong tin tai khoan
void hienThiTTTK(struct taiKhoan tk) {
	printf("%-30s %-30s %-30s\n",tk.username,tk.password,tk.loaiTK);
}
// Ham hien thi danh sach tai khoan
void hienThiDSTK(struct taiKhoan* dstk, int sltk) {
	int i;
	printf("-----------------------[ DANH SACH TAI KHOAN ]"
		"----------------------------\n");
	printf("%-30s %-30s %-30s\n", "Username", "Password", "Loai TK");
	for(i = 0; i < sltk; i++) {
		hienThiTTTK(dstk[i]);
	}
}
// Ham nhap tai khoan
struct taiKhoan nhapTK() {
	struct taiKhoan tk;
	printf("Nhap username: ");
	scanf("%s",tk.username);
	printf("Nhap password: ");
	scanf("%s",tk.password);
	printf("Nhap loai tai khoan: ");
	scanf("%s",tk.loaiTK);
	return tk;
}
// Ham nhap ho va ten
void scanHoTen(struct hoTen* ten) {
	printf("Nhap ho: ");
	scanf("%s", ten->ho);	fflush(stdin);
	printf("Nhap ten dem: ");
	gets(ten->dem);			fflush(stdin);
	printf("Nhap ten: ");
	scanf("%s", ten->ten);	fflush(stdin);
}
// Ham nhap ngay sinh
void scanNgaySinh(struct ngayThang* ngaySinh) {
	printf("Nhap ngay sinh: ");
	scanf("%d", &ngaySinh->Ngay);	fflush(stdin);
	printf("Nhap thang sinh: ");
	scanf("%d", &ngaySinh->Thang);	fflush(stdin);
	printf("Nam sinh: ");
	scanf("%d", &ngaySinh->Nam);	fflush(stdin);
}
// Ham nhap sinh vien
struct sinhVien scanSV() {
	struct sinhVien sv;
	printf("Lop: ");
	gets(sv.lop);				fflush(stdin);
	printf("MSSV: ");
	scanf("%s",sv.mssv);		fflush(stdin);
	scanHoTen(&sv.hoVaTen);
	printf("Gioi tinh: ");
	scanf("%s",sv.gioiTinh);	fflush(stdin);
	scanNgaySinh(&sv.ngaySinh);
	printf("Que quan: ");
	gets(sv.queQuan);			fflush(stdin);
	return sv;
}
// Ham hien thi thong tin sinh vien
void printTTSV(struct sinhVien sv) {
	printf("%-12s %-12s %-10s %-20s %-10s %-10s %-2d-%-2d-%-6d %-12s\n",
	sv.lop, sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.gioiTinh,
	sv.ngaySinh.Ngay,sv.ngaySinh.Thang,sv.ngaySinh.Nam, sv.queQuan);
}
// Ham sap xep sinh vien theo lop
void arrangeTheoLop(struct sinhVien* dssv, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(strcmp(dssv[j].lop, dssv[j-1].lop) < 0) {
				struct sinhVien sv = dssv[j];
				dssv[j] = dssv[j - 1];
				dssv[j - 1] = sv;
			}
		}
	}
}
// Ham tim kiem sinh vien theo ten
void searchTheoMSSV(struct sinhVien* dssv, int slsv) {
	char maSV[20];
	printf("Nhap  MSSV: ");
	scanf("%s", maSV);		fflush(stdin);
	printCot();
	int i, find = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(maSV, dssv[i].mssv) == 0) {
			printTTSV(dssv[i]);
			find = 1;
		}
	}
	if(find == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", maSV);
	}
}
// Ham xuat danh sach sinh vien
void xuatFile(struct sinhVien* dssv, int slsv) {
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i; 
	fputs("Lop          MSSV         Ho         Ten dem              Ten        "
		"Gioi tinh  Ngay sinh    Que quan\n", fOut);
	for(i = 0; i < slsv; i++) {
		struct sinhVien sv = dssv[i];
		fprintf(fOut,"%-12s %-12s %-10s %-20s %-10s %-10s %-2d-%-2d-%-6d %-12s\n",
		sv.lop, sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.gioiTinh,
		sv.ngaySinh.Ngay,sv.ngaySinh.Thang, sv.ngaySinh.Nam, sv.queQuan);
	}
	fclose(fOut);
	printf("file %s da duoc luu thanh cong \a", fName);
}
// Ham luu du lieu danh sach sinh vien
void saveData(struct sinhVien* dssv, int slsv) {
	FILE* fOut = fopen("student.txt", "w");
	int i;
	for(i = 0; i < slsv; i++) {
		struct sinhVien sv = dssv[i];
		fprintf(fOut,"%-12s %-12s %-10s %-20s %-10s %-10s %-2d %-2d %-6d %-12s\n",
		sv.lop, sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.gioiTinh,
		sv.ngaySinh.Ngay,sv.ngaySinh.Thang, sv.ngaySinh.Nam, sv.queQuan);
	}
	fclose(fOut);
}
// Ham doc file danh sach sinh vien
void readFile(struct sinhVien* dssv, int* slsv) {
	FILE* fOut = fopen("student.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct sinhVien sv;
			fscanf(fOut,"%12s %12s %10s %20[^\n] %10s %10s %2d %2d %6d %12[^\n]\n",
			sv.lop, sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.dem, sv.hoVaTen.ten, sv.gioiTinh,
			&sv.ngaySinh.Ngay, &sv.ngaySinh.Thang, &sv.ngaySinh.Nam, sv.queQuan);
			dssv[i++] = sv;
			if(feof(fOut)) {
				break;
			}
		}
	}
	fclose(fOut);
	*slsv = i;
}
// Ham hien thi ten cot
void printCot() {
	printf("%-12s %-12s %-10s %-20s %-10s %-10s %-12s %-15s \n",
	"Lop", "MSSV", "Ho", "Ten dem", "Ten", "Gioi tinh", "Ngay sinh", "Que quan");
}
// Ham hien thi danh sach sinh vien
void printDSSV(struct sinhVien* dssv, int slsv) {
	printf("---------------------------------------[ DANH SACH SINH VIEN ]"
		"----------------------------------------\n");
	printCot();
	int i;
	for(i = 0; i < slsv; i++) {
		printTTSV(dssv[i]);
	}
	printf("-----------------------------------------------------------"
			"-------------------------------------------\n");
}
// Ham dem so lan thuc hien
int demSoLan() {	
	int n;
	FILE *fOut;
    if((fOut = fopen("soLanThucHien.dat","rb+")) == NULL) {
       printf("Error! opening file");
       exit(1);
    }   
    fread(&n,1, 1, fOut); 
  	fclose(fOut); 
  	return n;
}
// Ham reset so lan thuc hien
void reset() {	
	int dem=0;
	FILE* fOut = fopen("soLanThucHien.dat","wb+");
	fwrite(&dem,1,1, fOut); 
	fclose(fOut);
}
// Ham xoa danh sach sinh vien
void xoaDSSV() {
	int del;
	char fName[50];
	printf("Nhap danh ten danh sach ban muon xoa: ");
	gets(fName);
 	del = remove(fName);			// ham remove la xoa file text
	if(del == 0) {
   		printf("Xoa danh sach %s thanh cong !!!", fName);
	}
   	else {	
		printf("Error! khong the xoa file tren");
	}
}

// Chuong trinh chinh
int main()
{ 
	int sltk=0, dem, elect, slsv = 0;
	struct taiKhoan dstk[100];
	struct taiKhoan tk;
	struct sinhVien dssv[200];
	
	dem=demSoLan(); 		// gan gia tri dem = gia tri doc file 
	dem++;
	FILE *f;
	if ((f = fopen("soLanThucHien.dat","w+b")) == NULL) {
		printf("Error! opening file");
	}
	else {
	   	fwrite(&dem,1,1, f); 		// Luu gia tri dem vao file
	}
	fclose(f);

	ReturnDangNhap:						// Dang nhap
	char user[50], pass[50];
	int i, count=0;
	docTaiKhoan(dstk, &sltk);
	
	printf("So lan thuc hien chuong trinh la %d\n", dem);
	printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
	do {
		if(count > 0) {
			printf("So lan thuc hien chuong trinh la %d\n", dem);
			printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
			printf("\nTen nguoi dung hoac mat khau khong chinh xac lan %d \n",count);
		}
		if(count > 3) {
			int i;
			for (i = pow(count,2) -1 ; i>=0; i--) {		// Neu count > 3 thi se cho count^2 giay
				system("cls");
				printf("So lan thuc hien chuong trinh la %d\n", dem);
				printf("\t\t\t\tDang Nhap He Thong Quan Li\n");
				printf("\nTen nguoi dung hoac mat khau khong chinh xac lan %d \n",count);
				printf("Thoi gian con lai: %ds \n", i);
				Sleep(1000);
				}
			}
		printf("Enter your username: ");		// Nhap tai khoan
		gets(user);
		fflush(stdin);
		printf("Enter your password: ");		// Nhap mat khau
		gets(pass);
		fflush(stdin);
      system("cls");
		for(i = 0; i < sltk; i++) {
			// So sanh tai khoan va mat khau da nhap voi trong dstk
			if((strcmp(user, dstk[i].username) == 0) && (strcmp(pass, dstk[i].password) == 0)) {
				if(strcmp("ADMIN", dstk[i].loaiTK) == 0) {		// Dang nhap tai khoan ADMIN
					printf("So lan thuc hien chuong trinh la %d\n", dem);
					printf("Dang nhap thanh cong tai khoan ADMIN\n");
					do {
						printf("\n");
						printf("\t\t--------------[ MENU ]--------------");
						printf("\n\t\t1. Them tai khoan.");
						printf("\n\t\t2. Hien thi danh sach tai khoan.");
						printf("\n\t\t3. Them sinh vien vao danh sach.");
						printf("\n\t\t4. Hien thi danh sach sinh vien.");
						printf("\n\t\t5. Sap xep theo lop.");
						printf("\n\t\t6. Tim sinh vien theo MSSV.");
						printf("\n\t\t7. Xuat thong tin sinh vien ra file.");
						printf("\n\t\t8. Xoa toan bo danh sach sinh vien.");
						printf("\n\t\t9. Reset so lan thuc hien.");
						printf("\n\t\t10. Dang xuat");
						printf("\n\t\t0. Thoat chuong trinh.");
						printf("\n\nChon chuc nang\n");
						scanf("%d", &elect);
						fflush(stdin);
						struct sinhVien sv;
						system("cls");
						switch(elect) {
						case 0:
							printf("Ban da thoat chuong trinh"); exit(0);
							break;	
						case 1:
							printf("\tChuc nang them tai khoan\n");
							docTaiKhoan(dstk, &sltk);
							tk = nhapTK();			// gan tk = ham nhap tai khoan
							dstk[sltk++] = tk;	// gan dstk i + 1 = tk	
							luuTaiKhoan(dstk, sltk);
							break;
						case 2:
							printf("\tChuc nang hien thi danh sach tai khoan\n");
							docTaiKhoan(dstk, &sltk);
							hienThiDSTK(dstk, sltk);
							break;
						case 3:
							printf("\tChuc nang them sinh vien vao danh sach\n");
							readFile(dssv, &slsv);
							sv = scanSV();
							dssv[slsv++] = sv;
							saveData(dssv, slsv);
							Sleep(500);
							printf("Da them thanh cong!!!");
							break;
						case 4:
							printf("\tChuc nang hien thi danh sach sinh vien\n");
							readFile(dssv, &slsv);
							printDSSV(dssv, slsv);
							break;	
						case 5:
							printf("\tChuc nang sap xep sinh vien theo lop\n");
							readFile(dssv, &slsv);
							arrangeTheoLop(dssv, slsv);
							printf("\tDanh sach sinh vien sau khi duoc sap xep la.\n");
							printDSSV(dssv, slsv);
							break;	
						case 6:
							printf("\tChuc nang tim kiem sinh vien theo MSSV\n");
							readFile(dssv, &slsv);
							searchTheoMSSV(dssv, slsv);
							break;	
						case 7:
							printf("\tChuc nang xuat file danh sach sinh vien\n");
							readFile(dssv, &slsv);
							xuatFile(dssv, slsv);
							break;
						case 8:
							printf("\tChuc nang xoa toan bo danh sach sinh vien\n");
							xoaDSSV();
							break;
						case 9:
							reset();
							system("cls");
							dem=demSoLan();
							printf("So lan thuc hien chuong trinh la %d\n", dem);
							break;
						case 10:
							char c;
							printf("Ban co chac dang xuat khong (y/n) ");
							scanf("%c",&c); 	fflush(stdin);
							system("cls");
							if (c=='y'||c=='Y') {
								goto ReturnDangNhap;				// tro ve dang nhap
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
						printf("\nNhan phim bat ki de tiep tuc.");
						getchar();	
						system("cls");
						printf("So lan thuc hien chuong trinh la %d\n", dem);
					}
					while(elect);
				}
				else if(strcmp("GV", dstk[i].loaiTK) == 0) {			// Dang nhap tai khoan GV
					printf("So lan thuc hien chuong trinh la %d\n", dem);
					printf("Dang nhap thanh cong tai khoan GIAO VIEN\n");
					do {
						printf("\n");
						printf("\t\t--------------[ MENU ]--------------");
						printf("\n\t\t1. Them sinh vien vao danh sach.");
						printf("\n\t\t2. Hien thi danh sach sinh vien.");
						printf("\n\t\t3. Sap xep theo lop.");
						printf("\n\t\t4. Tim sinh vien theo MSSV.");
						printf("\n\t\t5. Xuat thong tin sinh vien ra file.");
						printf("\n\t\t6. Dang xuat");
						printf("\n\t\t0. Thoat chuong trinh.");
						printf("\n\nChon chuc nang\n");
						scanf("%d", &elect);
						fflush(stdin);
						struct sinhVien sv;
						system("cls");
						switch(elect) {
						case 0:
							printf("Ban da thoat chuong trinh"); exit(0);
							break;	
						case 1:
							printf("\tChuc nang them sinh vien vao danh sach\n");
							readFile(dssv, &slsv);
							sv = scanSV();
							dssv[slsv++] = sv;
							saveData(dssv, slsv);
							printDSSV(dssv, slsv);
							break;
						case 2:
							printf("\tChuc nang hien thi danh sach sinh vien\n");
							readFile(dssv, &slsv);
							printf("---------------------------------------[ DANH SACH SINH VIEN ]"
								"----------------------------------------\n");
							printDSSV(dssv, slsv);
							break;	
						case 3:
							printf("\tChuc nang sap xep sinh vien theo lop\n");
							readFile(dssv, &slsv);
							arrangeTheoLop(dssv, slsv);
							break;	
						case 4:
							printf("\tChuc nang tim kiem sinh vien theo MSSV\n");
							readFile(dssv, &slsv);
							searchTheoMSSV(dssv, slsv);
							break;	
						case 5:
							printf("\tChuc nang xuat file danh sach sinh vien\n");
							readFile(dssv, &slsv);
							xuatFile(dssv, slsv);
							break;
						case 6:
							char c;
							printf("Ban co chac dang xuat khong (y/n) ");
							scanf("%c",&c); 	fflush(stdin);
							system("cls");
							if (c=='y'||c=='Y') {
								goto ReturnDangNhap;
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
						printf("\nNhan phim bat ki de tiep tuc.");
						getchar();	
						system("cls");
						printf("So lan thuc hien chuong trinh la %d\n", dem);	
					}
					while(elect);
				}
				else {		// Dang nhap tai khoan sinh vien
					printf("So lan thuc hien chuong trinh la %d\n", dem);
					int j;
					readFile(dssv, &slsv);
					for(j = 0; j < slsv; j++) {
						if(strcmp(user,dssv[j].mssv) == 0) {
							printf("Dang nhap thanh cong tai khoan SINH VIEN: [ %s %s %s ]\n", 
							dssv[j].hoVaTen.ho, dssv[j].hoVaTen.dem,dssv[j].hoVaTen.ten);
							printCot();
							printTTSV(dssv[j]);
							
							printf("\n\t\t--------------[ MENU ]--------------");
							printf("\n\t\t1. Dang xuat");
							printf("\n\t\t0. Thoat chuong trinh.");
							printf("\n\nChon chuc nang:\n");
							scanf("%d", &elect);
							fflush(stdin);
							struct sinhVien sv;
							system("cls");
							switch(elect) {
							case 0:
								printf("Ban da thoat chuong trinh"); exit(0);
								break;	
							case 1:
								char c;
								printf("Ban co chac dang xuat khong (y/n) ");
								scanf("%c",&c); 	fflush(stdin);
								system("cls");
								if (c=='y'||c=='Y') {
									goto ReturnDangNhap;
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
					}
					printf("\t\t\t\t Sinh vien co ma so %s chua co thong tin trong danh sach\n", user);
					printf("\t Bam phim bat ki de tiep tuc\n");
					getchar();
					system("cls");
					goto ReturnDangNhap;
				}	
			}
		}	
		count++;
	} while(1);

	return 0;
}
