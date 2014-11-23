#include <stdio.h>
#define TOTAL 9087654321

//0-9 pandigital
int IsPandigital(int number[10], long multiplyers[9]) {
   int ndx, temp;
   long sum = 0;   
   for(ndx=0;ndx<10;ndx++) {
      temp = number[ndx] - 1;
      if(temp > -1)
         sum += number[ndx] * multiplyers[temp];
   }
   return sum == TOTAL;
}

int GetNumber(int number[10], int start) {
   int ndx, sum = 0, multiplyer = 100;
   for(ndx=start;ndx>start-3;ndx--) {
      sum += number[ndx] * multiplyer;
      multiplyer /= 10;
   }

   return sum;
}

int IsDivisible(int number[10], int divisors[7]) {
   int ndx, temp, start = 8; 
   for(ndx=0;ndx<7;ndx++) {
      temp = GetNumber(number, start--);
      if(temp%divisors[ndx])
         return 0;
   }
   return 1;
}

CarryOver(int number[10]) {
   int ndx;
   for(ndx=0;ndx<9;ndx++) {
      if(number[ndx] > 9) {
         number[ndx+1] += number[ndx]/10;
         number[ndx] %= 10;
      }
   }
}

long GetTotal(int number[10]){
   int ndx;
   long sum=0, multiplyer = 1;

   for(ndx=0;ndx<10;ndx++) {
      sum += number[ndx] * multiplyer;
      multiplyer *= 10;
   }
   return sum;
}

main() {
   int ndx;
   unsigned long long sumTotal=0;
   int divisors[7] = {2, 3, 5, 7, 11, 13, 17};
   int number[10] = {9, 8, 7, 6, 5, 4, 3, 2, 0, 1};
   long count = 0;

   long multiplyers[9] = {1,10,100,1000,10000,100000,1000000,10000000,1000000000};
   while(number[9] != 9 || number[8] != 9) {
      number[0]++;
      if(number[0] > 9)
         CarryOver(number);
      if(IsPandigital(number, multiplyers)) {
         if(IsDivisible(number, divisors)) {
            printf("%ld\n", GetTotal(number));
            sumTotal += GetTotal(number); 
         }
      }
      count++;
   }
   printf("%llu\n", sumTotal);
}
