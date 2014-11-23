#include <stdio.h>

main() {
   int ndxNeeded = 1, ndx, currentNumber, product=1, digitCount = 0;
   int numberSize = 1, sizeThreshold = 10, currentDigit, divider=1;
   int currentSize;

   for(ndx=1;ndxNeeded<10000000;ndx++) {
      currentNumber = ndx;
      if(ndx == sizeThreshold) {
         numberSize++;
         sizeThreshold*=10;
      }
      divider = sizeThreshold/10;
      currentSize = numberSize;
      while(currentSize--) {
         currentDigit = currentNumber / divider;
         digitCount++;
         if(digitCount == ndxNeeded) {
            product*=currentDigit;
            ndxNeeded*=10;
         }
         currentNumber = currentNumber - currentDigit * divider;
         divider/=10;
      }
   }
   printf("%d:", ndx);
   printf("%d\n", product);
}
