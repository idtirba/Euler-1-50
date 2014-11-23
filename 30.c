#include <stdio.h>

unsigned long long Pow(unsigned int num, int pow) {
   int temp = num;
   while(--pow) {
      temp*=num;
   }
   return temp;
}

main() {
   unsigned long long ndx, temp, tempSum, answer=0;
   unsigned long long bil, hMil, tMil, mil, hThou, tThou, thou, hun, ten;
   int pow = 5;

   //11, 63245
   for(ndx=11;ndx<(9*9*9*9*9)*7;ndx++) {
      temp = ndx;

      bil = Pow(temp/1000000000, pow);
      temp = temp%1000000000;

      hMil = Pow(temp/100000000, pow);
      temp = temp%100000000;

      tMil = Pow(temp/10000000, pow);
      temp = temp%10000000;

      mil = Pow(temp/1000000, pow);
      temp = temp%1000000;

      hThou = Pow(temp/100000, pow);
      temp = temp%100000;

      tThou =  Pow(temp/10000, pow);
      temp = temp%10000;
      
      thou = Pow(temp/1000, pow);
      temp = temp%1000;
      
      hun = Pow(temp/100, pow);
      temp = temp%100;
      
      ten = Pow(temp/10, pow);
      
      temp = temp%10;
      
      temp = Pow(temp, pow);
      tempSum = bil + hMil + mil + hThou + tThou + thou + hun + ten + temp;
      
      if(tempSum == ndx) 
         answer+=tempSum;
   }
   printf("%llu\n", answer);
}
