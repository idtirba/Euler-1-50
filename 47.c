#include <stdio.h>
#define size 1000000

char primes[size];

int PrimeFactors(int number) {
   int count=0, ndx, ndx2, factors[10], factorSize=0;
   
   while(number > 1) {
      for(ndx=0;ndx<size;ndx++) {
         if(primes[ndx] == 1)
            if(number % ndx == 0) {
               factors[factorSize] = ndx;
               factorSize++;
               number /= ndx;
               break;
            }
      }
   }
   for(ndx=0;ndx<factorSize;ndx++) {
      for(ndx2=ndx+1;ndx2<factorSize;ndx2++) {
         if(factors[ndx2] == factors[ndx])
            factors[ndx2] = 0;
      }   
   }
   for(ndx=0;ndx<factorSize;ndx++) {
      if(factors[ndx])
         count++;
   }
   return count;
}

main() {
   int ndx, ndx2, count=0;
   for(ndx=0;ndx<size;ndx++) {
      primes[ndx] = 0;
   }
   for(ndx=2;ndx<size;ndx++) { 
      if(!primes[ndx]) {
         primes[ndx] = 1;
         for(ndx2=ndx*2;ndx2<size;ndx2+=ndx) {
            primes[ndx2]=-1;
         }
      }
   }
   ndx=643;
   while(count<4) {
      ndx++;
      if(PrimeFactors(ndx)==4)
         count++;
      else
         count=0;
   }
   printf("%d\n", ndx-3);
}
