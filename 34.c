#include <stdio.h>

CarryOver(int number[10]) {
   int ndx;
   for(ndx=0;ndx<9;ndx++) {
      if(number[ndx] > 9) {
         number[ndx+1] += number[ndx]/10;
         number[ndx] %= 10;
      }
   }
}

int GetSum(int number[10], int factorials[10]) {
   int sum=0, ndx;
   for(ndx=0;ndx<10;ndx++) {
      if(number[ndx] <10)
         sum+=factorials[number[ndx]];
   }

   return sum;
}

int GetNumber(int number[10]) {
   int sum=0, multiplyer=1, ndx;

   for(ndx=0;ndx<10;ndx++) {
      sum += number[ndx] * multiplyer;
      multiplyer*=10;
   }

   return sum;
}

main() {
   int factorials[10], number[10], ndx, temp, sum=0;
   int count =0;
   for(ndx;ndx<10;ndx++) {
      temp = ndx;
      factorials[ndx] = temp;
      while(--temp > 1) {
         factorials[ndx]*=temp;
      }
      number[ndx] = 0;
   }

   while(number[9]<9) {
      number[0] += 1;
      count++;
      printf("%d\n", count);
      CarryOver(number);
      temp = GetSum(number, factorials);
      if(count == 145)
         printf("%d\n", temp);
      if(temp == GetNumber(number)) {
         sum+=temp;
      }
   }

   printf("%d\n", sum);
}
