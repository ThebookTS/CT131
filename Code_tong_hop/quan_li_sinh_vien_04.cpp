#include<stdio.h>  
#include<conio.h> 
#include<string.h>  
 #include<windows.h>
typedef struct  
{  
	char Ma[10];  
	char HoTen[40];
	char NgaySinh[12];
	char NganhHoc[56];  
} SinhVien;  
///----------- 


void Nhap(char *FileName)  // Nhap danh sach sinh vien
{  
	FILE *f;   
	int n,i;  
	SinhVien sv;   	
	f=fopen(FileName,"ab");   	
	printf("Nhap vao so luong sinh vien "); 
	scanf("%d",&n);   	
	for(i=1;i<=n;i++)  
	{  
		printf("Sinh vien thu %i\n",i);   	 	
		fflush(stdin); 
		printf(" - MSSV: ");
		gets(sv.Ma);    
		printf(" - Ho ten: ");
		gets(sv.HoTen);
		printf(" - Ngay sinh:");
		gets(sv.NgaySinh);
		printf(" - Nganh hoc:");
		gets(sv.NganhHoc);    
		fwrite(&sv,sizeof(sv),1,f);  
	}  
	fclose(f);  
	printf("Bam phim bat ky de tiep tuc");  
	getch();  
}  
void InDanhsach(char *FileName)  
{  
	FILE *f;   	
	SinhVien sv;   	
	f=fopen(FileName,"rb");   	
	printf(" MSSV            | Ho va ten                   | Ngay Sinh       | Nganh Hoc \n");   	
	fread(&sv,sizeof(sv),1,f);   	
	while (!feof(f))  
	{  
	printf(" %-10s      | %-22s      | %-10s      | %-16s      \n",sv.Ma,sv.HoTen,sv.NgaySinh,sv.NganhHoc);  
	fread(&sv,sizeof(sv),1,f);  
	}  
	fclose(f);    
}  
void Timkiem(char *FileName) // Tim kiem thong tin sinh vien 
{  
	char MSSV[10];   
	FILE *f;   
	int Found=0;   
	SinhVien sv;   
	fflush(stdin);  
	printf("Ma so sinh vien can tim: ");
	gets(MSSV);  
	f=fopen(FileName,"wb");  
	while (!feof(f) && Found==0)  
	{  
		fread(&sv,sizeof(sv),1,f);   	 	
		if (strcmp(sv.Ma,MSSV)==0) 
			Found=1;  
	}  
	fclose(f);  
	if (Found == 1)  
	{ 
		printf("Tim thay Sinh Vien co ma %s \n",sv.Ma);
		printf(" MSSV            | Ho va ten                   | Ngay Sinh       | Nganh Hoc \n");
		printf(" %-10s      | %-22s      | %-10s      | %-16s      \n",sv.Ma,sv.HoTen,sv.NgaySinh,sv.NganhHoc); 
	}  	
	else  	
	{  
		printf("Tim khong thay sinh vien co ma %s",MSSV);  
	} 
	printf("\nBam phim bat ky de tiep tuc!!!");  
	getch(); 

}
void Sua (char *FileName) //Thay doi thong tin sinh vien
{
  char MSSV[10];int m; char ma1[10];  
	FILE *f;   
	int Found=0;   
	SinhVien sv;   
	fflush(stdin);  
	printf("Ma so sinh vien can thay doi: ");
	gets(MSSV);  
	f=fopen(FileName,"r+b");  
	while (!feof(f) && Found==0)  
	{  
		fread(&sv,sizeof(sv),1,f);   	 	
		if (strcmp(sv.Ma,MSSV)==0) 
			Found=1;  
	}  
	
	if (Found==1) {

	printf("\n*******************CO PHAI BAN MUON SUA?**************************");
	printf("\n %-10s %-22s %-15s %-15s\n","MSSV","HO TEN","Ngay sinh","nganh hoc");
	printf("\n %-12s %-22s %-15s %-7s",sv.Ma,sv.HoTen,sv.NgaySinh,sv.NganhHoc);
	printf("\n******************************************************************\n");
	printf("Neu ban MUON sua nhan 1. Neu KHONG MUON sua vui long nhan 0! ---"); scanf("%d",&m);
	fflush(stdin);                  
		    switch(m)
		    {
                case 1: 
						printf("Ban muon thay doi:\n");
						printf(" 1. MSSV. \n");
                        printf(" 2. Ho Va Ten. \n");                                       
                        printf(" 3. Ngay Sinh (ngay/thang/nam).\n");
                        printf(" 4. Nganh hoc. \n");
						printf(" 5. Thay doi tat ca \n"); 
                        printf("\nVui long nhap lua chon cua ban: ");  
                        int c1;
                        scanf("%d",&c1);
                        fflush(stdin);                                     
                        switch(c1)
                        {
                        case 1: 
                        
                            printf("MSSV %s",sv.Ma);
							printf("		Ban hay nhap MSSV moi: ");
                            fseek(f,ftell(f)-sizeof(sv),0);
                            gets(sv.Ma);
                            fwrite(&sv, sizeof(sv), 1, f);
																				                                                        
                            printf("\n__________Da thay doi thong tin thanh cong!__________");  													    
                            fclose(f);      
                            getch ();                                            
                            break;                                                                                                                                                                                                                                                                                                                 
                        case 2:  
							printf("Ho Va Ten: %s", sv.HoTen);                                                 
                            printf("		Ban hay nhap Ho Va Ten moi: ");
                            gets(sv.HoTen);
                            fseek(f,ftell(f)-sizeof(sv),0);
                            fwrite(&sv, sizeof(sv), 1, f); 													                                                        
                            printf("\n__________Da thay doi thong tin thanh cong!__________");  													    
                            fclose(f);      
                            getch ();                                            
                            break; 
                        case 3:
                			printf("Ngay Sinh (ngay/thang/nam) %s",sv.NgaySinh);     
                            printf("\n Ngay Sinh (ngay/thang/nam) moi: ");
      						gets(sv.NgaySinh);
      						fseek(f,ftell(f)-sizeof(sv),0);
                        	fwrite(&sv, sizeof(sv), 1, f); 													                                                        
                            printf("\n__________Da thay doi thong tin thanh cong!__________");  													    
                            fclose(f);      
                            getch ();                                            
                            break; 
                    	case 4: 
							printf("Nganh Hoc: %s",sv.NganhHoc);                                          
                       		printf("		Nhap Nganh Hoc moi: ");
                        	gets(sv.NganhHoc);
                        	fseek(f,ftell(f)-sizeof(sv),0);
                    		fwrite(&sv, sizeof(sv), 1, f); 													                                                        
                        	printf("\n__________Da thay doi thong tin thanh cong!__________");  													    
                       	 	fclose(f);      
                        	getch ();                                            
                            break;        
                        case 5:
							printf("MSSV %s",sv.Ma);
							printf("		Ban hay nhap MSSV moi: ");
                            fseek(f,ftell(f)-sizeof(sv),0);
                            gets(sv.Ma);
                            fwrite(&sv, sizeof(sv), 1, f);
						    printf("Ho Va Ten: %s", sv.HoTen);                                                 
                            printf("		Ban hay nhap Ho Va Ten moi: ");
                            gets(sv.HoTen);
                            fseek(f,ftell(f)-sizeof(sv),0);
                            fwrite(&sv, sizeof(sv), 1, f); 
							printf("Ngay Sinh (ngay/thang/nam) %s",sv.NgaySinh);     
                            printf("\n Ngay Sinh (ngay/thang/nam) moi: ");
      						gets(sv.NgaySinh);
      						fseek(f,ftell(f)-sizeof(sv),0);
                        	fwrite(&sv, sizeof(sv), 1, f); 
							printf("Nganh Hoc: %s",sv.NganhHoc);                                          
                       		printf("		Nhap Nganh Hoc moi: ");
                        	gets(sv.NganhHoc);
                        	fseek(f,ftell(f)-sizeof(sv),0);
                    		fwrite(&sv, sizeof(sv), 1, f); 													                                                        
                        	printf("\n__________Da thay doi thong tin thanh cong!__________");  													    
                       	 	fclose(f);      
                        	getch ();                                            
                            break;                      		
                		default:      
							printf("Rat tiec ban da lua chon khong dung. \n");
                       		getch();
                       		break; 
                    }        
                                                       
                               
                case 0:  
                    printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
                    getch();
                    break;                                                                                                                   
                default:
                printf("\nRat tiec ban da lua chon khong dung. \n");
                getch();
                break;
            }                   
	           }
}
void Xoa(char *FileName,char*text) //chuong trinh con xoa thong tin sinh vien
{       
    FILE *f, *f1; //khai bao 2 bien con tro la f va f1
    f=fopen(FileName,"r+b");
    f1=fopen(text,"wb");
	fclose(f1);  
    SinhVien sv;
    char FOUND=0;
    char 	Ma[10];
    fflush(stdin);
    printf("\nNhap ma so sinh vien can xoa: ");
    gets(Ma);
    fflush(stdin);
    
    while(!feof(f) && FOUND==0)
     {
       fread(&sv,sizeof(sv),1,f);
       if(strcmp(Ma, sv.Ma)==0)
          FOUND=1;
     }
    
     if (FOUND == 1)
     {
            printf("Da tim thay thong tin cua nguoi co Ma so sinh vien  %s: ", &sv.HoTen);
            printf("\n*******************Co phai ban muon xoa?*********************");
			printf("\n %-10s %-22s %-15s %-15s\n","MSSV","HO TEN","Ngay sinh","nganh hoc");
			printf("\n %-12s %-22s %-15s %-7s",sv.Ma,sv.HoTen,sv.NgaySinh,sv.NganhHoc);
			printf("\n*************************************************************\n");
                         
		                printf("\nBan co chac chan xoa thong tin Sinh Vien nay!?\n");
		                printf("Neu MUON xoa ban vui long nhan phan phim 1.\n");
		                printf("Neu KHONG muon xoa ban vui long nhan phan phim 0.\n");
		                printf("\nVui long nhap lua chon cua ban vao day: ");
		                int c1;
		                scanf("%d",&c1);
		                switch(c1)
		                 {
                          case 1: 
						    int FOUND;
                			f1=fopen(text,"ab");
                            rewind(f);
                            while (!feof(f))
                            	{
    								{ 
                               		if (strcmp(Ma, sv.Ma)==0)
                                	FOUND=1;
                                	else
                                	FOUND=0;
                              		}                                  
                                	if (FOUND==0)
                               		{
                            		fwrite(&sv,sizeof(sv),1,f1);                      
                              		}
                            		fread(&sv, sizeof(sv), 1, f);                                    
                            	}
                                                            		
                           	fclose(f); fclose(f1);
							f1=fopen(text,"rb");
                        	
                            f=fopen(FileName, "w+b");
                            fread(&sv, sizeof(sv), 1, f1);
                            while(!feof(f1))
                            	{
                            	fwrite(&sv, sizeof(sv), 1, f);
                            	fread(&sv, sizeof(sv), 1, f1);
                           		}  
							fclose(f); fclose(f1);   
							remove(text); 
                        	printf("__________Da xoa thanh cong!__________");
                        	printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
							getch();  
                            break;
							                                                                                                            
                          case 0:                                       
                            printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
                            getch();
                            break;
                            
                          default:
                            printf("Rat tiec ban da lua chon khong dung. \n");
                            printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
                            getch();
                            break;                                  
                         }
    }
      

	  else  
           {
                printf("\nERROR!!! Khong tim thay Ma so sinh vien %s ", Ma);
                printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
				getch(); 
           }             
}
void Xoatoanbo(char *FileName) //Xoa toan bo danh sach sinh vien
{	
	int c3;
	printf("\nBan co chac chan xoa TOAN BO thong tin Sinh Vien!?\n");
	printf("Neu MUON xoa ban vui long nhan phan phim 1.\n");
	printf("Neu KHONG muon xoa ban vui long nhan phan phim 0.\n");
	printf("\nVui long nhap lua chon cua ban vao day: ");
	scanf("%d",&c3);
	if(c3==1)
		{
		FILE *f;
    	f=fopen (FileName,"w");
    	printf("\t\t\t______Xoa thanh cong______");
    	fclose(f);
    	printf("\n Nhan phim bat ki de tro ve");
    	getch();
    	}
    	else                                      
        {
		printf("\nMoi ban nhan phim bat ki de tro ve tuy chinh!");
        getch();
    	}
        
		
}
int main()  //chuong trinh chinh
{  
	int c;  
	while(1)  
	{   system("cls");
		printf("\t\t =================== MENU ==================\n");
		printf("\t\t\t 1. Nhap Danh Sach Sinh Vien \n");  
		printf("\t\t\t 2. In Danh Sach Sinh Vien\n");  
		printf("\t\t\t 3. Tim kiem Thong Tin Sinh Vien\n");  
		printf("\t\t\t 4. Thay doi Thong Tin Sinh Vien\n"); 
		printf("\t\t\t 5. Xoa Thong Tin Sinh Vien\n"); 
		printf("\t\t\t 6. Xoa toan bo danh sach \n");
		printf("\t\t\t 7. Thoat \n");
		printf("Moi ban chon 1, 2, 3, 4, 5, 6, 7: ");  
		scanf("%d",&c);  
		fflush(stdin); 
		if(c==1)  
		{ 
			Nhap("SinhVien.dat");  
		} 
		else if (c==2)  
		{ 
			InDanhsach("SinhVien.dat");
			printf("Bam phim bat ky de tiep tuc!!!");  
			getch();  
		} 
		else if (c==3) 
		{  
			Timkiem("SinhVien.Dat");  
		} 
		else if (c==4)
		{	
			InDanhsach("SinhVien.dat");
			Sua("SinhVien.Dat");
		} 
		else if (c==5)
		{
			InDanhsach("SinhVien.dat");
			Xoa("SinhVien.Dat","daxoa.dat");
	    }
		else if (c==6)
		{
			Xoatoanbo ("SinhVien.dat");
		}
		else if (c==7)
		{
		 printf("\t\t=========================================\n");
		 printf("\t\t|             CHAO TAM BIET             |\n" );
		 printf("\t\t=========================================\n");
		 break;
		} 
		
	}
} 
