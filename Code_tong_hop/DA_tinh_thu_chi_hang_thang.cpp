#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
// chuong trinh con tinh tien dien.
int tiendiennongthon(int n)
{
	int x,y;
	printf("ban dung dien cho muc dich nao? \n");
	printf("1.Sinh Hoat.\n");
	printf("2.Muc dich khac.\n");
	scanf("%d",&x);
	system("cls");
	if (x==1)
	{
       if(n<50) y=n*1403;
       else if(n<101) y=n*1459;
       else if(n<201) y=n*1590;
       else if(n<301) y=n*1971;
       else if(n<401) y=n*2231;
       else  y=n*2323;
       
	}
	else if(x==2)
	{
		y=n*1473;
	}
	else
	{
		printf("ban nhap sai, vui long lua chon 1 hoac 2: \n");
		system("cls");
	}
return(y);
}
// chuong trinh con tinh tien dien.
int tiendien(int n)
{
	int y,z;
	z=0;
	 again:;
	printf("ban thuoc khu vu nao?\n");
	printf("1. Nong Thon.\n");
	printf("2. Cho.\n");
	scanf("%d",&y);
	system("cls");
	if (y==1) 	z=tiendiennongthon(n);
	else if (y==2) 	z=n*2382;
	else 
	printf("ban nhap sai, vui long lua chon 1 hoac 2 \n");
	return(z);
}
// chuong trinh con tinh tien dien cho tung loai do dung dien.
int dodung(int x,int y)
{
	int z;
	z=(x*y)/1000;
    return(z);
}
// chuong trinh con tinh tien nuoc.
int tiennuoc(int n)
{
	int x, y;
	printf("Ban thuoc dien nao sau day.\n");
	printf("1. Ho ngheo co so.\n");
	printf("2. Khong co so ho ngheo, dung nuoc cho muc dich sinh hoat.\n");
	printf("3. Co quan hanh chinh, don vi su nghiep.\n");
	printf("4. Hoat dong san xuat vat chat.\n");
	printf("5. Kinh danh dich vu.\n");
	scanf("%d",&x);
	system("cls");
	switch(x)
	{
		case 1:
			y=n*4000;
			break;
		case 2:
		 if(n<11) y=n*5500;
		 else if (n<21) y=n*6800;
		 else if (n<31) y=n*7600;
		 else y=n*8700;
		 break;
		case 3:
		   y=n*8000;
		   break;
		case 4:
		   y=n*8900;   	
		   break;
		case 5:
			y=n*11100;
			break;
	}
	return(y);
}
// lai tiet kiem.
float tietkiem(int p){
	int a;
	float b, M; 
	printf("moi ban chon ngan hang: \n");
	printf("1. Agribank \n");
    printf("2. Sacombank\n");
	printf("3. HDbank \n");
	scanf("%d", &a);
	system("cls");
	printf("so tien ban da gui: \n");
	scanf("%f", &M);
	system("cls");
	switch(a){
		case 1:{
			printf("Agribank.\n");
			float LaiDon=0;
			LaiDon= M*(0.068/12);
			b=LaiDon; 
			break;
		}
		case 2:{
			printf("Sacombank.\n");
			float LaiDon=0;
			LaiDon= M*(0.068/12);
			b=LaiDon;
			break;
		}
		case 3:{
			printf("HDbank.\n");
			float LaiDon=0;
			LaiDon= M*(0.06/12);
			b=LaiDon;
			break;
			}
		default:{
				
				printf("nhap sai\n moi ban chon lai");	
		
		}
		
	}
return(b); 
}
// chuong trinh con tinh tien lai phai tra hang thang ngan hang Sacombank
int tienlai1(float n, int t)
{
int a;
float b;
printf("muc dich vay.\n");
printf("1.vay phat trien nong nghiep.\n");
printf("2.vay san xuat kinh doanh.\n");
printf("3.vay tieu dung.\n");
printf("4.vay mua xe.\n");
printf("5.vay mua nha.\n");
scanf("%d",&a);
system("cls");
switch(a)
{
case 1:
if(t<3) b=n*0.055;
else if(t<6) b=n*0.06;
else if(t<9) b=n*0.065;
else if(t<12) b=n*0.07;
else b=t*0.075;
break;
case 2:
if(t<3) b=n*0.059;
else if(t<6) b=n*0.064;
else if(t<9) b=n*0.07;
else if(t<12) b=n*0.074;
else b=t*0.08;
break;
case 3:
if(t<3) b=n*0.06;
else if(t<6) b=n*0.065;
else if(t<9) b=n*0.071;
else if(t<12) b=n*0.077;
else b=t*0.082;
break;
case 4:
if(t<3) b=n*0.062;
else if(t<6) b=n*0.067;
else if(t<9) b=n*0.073;
else if(t<12) b=n*0.079;
else b=n*0.086;
break;
case 5:
if(t<3) b=n*0.06;
else if(t<6) b=n*0.062;
else if(t<9) b=n*0.07;
else if(t<12) b=n*0.073;
else b=n*0.082;
break;
}
return(b);
}
// chuong trinh con tinh tien lai phai tra hang thang ngan hang HDbank
int tienlai2(float n, int t)
{
int a;
float b;
printf("muc dich vay.\n");
printf("1.vay phat trien nong nghiep.\n");
printf("2.vay san xuat kinh doanh.\n");
printf("3.vay tieu dung.\n");
printf("4.vay mua xe.\n");
printf("5.vay mua nha.\n");
scanf("%d",&a);
system("cls");
switch(a)
{
case 1:
if(t<3) b=n*0.056;
else if(t<6) b=n*0.061;
else if(t<9) b=n*0.067;
else if(t<12) b=n*0.074;
else b=n*0.078;
break;
case 2:
if(t<3) b=n*0.06;
else if(t<6) b=n*0.066;
else if(t<9) b=n*0.071;
else if(t<12) b=n*0.074;
else b=n*0.081;
break;
case 3:
if(t<3) b=n*0.061;
else if(t<6) b=n*0.067;
else if(t<9) b=n*0.071;
else if(t<12) b=n*0.079;
else b=n*0.083;
break;
case 4:
if(t<3) b=n*0.062;
else if(t<6) b=n*0.065;
else if(t<9) b=n*0.07;
else if(t<12) b=n*0.075;
else b=n*0.08;
break;
case 5:
if(t<3) b=n*0.064;
else if(t<6) b=n*0.068;
else if(t<9) b=n*0.07;
else if(t<12) b=n*0.073;
else b=n*0.086;
break;
}
return(b);
}
// chuong trinh con tinh tien lai phai tra hang thang ngan hang Agribank
int tienlai3(float n, int t)
{
int a;
float b;
printf("muc dich vay.\n");
printf("1.vay phat trien nong nghiep.\n");
printf("2.vay san xuat kinh doanh.\n");
printf("3.vay tieu dung.\n");
printf("4.vay mua xe.\n");
printf("5.vay mua nha.\n");
scanf("%d",&a);
system("cls");
switch(a)
{
case 1:
if(t<3) b=n*0.05;
else if(t<6) b=n*0.055;
else if(t<9) b=n*0.06;
else if(t<12) b=n*0.067;
else b=n*0.072;
break;
case 2:
if(t<3) b=n*0.55;
else if(t<6) b=n*0.06;
else if(t<9) b=n*0.066;
else if(t<12) b=n*0.07;
else b=n*0.075;
break;
case 3:
if(t<3) b=n*0.056;
else if(t<6) b=n*0.062;
else if(t<9) b=n*0.068;
else if(t<12) b=n*0.072;
else b=n*0.073;
break;
case 4:
if(t<3) b=n*0.06;
else if(t<6) b=n*0.062;
else if(t<9) b=n*0.067;
else if(t<12) b=n*0.07;
else b=n*0.075;
break;
case 5:
if(t<3) b=n*0.06;
else if(t<6) b=n*0.063;
else if(t<9) b=n*0.068;
else if(t<12) b=n*0.07;
else b=n*0.076;
break;
}
return(b);
}
int luachon(float n, int ttt)
{
int a,c,t;
system("cls");
printf("ngan hang ban da vay.\n");
printf("1.ngan hang Sacombank .\n");
printf("2.ngan hang HDbank\n");
printf("3.ngan hang Agribank\n");
scanf("%d",&a);
system("cls");
switch(a)
{
case 1:
c=tienlai1(n,t);
break;
case 2:
c=tienlai2(n,t);
break;
case 3:
	
c=tienlai3(n,t);
break;
}
return(c) ;
}

// Doc FILE
int Doc(){
	int n;
   
   FILE *fptr;
 
   if ((fptr = fopen("file.txt","rb+")) == NULL){
       printf("Error! opening file");
       exit(1);
   }   
      fread(&n,1, 1, fptr); 
  	 fclose(fptr); 
  	 return n;
}

// chuong trinh chinh.
int main()
{
 int a,n;
 
 int dem=0;
 
for(int i=0;i<100;i++)
 {
 	
 again:;
 dem = Doc(); 
 printf(" So lan su dung chuong trinh: %d", dem);
 printf("\n\t\t\t\t!====================================================!\n");
 printf("\n\t\t\t\t       !**** UNG DUNG TINH TIEN SINH HOAT  ****!\n");
 printf("\n\t\t\t\t!====================================================!\n");
 printf("Vui Long lua chon 1 trong cac tinh nang sau:\n");	
 printf("0. Tinh tien thu chi hang thang.\n");	
 printf("1. Tinh tien dien\n");
 printf("2. Tien dien cho tung loai do dung\n");	
 printf("3. Tinh tien nuoc\n");	
 printf("4. Tinh tien lai vay ngan hang\n");	
 printf("5. Tinh lai tiet kiem.\n");	
 printf("6. Thoat chuong trinh.\n");	
 scanf("%d",&a);
 system("cls");
 switch(a)
 {
 	case 6:
 		printf("Dang thoat... ");
 		exit(0);
 	case 1:
 	    printf("nhap so dien ban su dung(kWh): ");
	    scanf("%d",&n);
	    system("cls");
 	    printf("so tien dien ban can phai tra la: %dVND\n\n",tiendien(n));
 	    printf("Nhan phim bat ki de tro lai man hinh chinh.");
 	    getch();
 	    system("cls");
 	    break;
 	case 2:
 		int  y,x;
 		printf("Cong suat cua do dung dien la(W):\n");
	    scanf("%d",&x);
	    printf("so gio ban su dung:\n");
     	scanf("%d",&y);
     	system("cls");
     	printf("So tien ban can phai tra la: %dVND\n", tiendien(dodung(x,y)));
     	printf("Nhan phim bat ki de tro lai man hinh chinh.");
 	    getch();
 	    system("cls");
 	    break;
 	case 3:
 		printf("so m^3(met khoi) ban da sung dung: ");
	    scanf("%d",&n);
	    system("cls");
 	   	printf("so tien ban can phai tra la: %dVND\n\n",tiennuoc(n));
 	   	printf("Nhan phim bat ki de tro lai man hinh chinh.");
 	   	getch();
 	   	system("cls");
 	   	break;
 	case 4:
 	   float luachon1, n; 
 	   int ttt;
 	   printf("so tien ban da vay.\n");
       scanf("%f",&n); 
       printf("so thang ban vay la.\n");
       scanf("%d",&ttt);      
       luachon1=luachon(n,ttt);
       printf("so tien ban phai tra la: %f\n",luachon1);
       getch();
       system("cls");
       break;  
 	case 5:	
 	    float  case5; 
	    case5=tietkiem(0);
	    printf("\nso tien ban nhan duoc hang thang la: \n");
        printf("%.2f", case5);
	    getch();
	  	system("cls");
	    break;
	case 0:
		int a0, a1,a2, a3, a4, a5, a6, a7, a8, a9, chon, tongthu, tongchi,tt; 
		printf("nhap thu nhap hang thang cua ban: ");
	    scanf("%d",&a0);
	    system("cls");
		printf("nhap so dien ban da su dung trong thang(kWh): ");
	    scanf("%d",&n);
	    system("cls");
	    a1=tiendien(n);
	    printf("so m^3(met khoi) ban da sung dung trong thang: ");
	    scanf("%d",&n);
	    system("cls");
        a2=tiennuoc(n);
        printf("Chi tieu an uong trong thang cua ban la:\n");
    	scanf("%d",&a3);
     	system("cls");
    	printf(" Tien xang hoac phuong tien di chuyen hang thang cua ban la :\n");
    	scanf("%d",&a4);
        system("cls");
    //  
        printf("ban co su dung internet khong \n");
        printf("1.Co\n");
        printf("2.Khong\n");
        scanf("%d",&chon);
        system("cls");
	    if(chon==1)
		{
		printf("so tien ban tra cho dich vu internet la:\n");
        scanf("%d",&n);
		a5=n;
	    }
	    else
		{
		a5=0;
      	}
	    system("cls");
	//    
        printf("ban co vay tien ngan hang khong?\n");
        printf("1.Co\n");
        printf("2.Khong\n");
        scanf("%d",&chon);
        system("cls");
	    if(chon==1)
		{
		printf("so tien ban da vay.\n");
        scanf("%d",&n);
		a8=luachon(n,1);
	    }
	    else
		{
		a8=0;
      	}
    //  	
      	printf("ban co gui tiet kiem ngan hang khong?\n");
        printf("1.Co\n");
        printf("2.Khong\n");
        scanf("%d",&chon);
        system("cls");
	    if(chon==1)
		{
		printf("so tien ban da gui.\n");
        scanf("%d",&n);
		a9=tietkiem(0);
	    }
	    else
		{
		a9=0;
      	} 
	  	system("cls");
    //
        printf("cac khoan chi tieu khac chua duoc liet ke(neu khong co nhap 0): \n");
        scanf("%d",&a6);
	    system("cls");
    //    
        printf("cac khoan thu khac chua duoc liet ke(neu khong co nhap 0): \n");
        scanf("%d",&a7);
	    system("cls");
	//
	  	tongthu=a0+ a7 + a9;
		tongchi= a1+ a2 +a3 +a4 +a5 + a6 +a8; 
		printf("tong so tien thu vao thang nay la: %d \n", tongthu);
		printf("tong so tien chi ra thang nay la: %d \n", tongchi);
		printf("so tien con lai: %d \n", tongthu-tongchi);
		getch();
	  	system("cls");
	    break;
 }
 dem++;
  // dem so lan su dung
    FILE *fptr;
    if ((fptr = fopen("D:\\file.txt","w+b")) == NULL){
       printf("Error! opening file");
   }else{
   		 fwrite(&dem,1,1, fptr); 
   }
    fclose(fptr);  
 goto again;
}
}


