#include <stdio.h>

int Divisors(int number) {
   int ndx, count = 0;

   for(ndx = 2; ndx<number; ndx++) {
      if(number%ndx == 0)
         count++;
   }

   return count;
}

main() {
   int divisorCount = 0, triangleNumber, triangleNdx, ndx, naturalNumber;

   for(ndx=100; divisorCount < 499; ndx++) {
      triangleNdx = ndx;
      triangleNumber = 0;
      naturalNumber = 1;

      while(triangleNdx--) {
         triangleNumber += naturalNumber;
         naturalNumber++;
      }

      divisorCount = Divisors(triangleNumber);
   }

   printf("%d\n", triangleNumber);
}
