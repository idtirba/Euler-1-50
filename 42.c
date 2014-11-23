#include <stdio.h>
#include <stdlib.h>

main() {
   FILE *fp = fopen("42.txt", "r");
   int ndx, tempSum=0, triangleCount=0;
   char triangleNumbers[10000], currentChar;

   for(ndx=0;ndx<10000;ndx++) {
      triangleNumbers[ndx] = 0;
   }
   for(ndx=1;tempSum<10000;ndx++) {
      tempSum = ndx*(ndx+1) / 2;
      if(tempSum<10000)
         triangleNumbers[tempSum] = 1;
   }
   tempSum = 0;
   while(fscanf(fp, "%c", &currentChar) != EOF) {
      if(currentChar == '"')
         tempSum += 0;
       else if(currentChar == ','){
          if(tempSum < 10000) {
             if(triangleNumbers[tempSum] == 1)
                triangleCount++;
          }
          else
             printf("oops... over 10000\n");
          tempSum = 0;
       }
      else
         tempSum += currentChar - 64;
   }
   if(triangleNumbers[tempSum] == 1)
      triangleCount++;

   printf("%d\n", triangleCount);
}
