#include<stdio.h>

main() {

   int size = 0, ndx, child1, child2, sumNdx;
   int level = 14, levelSize = 14;
   int leftSide = 91, rightSide = 104, leftOffset = 13, rightOffset = 14;   

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

   for(ndx=104;ndx>=0;ndx--) {
      child1 = sums[ndx+level];
      child2 = sums[ndx+level+1];
      if(child1 >= child2)
         sums[ndx] = numbers[ndx] + child1;
      else
         sums[ndx] = numbers[ndx] + child2;

      levelSize--;
      if(!levelSize){
         level--;
         levelSize=level;
      }
   }

   printf("%d\n", sums[0]);
}
