#include <stdio.h>

//Euler Problem 37
/*The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.*/
//Approach, start from first prime 11, and search till the next 10 primes are found

//check if number is prime left to right
int IsMatchingPrime(int number, int size, int primes[2000001]){
   int digits[size], ndx, primeNdx, multiplyer, combinations = (size-1)*2+2;
   int tempSum;

   for(ndx=0;ndx<size;ndx++) {
      digits[ndx] = number%10;
      number/=10;
   }
   //sort left to right 321 -> 21 -> 1
   for(ndx=size-1;ndx>=0;ndx--) {
      multiplyer = 1;
      tempSum = 0;
      for(primeNdx=0;primeNdx<=ndx;primeNdx++) {
         tempSum += digits[primeNdx]*multiplyer;
         multiplyer*=10;
      }
      if(primes[tempSum] == 1)
         combinations--;
   }
   
   //check right to left 321 -> 32 -> 3
   for(ndx=0;ndx<size;ndx++) {
      multiplyer = 1;
      tempSum = 0;
      for(primeNdx=ndx;primeNdx<size;primeNdx++) {
         tempSum += digits[primeNdx]*multiplyer;
         multiplyer*=10;
      }
      if(primes[tempSum] == 1)
         combinations--;
   }

   return combinations == 0;
}
//return number of digits in number
int GetSize(int number) {
   int size=0;
   while(number) {
      size++;
      number/=10;
   }
   return size;
}

main() {
   int primes[2000001], ndx, sieveNdx, matchingPrimes=0, primeSum=0;
   for(ndx=0;ndx<2000001;ndx++) {
      primes[ndx] = 0;
   }

   for(ndx=2;ndx<2000001;ndx++) {
      if(primes[ndx] == 0) {
         primes[ndx] = 1;
         for(sieveNdx=ndx+ndx;sieveNdx<2000001;sieveNdx+=ndx) {
            primes[sieveNdx] = -1;
         }
      }
   }
   for(ndx=8;ndx<2000001;ndx++) {
      if(primes[ndx] == 1) {
         if(IsMatchingPrime(ndx, GetSize(ndx), primes)) {
            matchingPrimes++;
            primeSum+=ndx;
            printf("%d:%d\n", matchingPrimes, ndx);
         }
      }
   }
   printf("%d\n", primeSum);
}
