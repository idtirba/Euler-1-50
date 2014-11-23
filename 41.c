#include <stdio.h>

char primes[100000001];

int IsPandigital(int number) {
   int digits[10], ndx, lastDigit, temp = number;
   for(ndx=0;ndx<10;ndx++) {
      digits[ndx] = 0;
   }
   while(number) {
      digits[number%10]++;
      number/=10;
   }
   if(digits[0] != 0)
      return 0;
   for(ndx=1;ndx<10;ndx++) {
      if(digits[ndx] != 1 && digits[ndx] != 0)
         return 0;
      if(digits[ndx] == 1)
         lastDigit = ndx;
   }
   for(ndx=1;ndx<lastDigit;ndx++) {
      if(digits[ndx] != 1)
         return 0;
   }
   return temp;
}

main() {
   int ndx, ndx2, pandigital = 0;
   for(ndx=0;ndx<100000001;ndx++){
      primes[ndx] = 0;
   }
   for(ndx=2;ndx<100000001;ndx++) {
      if(primes[ndx] == 0) {
         primes[ndx] = 1;
         for(ndx2=ndx+ndx;ndx2<100000001;ndx2+=ndx) {
            primes[ndx2] = -1;
         }
      }
   }   
   for(ndx=100000000;!pandigital && ndx>2142;ndx--) {
      if(primes[ndx] == 1)
         pandigital = IsPandigital(ndx);
   }
   printf("%d\n", pandigital);
}
