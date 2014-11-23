#include <stdio.h>

//checks if an integer is prime
int CheckPrime(unsigned long long x) {
   unsigned long long count;
   printf("in check prime\n");
   for(count = 2;count<x;count++){
      if(x%count == 0)
         return 0;   
   }
   return 1; 
}

//largest prime factor of the number 600851475143
main(){
   unsigned long long number = 600851475143;
   int prime = 1, x;
   int six = 0, five = 0, four = 0, three = 0;

   printf("%llu \n",number);
   
   for(x=200000000;x>1;x--) {
      if(number%x == 0){
         printf("multiple: %llu\n", x);
         if(CheckPrime(x)==1){
            prime = x;
            printf("prime!: %llu\n", x);
         }
      }
   }
}
