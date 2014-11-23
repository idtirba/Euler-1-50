#include <stdio.h>

main() {

   long largestNum = 0, largestCount= 0, count = 1, x, y;

   for(x=2;x<1000000;x++) {
      count = 1;
      y=x;
      while(y > 1) {
         if((y%2) == 0){
            y = y/2;
         }
         else {
            y = (y*3) + 1;
         }
         count++;
      }
      if(count>largestCount) {
         largestCount = count;
         largestNum = x;
      }
   }

   printf("%d %d\n", largestNum, largestCount);

}
