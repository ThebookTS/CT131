//BookTs
// c�ch 1
#include<stdio.h>
#include <conio.h>
#include<math.h>
	float a, b, c, D, x1, x2;
int main()
{
	printf("Giai phuong trinh bac 2");
	printf("\n Nhap he so a: ");
	scanf("%f", &a);
	printf("Nhap he so b: ");
	scanf("%f", &b);
	printf("Nhap he so c: ");
	scanf("%f", &c);
	D = b*b - 4*a*c;
	if(D>0)
	{
		x1 = (-b + sqrt(D)) / 2*a;
		x2 = (-b - sqrt(D)) / 2*a;
		printf("vay phuong trinh co 2 nghiem phan biet la \n");
    	printf("x1 = %f \n", x1);
    	printf("x2 = %f", x2);
	}
	else if(D=0)
		printf("phuong trinh co nghiem kep x = %f", -b/2*a);
	else 
		printf("Phuong trinh vo nghiem");
	return 0;
}

/* c�ch 2
#include<stdio.h>
#include<math.h>
int giaiPT(float a, float b, float c,float &x1, float &x2){
    float delta = b*b - 4*a*c;
    if(delta<0){
        x1=x2=0.0;
        return 0;
    }
    else if(delta==0){
        x1 = x2 = -b/(2*a);
        return 1;
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta) / (2*a);
        x2 = (-b - delta) / (2*a);
        return 2;
    }
}
int main(){
    float a,b,c;
    float x1,x2;
    do{
        printf("Nhap a: ");
        scanf("%f",&a);
        printf("Nhap b: ");
        scanf("%f",&b);
        printf("Nhap c: ");
        scanf("%f",&c);
    }
    while(!a);
    int numNo = giaiPT(a,b,c,x1,x2);
        if(numNo == 0) {
        printf("Phuong trinh da cho vo nghiem");
    }
    else if(numNo == 1){
        printf("Phuong trinh da cho co nghiem kep x=%.4f",x1);
    }
    else{
        printf("Phuong trinh da cho co hai nghiem phan biet\nx1=%.4f \nx2=%.4f",x1,x2);
    }
}
*/

