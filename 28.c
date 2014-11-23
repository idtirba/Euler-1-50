#include <stdio.h>

main() {
   int sideLength=1001, last=1002001, sum = 1;
   for(sideLength=1001;sideLength>2;sideLength-=2) {
      sum+=last;
      last-=(sideLength-1);
      sum+=last;
      last-=(sideLength-1);
      sum+=last;
      last-=(sideLength-1);
      sum+=last;
      last-=(sideLength-1);   
   }
   printf("%d\n", sum);
}
