#include <stdio.h>
#include <stdlib.h>

main(){
   int upperLimit = 3000000;

   while(upperLimit>2000000) {
      printf("Find the number of primes up to what number?(2 million max)\n");
      scanf("%ld", &upperLimit);
      if(upperLimit>2000000)
         printf("error: upperLimit entered greater than 2000000\n");
   }

   upperLimit++;

   int ndx, numberOfPrimes=0, sieveNdx, lastPrime;
   int primes[upperLimit];

   for(ndx=0;ndx<upperLimit;ndx++) {
      primes[ndx] = 0;
   }

   lastPrime = 2;
   for(ndx=lastPrime;ndx<upperLimit;ndx++) {
      if(primes[ndx] == 0) {
         primes[ndx] = 1;
         lastPrime = ndx;
         for(sieveNdx=ndx+lastPrime;sieveNdx<upperLimit;sieveNdx+=lastPrime) {
             primes[sieveNdx] = -1;
         }
      }
   }

   for(ndx=0;ndx<upperLimit;ndx++) {
      if(primes[ndx] == 1)
         numberOfPrimes++;
   }

   printf("There are %d primes at or below %d\n", numberOfPrimes, upperLimit-1);
}
