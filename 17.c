#include <stdio.h>

main() {

   int letters[100], ndx, letterCount = 0, hundred = 7, thousand = 8;
   int current, count, digit;

   for(ndx=0;ndx<100;ndx++) {
      letters[ndx] = 0;
   }

   letters[1] = 3; letters[2] = 3; letters[3] = 5; letters[4] = 4;
   letters[5] = 4; letters[6] = 3; letters[7] = 5; letters[8] = 5;
   letters[9] = 4; letters[10] = 3; letters[11] = 6; letters[12] = 6;
   letters[13] = 8; letters[14] = 8; letters[15] = 7; letters[16] = 7;
   letters[17] = 9; letters[18] = 8; letters[19] = 8; letters[20] = 6; 
   letters[30] = 6; letters[40] = 5; letters[50] = 5; letters[60] = 5; 
   letters[70] = 7; letters[80] = 6; letters[90] = 6;

   for(count=1;count<1001;count++) {
      printf("%d\n", count);
      if(count>100 && (count%100) > 0) //and
         letterCount+=3;
      
      current = count;

      digit = current/1000;
  
      if(digit > 0) {
         letterCount+=thousand;
         letterCount+=3;
         current = current % (digit * 1000);
      }

      digit = current/100;

      if(digit > 0) {
         letterCount+=hundred;
         for(ndx=9;ndx>0;ndx--) {
            if(digit % letters[ndx] == 0) {
               letterCount += letters[ndx];
               break;
            }
         }
         current = current % (digit * 100);
      }
      
      digit = current/10;

      if(digit > 1) {
         for(ndx=90;ndx>0;ndx--) {
            if(letters[ndx]>0 && digit % letters[ndx] == 0) {
               letterCount += letters[ndx];
               break;
            }
         }
         current = current % (digit * 10);
      }
      
      if(current>0) {
         for(ndx=19;ndx>0;ndx--) {
            if(letters[ndx]>0 && (digit % letters[ndx] == 0)) {
               letterCount += letters[ndx];
               break;
            }
         }
      }
   }
   
   printf("%d\n", letterCount);
}
