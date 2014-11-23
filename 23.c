#include <stdio.h>

int IsAbundant(int num) {
   int sum = 0, ndx;
   
   for(ndx=1;ndx<num;ndx++) {
      if(num%ndx == 0)
         sum += ndx;
   }
   
   return sum > num;
}

main() {
   int sum = 0, abundantNumbers[28124], ndx, ndx2;
   int sumOfAbundant[28124], temp;
   
   abundantNumbers[0] = 0;
   
   for(ndx=1;ndx<28124;ndx++) {
       abundantNumbers[ndx] = IsAbundant(ndx);
       sumOfAbundant[ndx]=1;
   }
   
   ndx = 1; 
   while(ndx<28124) {
      while(abundantNumbers[ndx] == 0) {
          ndx++;
      }
      for(ndx2=ndx;ndx2<28124;ndx2++) {
          if(abundantNumbers[ndx2]) {
             temp = ndx + ndx2;
             if(temp<28124)
                sumOfAbundant[temp] = 0;
          }
      }
      ndx++;
   }
   
   for(ndx=0;ndx<28124;ndx++) {
       if(sumOfAbundant[ndx])
          sum+=ndx;
   }
   
   printf("%d\n", sum);
}