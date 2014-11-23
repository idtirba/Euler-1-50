#include <stdio.h>
#include <math.h>
#define size 1000000

int IsMatch(int composite, int primes[size]) {
   int curSum, ndx;
   for(ndx=composite-1;ndx>1;ndx--) {
      if(primes[ndx] == 1) {
         curSum = composite - ndx;
         if(curSum % 2){
         }
         else {
            curSum/=2;
            if(fmod(sqrt((double)curSum),1.0) == 0.0)
               return 0;
         }
      }
   }
   return composite;
}

//oddComposite = not prime that is odd
main() {
   int primes[size], found = 0;
   int ndx, ndx2, composite = 0;
   for(ndx=0;ndx<size;ndx++) {
      primes[ndx] = 0;
   }
   //sieve for primes
   for(ndx=2;ndx<size;ndx++){
      if(!primes[ndx]){
         primes[ndx] = 1;
         for(ndx2=ndx+ndx;ndx2<size;ndx2+=ndx) {
            primes[ndx2] = -1;
         }  
      }
   }
   for(ndx=4;!found && composite < size;ndx++) {
      for(ndx2=ndx;ndx2<size;ndx2++) {
         if(primes[ndx2]!=1 && primes[ndx2] % 2) {
            composite = ndx2;
            break;
         }
      }
      if(composite%2)
         found = IsMatch(composite, primes);
   }
   printf("%d\n", found);
}
