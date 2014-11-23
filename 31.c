#include <stdio.h>

main() {
   int ones, twos, fives, tens, twenties, fifties, hundreds;
   int validCombinations = 1, tempSum;
   
   for(hundreds=0;hundreds<3;hundreds++) {
      for(fifties=0;fifties<5;fifties++) {
         for(twenties=0;twenties<11;twenties++) {
            for(tens=0;tens<201;tens++) {
               for(fives=0;fives<41;fives++) {
                  for(twos=0;twos<101;twos++) {
                     for(ones=0;ones<201;ones++) {
                        tempSum = hundreds*100 + fifties*50 + twenties*20 + tens*10 + fives*5 + twos*2 + ones;
                        if(tempSum == 200)
                           validCombinations++;
                     }
                  }
               }
            }
         }
      }
   } 

   printf("%d\n", validCombinations);
}
