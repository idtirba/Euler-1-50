#include<stdio.h>

main() {
   int letterCount=0, ndx;

   letterCount+=11; //1000

   for(ndx=100;ndx<1000;ndx++) {
      if(ndx%100)
         letterCount+=3; //count ands
   }

   for(ndx=0;ndx<10;ndx++){
      letterCount+=(3+3+5+4+4+3+5+5+4+3); //1-10
      letterCount+=(6+6+8+8+7+7+9+8+8); //11-19
      letterCount+=(6+6+5+5+5+7+6+6)*10; //20-90, by 10's
      letterCount+=((3+3+5+4+4+3+5+5+4)*8); //1-9 for 20's-90's
   }

   letterCount+=((3+3+5+4+4+3+5+5+4)*100); //1-9 before hundred
   letterCount+=(7*900);//hundreds 100-999

   printf("%d\n", letterCount);
}
