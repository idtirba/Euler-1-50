#include <stdio.h>

main() {
   int number[1000], ndx, prev[1000], fibTerm = 2, temp;

   for(ndx=0;ndx<999;ndx++) {
      number[ndx] = 0;
      prev[ndx] = 0;
   }
   
   prev[0] = 1;
   number[0] = 1;

   while(number[999] == 0 && fibTerm++) {
      for(ndx=0;ndx<999;ndx++) {
         temp = number[ndx];
         number[ndx] += prev[ndx];
         prev[ndx] = temp;
      }
      for(ndx=0;ndx<999;ndx++) {
         if(number[ndx]>9) {
            number[ndx+1] += number[ndx]/10;
            number[ndx] = number[ndx]%10;
         }
      }
   }

   printf("%d\n", fibTerm);
   for(ndx=999;ndx>-1;ndx--){
      //printf("%d", number[ndx]);
   }

   printf("\n");
}
