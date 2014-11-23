#include<stdio.h>
#include<math.h>

main(){
   int numbers[1000], x, count = 1000, sum = 0;

   for(x=0;x<1000;x++) {
      numbers[x] = 0;
   }

   numbers[0] = 1;

   while(count--) {
      for(x=0;x<1000;x++) {
         numbers[x] = numbers[x] * 2;
      }
      for(x=0;x<1000;x++){
         if(numbers[x]>9){
            numbers[x+1]+=(numbers[x]/10);
            numbers[x] = (numbers[x])%10;
         }
      }
   }

   for(x=0;x<1000;x++) {
      sum+=numbers[x];
   }

   printf("%d\n",sum);
}
