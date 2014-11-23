#include <stdio.h>
#include <stdlib.h>

int getNumber(int *digits, int size, int rotation) {
   int ndx, sum=0, temp, multiplyer=1;   
   int digitsCopy[size];

   for(ndx=0;ndx<size;ndx++) {
      digitsCopy[ndx] = digits[ndx];
   }


   while(rotation--) {
      temp = digitsCopy[0];
      for(ndx=0;ndx<size-1;ndx++) {
         digitsCopy[ndx] = digitsCopy[ndx+1];
      }
      digitsCopy[size-1] = temp;
   }

   for(ndx=0;ndx<size;ndx++) {
      sum+=digitsCopy[ndx] * multiplyer;
      multiplyer*=10;
   }

   return sum;
}

int IsCircular(int number, int primes[1000001]) {
   int temp = number, size = 0, ndx, primeMatches=0;
   int ndx2;

   while(temp) {
      size++;
      temp/=10;
   }
   int digits[size];
   temp = number;
   for(ndx=0;ndx<size;ndx++) {
      digits[ndx] = temp%10;
      temp/=10;
   }
   for(ndx=1;ndx<=size;ndx++) {
      temp = getNumber(digits, size, ndx);
      if(primes[temp] == 1) 
         primeMatches++;
   }
   return primeMatches == size;
}

main(){
   int ndx, numberOfPrimes=0, sieveNdx, lastPrime, upperLimit = 1000001;
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

   for(ndx=0;ndx<1000000;ndx++) {
      if(primes[ndx] == 1) {
         if(IsCircular(ndx, primes)){
            numberOfPrimes++;
         }
      }
   }
   printf("%d\n", numberOfPrimes);
}
