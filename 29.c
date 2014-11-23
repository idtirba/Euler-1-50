#include <stdio.h>

main() {
   int terms[10000][210], base, power, size=0, x, y;
   int current[210], temp, ndx, add;

   for(x=0;x<10000;x++) {
      for(y=0;y<210;y++) {
         terms[x][y] = 0;
      }
   }

   for(base=2;base<101;base++) {
      for(power=2;power<101;power++) {
         add=1;
         for(x=0;x<210;x++) {
            current[x] = 0;
         }
         temp = power-1;
         current[0] = base;
         while(temp--) {
            for(x=0;x<209;x++) {
               if(current[x] > 9) {
                  current[x+1] += current[x]/10;
                  current[x] %= 10;
               }
            }
            for(x=0;x<210;x++) {
               current[x] *= base;
            }
         }
         for(x=0;x<209;x++) {
            if(current[x] > 9) {
               current[x+1] += current[x]/10;
               current[x] %= 10;
            }
         }
         for(x=0;x<size;x++) {
            for(y=0;y<210;y++) {
               if(current[y] != terms[x][y]) 
                  break;
               else if(y==209) 
                  add = 0;
            }
         }
         if(add) {
            for(ndx=0;ndx<210;ndx++) {
               terms[size][ndx] = current[ndx];
            }
            size++;
         }
      }
   }
   printf("%d\n", size);
}
