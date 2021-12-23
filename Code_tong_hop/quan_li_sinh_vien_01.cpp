//BookTs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define MAX_SO_MON_HOC 6
#define MAX_MSSV 8
#define MAX_HO_TEN 30
#define MAX_DIA_CHI 50

// cau truc thong tin sinh vien
struct SINHVIEN
{
	char MSSV[MAX_MSSV]; 
	char TEN[MAX_HO_TEN]; 
	char GIOITINH[3];
	char DIACHI[MAX_DIA_CHI];
	int DIEMMONHOC[MAX_SO_MON_HOC];
};


void nhapThongTinSinhVien(SINHVIEN &sv);


void xuatThongTinSinhVien(SINHVIEN sv);


void nhapDanhSachSinhVien(SINHVIEN sv[], int n);


void timSinhVien(SINHVIEN sv[], char * mssv, int n);


void themSinhvien(SINHVIEN sv[], int &n, SINHVIEN p, int vt);


void xoaSinhVien(SINHVIEN a[], int &n, int vt);


void menu();

int main()
{
	SINHVIEN sv[MAX];	
	int soSV;			

	while (1)
	{
		int choice;
		menu();
		printf("Moi ban chon chuc nang: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			printf("Nhap so luong sinh vien (Toi da la 150 sinh vien): ");
			scanf("%d", &soSV);

			if (soSV < 1 || soSV > 150)
			{
				printf("Vuot qua gioi han.\n");
				return 1;
			}

			nhapDanhSachSinhVien(sv, soSV);

			break;
		}
		case 2:
		{
			char mssv[MAX_MSSV];

			printf("Nhap vao mssv: ");
			scanf("%s", mssv);

			timSinhVien(sv, mssv, soSV);
			break;
		}
		case 3:
		{
			printf("Nhap sv can them:\n");
			SINHVIEN tmp;
			nhapThongTinSinhVien(tmp);
			themSinhvien(sv, soSV, tmp, 1);

			break;
		}
		case 4:
		{
			int tmp = 0;
			printf("Nhap vi tri can xoa: ");
			scanf("%d", &tmp);
			xoaSinhVien(sv, soSV, tmp);

			break;
		}
		case 5:
		{
			for (int i = 0; i < soSV; i++)
			{
				xuatThongTinSinhVien(sv[i]);
			}

			break;
		}
		case 6:
		{
			for (int i = 0; i < soSV; i++)
			{
				for (int j = 0; j < MAX_SO_MON_HOC; j++)
				{
					if (sv[i].DIEMMONHOC[j] < 5)
					{
						xuatThongTinSinhVien(sv[i]);
						break;
					}
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}
		system("pause");
		system("cls");
		
	}
	return 0;
}

void nhapThongTinSinhVien(SINHVIEN &sv)
{
	printf("\nNhap MSSV: ");
	scanf("%s", sv.MSSV);

	printf("\nNhap ho ten: ");
	scanf("%s", sv.TEN);

	printf("\nNhap gioi tinh: (Nam, Nu): ");
	scanf("%s", sv.GIOITINH);

	printf("\nNhap dia chi: ");
	scanf("%s", sv.DIACHI);

	printf("\nNhap diem %d mon hoc: \n", MAX_SO_MON_HOC);

	for (int i = 0; i < MAX_SO_MON_HOC; i++)
	{
		printf("Mon thu %d: ", i + 1);
		scanf("%d", &sv.DIEMMONHOC[i]);
	}
}

void xuatThongTinSinhVien(SINHVIEN sv)
{
	printf("1.MSSV: %s\n", sv.MSSV);
	printf("2.Ho ten: %s\n", sv.TEN);
	printf("3.Gioi tinh: %s\n",sv.GIOITINH);
	printf("4.Dia chi: %s\n", sv.DIACHI);

	for (int i = 0; i < MAX_SO_MON_HOC; i++)
	{
		printf("Mon thu %d: %d\n", i + 1, sv.DIEMMONHOC[i]);
	}
}

void nhapDanhSachSinhVien(SINHVIEN sv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		nhapThongTinSinhVien(sv[i]);
	}
}
void timSinhVien(SINHVIEN sv[], char * mssv, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sv[i].MSSV, mssv) == 0)
		{
			j = 1;
			xuatThongTinSinhVien(sv[i]);
		}
	}
	if (j == 0)
		printf("Khong tim thay sinh vien");
}
void themSinhvien(SINHVIEN sv[], int &n, SINHVIEN p, int vt)
{
	n++;
	for (int i = n - 1; i > vt; i--)
	{
		sv[i] = sv[i - 1];
	}
	sv[vt] = p;
}
void xoaSinhVien(SINHVIEN a[], int &n, int vt)
{
	for (int i = vt; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void menu()
{
	printf("--------------------- CHUONG TRINH QUAN LI SINH VIEN --------------\n");
	printf("1.Nhap moi danh sach sinh vien\n");
	printf("2.Tim sinh vien theo MSSV\n");
	printf("3.Them sinh vien\n");
	printf("4.Xoa sinh vien\n");
	printf("5.Xuat danh sach sinh vien ra man hinh\n");
	printf("6.Xuat sinh vien con no diem\n");
	printf("Nhan phim bat ki de thoat khoi chuong trinh.\n");

