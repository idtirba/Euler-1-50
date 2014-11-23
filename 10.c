#include <stdio.h>

int IsPrime(long number) {
   int x;
   for(x=2;x<number;x++){
      if(number%x == 0)
         return 0;
   }
   return 1;
}

main() {
   long x,sum = 2;
   for(x=3;x<2000000;x+=2){
      if(IsPrime(x))
         sum+=x;
   }
   printf("%ld\n", sum);
}
