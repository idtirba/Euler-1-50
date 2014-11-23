#include <stdio.h>

main() {
   long x, y, z, answer = 0;

   for(x=0;x<1000;x++) {
      for(y=0;y<1000;y++) {
         for(z=0;z<1000;z++) {
            if(((x*x)+(y*y))==(z*z)){
               if(x+y+z==1000) {
                  answer = x*y*z;
               }
            }
         }
      }
   }

   printf("%ld\n", answer);
}
