#include <stdio.h>

int SumOfDivisors(int number) {
   int ndx, sum=0; 
   for(ndx=1;ndx<number;ndx++){
      if(number%ndx == 0) 
         sum+=ndx;
   }
   return sum;
}

Add(int num1, int num2, int list[5000]) {
   int ndx;
   
   printf("%d, %d\n", num1, num2);
   
   for(ndx=0;ndx<5000;ndx++) {
      if(list[ndx] == num1)
         break;
      if(list[ndx] == 0) {
         list[ndx] = num1;
         break;
      }
   }
   
   for(ndx=0;ndx<5000;ndx++) {
      if(list[ndx] == num2) 
         break;
      if(list[ndx] == 0) {
         list[ndx] = num2;
         break;
      }
   }
}

main() {
   int numbers[10001], ndx, sum=0, ndx2, list[5000];
   
   for(ndx=0;ndx<5000;ndx++) {
      list[ndx] = 0;
   }
   
   for(ndx=1;ndx<10001;ndx++) {
      numbers[ndx] = SumOfDivisors(ndx);
   }
   
   for(ndx=1;ndx<10000;ndx++) {
      for(ndx2=ndx+1;ndx2<10001;ndx2++) {
         if(numbers[ndx2] && ((numbers[ndx] == ndx2)&& (numbers[ndx2]==ndx))) {
            Add(ndx, ndx2, list);
         }
      }
   }
   
   sum = 0;
   
   for(ndx=0;list[ndx];ndx++) {
       //printf("%d, ", list[ndx]);
      sum+=list[ndx];
   }
   
   printf("sum: %d\n", sum);
}