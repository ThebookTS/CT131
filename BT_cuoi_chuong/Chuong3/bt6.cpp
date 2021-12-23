//BookTs
#include<stdio.h> //thu vien chua ham printf,scanf
#include<conio.h> //thu vien chua ham getch

int main(){
    char kitu;
    int n;
    printf("\nNhap 1 ki tu bat ki: ");
    scanf("%c",&kitu);
    printf("\nMa ASCII cua ki tu %c la %d",kitu,kitu);
    printf("\nKi tu tiep theo la %c",kitu+1);
    getch();
    return 0;
}
