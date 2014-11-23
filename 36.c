#include <stdio.h>

int IsDecimalPalindrome(int number, int size) {
   int digits[size], ndx, temp=size;
   for(ndx=0;ndx<size;ndx++) {
      digits[ndx] = number%10;
      number/=10;
   }
   for(ndx=0;size > 1;ndx++, size-=2) {
      if(digits[ndx] != digits[temp-ndx-1])
         return 0;
   }
   return 1;
}

int GetBinarySize(int decimal) {
   int ndx=2, size=1;
   while(decimal>ndx-1) {
      ndx*=2;
      size++;
   }
   return size;
}

int IsBinaryPalindrome(int bits[21], int size) {
   int ndx, temp=size;
   for(ndx=0;size>1;ndx++, size-=2) {
      if(bits[ndx] != bits[temp-1-ndx])
         return 0;
   }
   return 1;
}

CarryOver(int bits[21]) {
   int ndx;
   for(ndx=0;ndx<20;ndx++) {
      if(bits[ndx] > 1) {
         bits[ndx+1]+=bits[ndx]/2;
         bits[ndx]%=2;
      }
   }
}

main() {
   int bits[21], ndx, decimal=0, decimalSize=1, palindromeSum=0;
   int limit=1000000, binarySize=1, temp, decimalLimit=10;

   for(ndx=0;ndx<21;ndx++) {
      bits[ndx]=0;
   }   
   
   while(limit--) {
      bits[0]++;
      decimal++;
      if(decimal==decimalLimit) {
         decimalSize++;
         decimalLimit*=10;
      }
      CarryOver(bits);
      binarySize = GetBinarySize(decimal);
      if(IsBinaryPalindrome(bits, binarySize) && IsDecimalPalindrome(decimal, decimalSize)) {
         printf("%d : ", decimal, decimalSize);
         for(temp=0;temp<binarySize;temp++) {
            printf("%d", bits[temp]);
         }
         printf("\n", binarySize);
         palindromeSum += decimal;
      }
   }
   printf("Sum of Palindromes of both bases: %d\n", palindromeSum);
}
