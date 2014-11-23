#include <stdio.h>

main(){
   int sumOfSquares = 0, squareOfSum = 0, x;

   for(x=1;x<101;x++){
      squareOfSum+=x;
      sumOfSquares+=x*x;
   }

   squareOfSum = squareOfSum * squareOfSum;
   printf("difference = %d\n", squareOfSum - sumOfSquares);
}
