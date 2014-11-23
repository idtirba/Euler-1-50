#include <stdio.h>

long Multiple(long numbers[1000], int index) {
   long x, sum = numbers[index];
   for(x=index+1;x<index+13;x++) {
      sum=numbers[x] * sum;
   }
   return sum;
}

main() {

   FILE *fp = fopen("8.txt", "r");

   long numbers[1000], x, largestProduct = 0, temp;

   for(x=0;x<1000;x++) {
      fscanf(fp,"%c", &temp);
      numbers[x] = temp - 48;
      //printf("%d\n", numbers[x]);
   }

   for(x=0;x<988;x++) {
      temp = Multiple(numbers, x);
      if(temp>largestProduct) {
         printf("%d\n", x); 
         largestProduct = temp;
      }
   }

   printf("%ld\n",largestProduct);
}
