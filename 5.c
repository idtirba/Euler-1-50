#include <stdio.h>

int CheckFactors(int number) {
   int x;
   int y = 0;
   for(x=20;x>0;x--){
      if(number%x)
         return 0;
   }
   return number;
}

main(){
   int x, answer = 0;
   for(x=2520;!answer;x++){
      answer = CheckFactors(x);
   }
   printf("%d\n",answer);
}
