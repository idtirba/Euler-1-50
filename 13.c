#include <stdio.h>

main() {
   FILE *fp = fopen("13.txt", "r");

   int numbers[100], x, y, temp;

   for(x=0;x<100;x++) {
      numbers[x] = 0;
   }

   for(x=0;x<100;x++) {
      for(y=49;y>=0;y--){
         fscanf(fp," %c", &temp);
         printf("%d", temp-48);
         numbers[y] = numbers[y] + (temp - 48);
      }
      printf("\n");
      for(y=0;y<100;y++) {
         if(numbers[y]>9) { 
            numbers[y+1] += (numbers[y]/10);
            numbers[y] = (numbers[y])%10;
         }
      }
   }

   printf("\n");

   for(x=51;x>-1;x--) {
      printf("%d",numbers[x]);
   }
}
