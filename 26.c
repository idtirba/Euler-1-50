#include<stdio.h>

main() {
   int numbers[1000][1000], ndx1, ndx2, temp;
   int divisor = 1, lengths[1000], maxNdx=0, maxLength=1;

   for(ndx1=0;ndx1<1000;ndx1++) {
      for(ndx2=0;ndx2<1000;ndx2++) {
         numbers[ndx1][ndx2] = 0;
      }
      numbers[ndx1][0] = 1;
      lengths[ndx1] = 0;
   }

   for(ndx1=0;ndx1<1000;ndx1++) {
      for(ndx2=0;ndx2<1000;ndx2++) {
         if(numbers[ndx1][ndx2] % divisor == 1 && ndx2 > 4) {
            if(ndx2 > maxLength) {
               maxLength = ndx2;
               maxNdx = ndx1;
            }
            break;
         }
         if(ndx2<999)
            numbers[ndx1][ndx2+1] = numbers[ndx1][ndx2]%divisor * 10;
         numbers[ndx1][ndx2] = (numbers[ndx1][ndx2]) / divisor;
      }
      divisor++;
   }
   printf("Max Length with divisor of %d with length %d\n", maxNdx+1, maxLength);
}
