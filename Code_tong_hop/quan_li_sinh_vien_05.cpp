#include<conio.h>
#include<stdio.h>
#include<string.h>

typedef struct
{
   unsigned char Ngay;
   unsigned char Thang;
   unsigned int Nam;
} NgayThang;

typedef struct
{
   char MSSV[10];
   char HoTen[40];
   NgayThang NgaySinh;
   int Phai;
   char DiaChi[40];
} SinhVien;

void InSV(SinhVien s)
{
   printf("MSSV:  |  Ho va ten   |  Ngay Sinh   |  Dia chi\n");
   printf("%s  |  %s |  %d-%d-%d |  %s\n",s.MSSV,s.HoTen,
     s.NgaySinh.Ngay,s.NgaySinh.Thang,s.NgaySinh.Nam,s.DiaChi);
}

int main()
{
   SinhVien SV;
   printf("Nhap MSSV: ");gets(SV.MSSV);
   printf("Nhap Ho va ten: ");gets(SV.HoTen);
   printf("Sinh ngay: ");scanf("%d",&SV.NgaySinh.Ngay);
   printf("Thang: ");scanf("%d",&SV.NgaySinh.Thang);
   printf("Nam: ");scanf("%d",&SV.NgaySinh.Nam);
   printf("Gioi tinh (0: Nu), (1: Nam): ");scanf("%d",&SV.Phai);
   flushall();
   printf("Dia chi: ");gets(SV.DiaChi);
   InSV(SV);
   SinhVien s;
   s=SV;	
 	InSV(s);
   getch();
   return 0;
}
 
