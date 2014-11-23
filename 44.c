#include <stdio.h>
#include <stdlib.h>

char PentNumbers[100000000];

main() {
   int ndx, tempSum=0, size=0, current;
   int sum, difference;
   int numbers[8165];
   for(ndx=0;ndx<100000000;ndx++) {
      PentNumbers[ndx] = 0;
   }
   tempSum = (1*(3*1 - 1))/2;
   for(ndx=2;tempSum<100000000;ndx++) {
      PentNumbers[tempSum] = 1;
      numbers[size] = tempSum;
      tempSum = (ndx*(3*ndx-1))/2;
      size++;
   }
   for(current=0;current<8165;current++) {
      for(ndx=current+1;numbers[current]+numbers[ndx]<100000000;ndx++) {
         sum = numbers[current] + numbers[ndx];
         if(sum < 1000000000 && PentNumbers[sum]) {
            difference = numbers[ndx] - numbers[current];
            if(difference > 0 && PentNumbers[difference]) {
               printf("%d,%d:%ld\n", numbers[current], numbers[ndx], numbers[ndx]-numbers[current]);
            }
         }
      }
   }
}
