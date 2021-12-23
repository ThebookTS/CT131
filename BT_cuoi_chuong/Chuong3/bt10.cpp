//BookTs
//bien 100 thanh 001
#include<stdio.h> //printf,scanf
#include<conio.h> //getch

int main(){
    int n,hople=0;
    while(hople==0)
	{
    	printf("\nNhap 1 so nguyen duong co 3 chu so:");
        scanf("%d",&n);
        if(n>=100 && n<=999) hople=1;
    } //nhap dung so nguyen duong co 3 chu so
    int a,b,c;
    a=n%10;
    b=(n%100)/10;
    c=n/100;
    printf("\nSo dao nguoc cua so %d la %d%d%d",n,a,b,c);
    getch();
    return 0;
}

//bien 100 thanh 1
/*
#include<stdio.h> //printf,scanf
#include<conio.h> //getch

int main(){
    int n,hople=0;
    while(hople==0){
                    printf("\nNhap 1 so nguyen duong co 3 chu so:");
                    scanf("%d",&n);
                    if(n>=100 && n<=999) hople=1;
                    }// nhap dung so nguyen duong co 3 chu so
    n=(n%10)*100+((n%100)/10)*10+(n/100);
    printf("\nSo dao nguoc la %d",n);
    getch();
    return 0;
}
*/
