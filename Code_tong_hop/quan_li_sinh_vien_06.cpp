//quan li sinh vien

#include <stdio.h>
#include <conio.h>
#include <string.h>
struct Subject{
	char Tenhocphan[50];
	int  Tinchi;
	float  Diemhp;
} ;

struct NgayThang{
   int Ngay;
   int Thang;
   int Nam; 	
};

struct Student{
	char MSSV[10];
	char hoTen[50];
	char Gioitinh[5];
	struct NgayThang NgaySinh;
	char Lop[];
	struct Subject hocPhan[10];
};

int n;
Student dsSV[100];



float tinhDTB(int t){
	//tinh diem trung binh cua sinh vien thu t
	float s=0;
	int tongTC=0;
	for(int i=0;i<3;i++) {
		s+=(dsSV[t].hocPhan[i].Diemhp)*(dsSV[t].hocPhan[i].Tinchi);
		tongTC+=dsSV[t].hocPhan[i].Tinchi;
	}
	return s/tongTC;
}
	
void xeploai(int t){
// xep loai cho sinh vien thu t
        float x=tinhDTB(t);	
    	if(x>=3.6) printf("Xuat sac");
    	else if(x>=3.2) printf("Gioi");
    	else if(x>=2.5) printf("Kha");
    	else if(x>=2) printf("Trung binh");
    	else if(x>=1) printf("Trung binh yeu");
    	else printf("Kem");
}  
  


void nhap() {
	printf("Nhap so luong sinh vien: "); scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Nhap thong tin cua sinh vien thu %d: ",i+1);
		fflush(stdin);
		printf("\nNhap MSSV: "); gets(dsSV[i].MSSV); 
     	printf ("Nhap ho ten: "); gets(dsSV[i].hoTen);
     	printf("Nhap Ngay thang nam sinh (dd mm yyyy): ");
		scanf("%d%d%d",&dsSV[i].NgaySinh.Ngay,&dsSV[i].NgaySinh.Thang,&dsSV[i].NgaySinh.Nam);
     	fflush(stdin);
     	printf("Nhap gioi tinh: "); gets(dsSV[i].Gioitinh);
     	printf("Nhap lop: "); gets(dsSV[i].Lop);
        for(int j=0;j<3;j++) {
        	printf("Nhap thong tin cua hoc phan thu %d:\n",j+1);
        	fflush(stdin);
        	printf ("- Nhap ten hoc phan: "); gets(dsSV[i].hocPhan[j].Tenhocphan);
    		printf ("- Nhap so tin chi: "); scanf("%d",&dsSV[i].hocPhan[j].Tinchi);
    		printf ("- Nhap diem hoc phan: "); scanf("%f",&dsSV[i].hocPhan[j].Diemhp);
	 }
     
     }
}
   // xuat thong tin

void xuat(){
printf ("Thong tin sinh vien sau khi tinh diem trung binh va xep loai\n");
	printf ("   MSSV  |       Ho ten       | Ngay sinh |Gioi tinh|   Lop   |   Ten HP      |So chi|Diem HP| DTB |Xep loai\n");
	for (int i=0;i<n;i++) {
		printf("---------------------------------------------------------------------------------------------------------------\n");
		printf("%*s|",9,dsSV[i].MSSV);
		printf("%*s|",20,dsSV[i].hoTen);
		printf("%02d/%02d/%04d |",dsSV[i].NgaySinh.Ngay,dsSV[i].NgaySinh.Thang,dsSV[i].NgaySinh.Nam);
		printf("%*s|",9,dsSV[i].Gioitinh);
		printf("%*s|",9,dsSV[i].Lop);
		for(int j=0;j<3;j++){
			if(j>0) printf ("         |                    |           |         |         |");
				printf("%*s|",15,dsSV[i].hocPhan[j].Tenhocphan);
				printf("%*d|",6,dsSV[i].hocPhan[j].Tinchi);
				printf("  %.1f  |",dsSV[i].hocPhan[j].Diemhp);
			if(j>0) printf("     |\n");
			if(j==0) {
				float k=tinhDTB(i);
				printf("%.2f |",k);
				xeploai(i);
				printf("\n");	
			}
		}
		
		
	}
	}
	
	
void doidiem(){
// qui doi diem 
for (int i=0;i<n;i++)
    for(int j=0;j<3;j++){
        float x=dsSV[i].hocPhan[j].Diemhp;	
    	if(x>=9) x=4;
    	else if(x>=8) x=3.5;
    	else if(x>=7) x=3;
    	else if(x>=6.5) x=2.5;
    	else if(x>=5.5) x=2;
    	else if(x>=5) x=1.5;
    	else if(x>=4) x=1;
    	else x=0;
    	dsSV[i].hocPhan[j].Diemhp=x;
	}
}
  


    // sap xep tang dan diem trung binh
void sapxep(){
	Student t;
	for(int i=0;i<n-1;i++)    
		for(int j=i+1;j<n;j++) 
			if(tinhDTB(i)<tinhDTB(j)){
				t=dsSV[i];
				dsSV[i]=dsSV[j];
				dsSV[j]=t;
			}	
}
    
int main(){ 
	nhap();
	doidiem();
	xuat();
    sapxep();
    printf("\nSau khi da sap xep\n");
    xuat();
getch ();
return 0;
}

