#include <stdio.h>

int IsPalendrome(int number){
   if(number/100000 == number %10) {
      if((number/10000)%10 == (number/10)%10)
         if((number/1000)%10 == (number/100)%10)
            return 1;
   }
   return 0;
}

int IsFactor(int number) {
   int x;
   for(x=999;x>99;x--) {
      if(number%x == 0 && number/x > 99 && number/x < 999) {
         printf("The solution is %d and %d = %d\n", x, number/x, number);
         return 1;
      }
   }
   return 0;
}


main(){
   int x, solution = 0;
   for(x=998000;!solution;x--) {
      if(IsPalendrome(x))
         solution = IsFactor(x);
   }
}
