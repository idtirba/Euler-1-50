#include <stdio.h>

//successful returns new concatNdx, else 0
int AddNumber(int number, int size, int concatNdx, int concatNumber[9]) {
   if(size+concatNdx > 9)
      return 0;
   int digits[size], offSet = concatNdx, ndx;
   for(ndx=0;ndx<size;ndx++) {
      digits[ndx] = number%10;
      number/=10;
   }
   for(ndx=0;ndx<size;ndx++) {
      concatNumber[concatNdx+ndx] = digits[size-ndx-1];
   }
   return concatNdx+size;
}

int IsPandigital(int number) {
   int multiplyer = 1, concatNumber[9], ndx, temp, tempSize;
   int numberSize = GetSize(number), sizeSum=0, concatNdx=0;
   int digitCheck[9];
   for(ndx=0;ndx<9;ndx++) {
      concatNumber[ndx] = 0;
      digitCheck[ndx] = 0;
   }
   while(sizeSum<10) { 
      temp = number*multiplyer;
      tempSize = GetSize(temp);
      sizeSum += tempSize;
      concatNdx = AddNumber(temp, tempSize, concatNdx, concatNumber);
      multiplyer++;
   }
   for(ndx=0;ndx<9;ndx++) {
      digitCheck[(concatNumber[ndx]-1)]++;
   }  
   for(ndx=0;ndx<9;ndx++) {
      if(digitCheck[ndx] != 1)
         return 0;
   } 

   return GetNumber(concatNumber);
}

int GetNumber(int concatNumber[9]) {
   int sum = 0, ndx, multiplyer = 100000000;
   for(ndx=0;ndx<9;ndx++) {
      sum+=concatNumber[ndx] * multiplyer;
      multiplyer /= 10;
   }
   return sum;
}

int GetSize(int number) {
   int size=0;
   while(number) {
      size++;
      number/=10;
   }
   return size;
}

//domain should be 1-333, 5000-9999
main() {
   int maxProduct = 0, ndx, tempProduct;
   for(ndx=1;ndx<10000;ndx++) {
      tempProduct = IsPandigital(ndx);
      if(tempProduct > maxProduct) {
         //printf("%d:%d\n", ndx, tempProduct);
         maxProduct = tempProduct;
      }
      if(ndx==333)
         ndx=5000;
   }
   printf("%d\n", maxProduct);
}
