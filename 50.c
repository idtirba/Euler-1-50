#include <stdio.h>
#include <stdlib.h>
#define SIZE 78498
#define LIMIT 1000000
//78498 primes below 1000000
//Primes 50.txt found using primes.c

int primes[SIZE];
char isPrime[LIMIT];

main(){
   FILE *fp = fopen("50.txt","r");
   int ndx, ndx2, longest=0, start, curLength, tempMax, temp;
   long tempSum;
   for(ndx=0;ndx<LIMIT;ndx++) {
      isPrime[ndx] = 0;
   }
   for(ndx=0;ndx<SIZE;ndx++) {
      fscanf(fp,"%d",&temp);
      isPrime[temp] = 1;
      primes[ndx] = temp;
   }
   for(ndx=0;ndx<SIZE;ndx++) {
      tempSum = primes[ndx];
      curLength = 1;
      tempMax = 1;
      for(ndx2=ndx+1;ndx2<SIZE&&tempSum+primes[ndx2]<LIMIT;ndx2++) {
         tempSum+=primes[ndx2];
         curLength++;
         if(isPrime[tempSum] == 1){
            tempMax = curLength;
         }
      }
      if(tempMax > longest) {
         longest = tempMax;
         start = ndx;
      }
   }
   tempSum = 0;
   for(ndx=start;ndx<start+longest;ndx++) {
      tempSum += primes[ndx];
   }
   printf("start:%d,length:%d,Sum:%d\n", primes[start], longest, tempSum);
}
