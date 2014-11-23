#include <stdio.h>

main() {
   int number[1000], ndx, ndx2, count;

   for(ndx=0;ndx<1000;ndx++) {
      number[ndx] = 0;
   }

   number[2] = 1;

   for(count=99;count>1;count--) {
      for(ndx = 0; ndx<1000; ndx++) {
         number[ndx] = number[ndx] * count;
      }
      for(ndx2=0;ndx2<1000;ndx2++) {
         if(number[ndx2]>9) {
            number[ndx2+1] += (number[ndx2]/10);
            number[ndx2] = number[ndx2]%10;
         }
      }
   }

   int sum = 0;

   for(ndx=160;ndx>=0;ndx--) {
      printf("%d", number[ndx]);
      sum+=number[ndx];
   }
   printf("\n");

   printf("%d\n", sum);
}
