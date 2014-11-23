#include <stdio.h>

main() {
   int lexCount=1, digitCount, temp;
   int digits[10] = {9,8,7,6,5,4,3,2,1,0}, ndx, ndx2;
  
   while(lexCount<1000000) {
      digits[0]++;
      digitCount = 0;
      for(ndx=0;ndx<10;ndx++) {
         if(digits[ndx]>9) {
            digits[ndx+1] += digits[ndx]/10;
            digits[ndx] = digits[ndx]%10;
         }
      }
      for(ndx=0;ndx<10;ndx++) {
         temp = digits[ndx];
         if(temp == 9) 
            digitCount += 900000000;
         else if(temp == 8) 
            digitCount += 80000000;
         else if(temp == 7)
            digitCount += 7000000;
         else if(temp == 6)
            digitCount += 600000;
         else if(temp == 5)
            digitCount += 50000;
         else if(temp == 4)
            digitCount += 4000;
         else if(temp == 3)
            digitCount += 300;
         else if(temp == 2)
            digitCount += 20;
         else if(temp == 1)
            digitCount += 1;
      }
      if(digitCount == 987654321)
         lexCount++; 
   }

   for(ndx=9;ndx>-1;ndx--) {
      printf("%d", digits[ndx]);
   }
   printf("\n");
}
