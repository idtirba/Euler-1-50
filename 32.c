#include <stdio.h>
#include <stdlib.h>

int Digits(int num) {
   if(num<10 && num>0)
      return 1;
   else if(num < 100)
      return 2;
   else if(num<1000)
      return 3;
   else if(num<10000)
      return 4;

   return 0;
}

int CheckPandigital(int x, int y, int temp, int check[10]) {
   int checkSum = 0, digit;
   while(x) {
      digit=x%10;
      checkSum+=check[digit];
      x/=10;
   }
   while(y) {
      digit=y%10;
      checkSum+=check[digit];
      y/=10;
   }
   while(temp) {
      digit=temp%10;
      checkSum+=check[digit];
      temp/=10;
   }
   return checkSum == 987654321;
}

main() {
   int x, y, temp, sumPandigital=0;
   int check[10] = {-2,1,20,300,4000,50000,600000,7000000,80000000,900000000};
   int *doubleCheck = calloc(100000000, 1);
   
   for(x=0;x<10000;x++) {
      for(y=0;y<10000;y++) {
         temp = x*y;
         if(Digits(x) + Digits(y) + Digits(temp) == 9) {
            if(CheckPandigital(x,y,temp, check)) {
               if(!doubleCheck[temp]){
                  sumPandigital+=temp;
                  doubleCheck[temp] = 1;
               }
            }
         }
      }
   }
   printf("%d\n", sumPandigital);
}
