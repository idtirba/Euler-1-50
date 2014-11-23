#include <stdio.h>

void reduce(int additive[10]) {
   int ndx;
   for(ndx=0;ndx<10;ndx++) {
      if(additive[ndx]>9) {
         if(ndx < 9)
            additive[ndx+1] += additive[ndx]/10;
         additive[ndx] = additive[ndx]%10;
      }
   }
}

void power(int additive[10], int count) {
   int iterations = count, ndx;
   while(iterations-- > 1) {
      for(ndx=0;ndx<10;ndx++) {
         additive[ndx] *= count;
      }
      reduce(additive);
   }
}

void add(int sum[10], int additive[10]) {
   int ndx;
   for(ndx=0;ndx<10;ndx++) {
      sum[ndx] += additive[ndx];
   }
   reduce(sum);
}

void print(int sum[10]) {
   int ndx;
   for(ndx=9;ndx>=0;ndx--){
      printf("%d", sum[ndx]);
   }
   printf("\n");
}

main() {
   int additive[10], ndx, count;
   int sum[10] = {0,0,0,0,0,0,0,0,0,0};

   for(count=1;count<1001;count++) {
      for(ndx=0;ndx<10;ndx++) {
         additive[ndx]=0;
      }
      additive[0] = count;
      reduce(additive);
      power(additive, count);
      add(sum, additive);
   }
   print(sum);
}
