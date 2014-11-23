#include <stdio.h>

int IsPrime(int number) {
   int ndx;
   for(ndx=2;ndx<number;ndx++) {
      if(number%ndx == 0)
         return 0;
   }
   return 1;
}

int ConsecutivePrimes(int a, int b, int primes[100000]) {
   int numPrimes = 0, n, eval;
   for(n=0;n<1000;n++) {
      eval = (n*n)+(a*n) + b;
      if(primes[(eval)])
         numPrimes++;
      else
         break;
   }
   return numPrimes;
}

main() {

   int primes[100000], ndx, solutionProduct = 0, mostPrimes=0;
   int a, b, tempPrimes;

   for(ndx=0;ndx<100000;ndx++) {
      primes[ndx] = IsPrime(ndx);
   }

   for(a=-999;a<1000;a++) {
      for(b=-999;b<1000;b++) {
         tempPrimes = ConsecutivePrimes(a,b,primes);
         if(tempPrimes > mostPrimes){
            mostPrimes = tempPrimes;
            solutionProduct = a*b;
            printf("%d,%d - %d\n", a,b,mostPrimes);
         }
      }
   }
   printf("%d, %d\n", solutionProduct, mostPrimes);
}
