//BookTs
#include<stdio.h>
#include<conio.h>

int main() {
   int arr[10][10], size, i, j, temp;

   printf("\nNhap kich co cua ma tran: ");
   scanf("%d", &size);

   printf("\nNhap ma tran:\n");
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
    	printf("Nhap phan tu thu [%d][%d]",i,j);
         scanf("%d", &arr[i][j]);
      }
   }

   printf("\nMa tran vua nhap la: \n");
   for (i = 0; i < size; i++) {
      printf("\n");
      for (j = 0; j < size; j++) {
         printf("%d\t", arr[i][j]);
      }
   }

   /* Tim ma tran chuyen vi */
   for (i = 1; i < size; i++) {
      for (j = 0; j < i; j++) {
         temp = arr[i][j];
         arr[i][j] = arr[j][i];
         arr[j][i] = temp;
      }
   }

   printf("\nMa tran chuyen vi cua ma tran da cho la:\n");
   for (i = 0; i < size; i++) {
      printf("\n");
      for (j = 0; j < size; j++) {
         printf("%d\t", arr[i][j]);
      }
   }

   return (0);
}
