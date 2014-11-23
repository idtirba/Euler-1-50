#include <stdio.h>

main() {
   int numbers[20][20], x, y, largestProduct=0, temp;
   FILE *fp = fopen("11.txt","r");

   for(x=0;x<20;x++) {
      for(y=0;y<20;y++) {
         fscanf(fp,"%d", &numbers[x][y]);
      }
   }

   for(x=0;x<20;x++) {
      for(y=0;y<20;y++) {
         if(x-3>=0) { //check up
            temp = numbers[x][y]*numbers[x-1][y]*numbers[x-2][y]*numbers[x-3][y];
            if(temp>largestProduct)
               largestProduct = temp;
         }
         if(x+3<20) { //check down
            temp = numbers[x][y]*numbers[x+1][y]*numbers[x+2][y]*numbers[x+3][y];
            if(temp>largestProduct)
               largestProduct = temp;
         }          
         if(y-3>=0) { //check left
            temp = numbers[x][y]*numbers[x][y-1]*numbers[x][y-2]*numbers[x][y-3];
            if(temp>largestProduct)
               largestProduct = temp;
         }
         if(y+3<20) {//check right
            temp = numbers[x][y]*numbers[x][y+1]*numbers[x][y+2]*numbers[x][y+3];
            if(temp>largestProduct)
               largestProduct = temp;
         }
         if(y-3>=0 && x+3<20) {//check left diagonal
            temp = numbers[x][y]*numbers[x+1][y-1]*numbers[x+2][y-2]*numbers[x+3][y-3];
            if(temp>largestProduct)
               largestProduct = temp;
         }
         if(y+3<20 && x+3<20) {//check right diagonal
            temp = numbers[x][y]*numbers[x+1][y+1]*numbers[x+2][y+2]*numbers[x+3][y+3];
            if(temp>largestProduct)
               largestProduct = temp;
         }
      }
   }
   printf("%d\n", largestProduct);
}
