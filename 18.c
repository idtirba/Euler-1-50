#include<stdio.h>

main() {

   int size = 0, sum=0, ndx, parent1, parent2, sumNdx;
   int level = 14, levelSize = 14;
   int leftSide = 91, rightSide = 104, leftOffset = 13, rightOffset = 14;  
   int start = 104; 

   for(ndx=1;ndx<16;ndx++) {
      size+=ndx;
   }

   int numbers[size], sums[size];
   FILE *fp = fopen("18.txt", "r");

   for(ndx=0;ndx<size;ndx++) {
      fscanf(fp, "%d", &numbers[ndx]);
      sums[ndx] = 0;
      if(ndx>104)
         sums[ndx] = numbers[ndx]; 
   }

   

}
