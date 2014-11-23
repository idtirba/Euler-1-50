#include<stdio.h>

int IsPrime(int number) {
   int x;
   for(x=2;x<number;x++) {
      if(number%x == 0)
         return 0;
   }
   return 1;
}

main(){
   int primes = 1, x;
   for(x=3;primes<10001;x++) {
      primes+=IsPrime(x);
   }
   printf("%d\n",x-1);
}
