//BookTs
#include<stdio.h>
//Ham UCLN
int USCLN(int a, int b) {
    if (b == 0) return a;
    return USCLN(b, a % b);
}
//Ham BCNN
int BSCNN(int a, int b) {
    return (a * b) / USCLN(a, b);
}

int main() {
 int a, b;
    printf("Nhap so nguyen duong a = ");
    scanf("%d", &a);
    printf("Nhap so nguyen duong b = ");
    scanf("%d", &b);
    // tinh USCLN cua a và b
    printf("UCLN cua %d va %d la: %d", a, b, USCLN(a, b));
    // tinh BSCNN cua a và b
    printf("BCNN cua %d va %d la: %d", a, b, BSCNN(a, b));
}
