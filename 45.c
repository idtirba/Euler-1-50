#include <stdio.h>
#include <math.h>
//**used wolfram alpha for inverse function
//hexagon numbers are a subset of triangle numbers

int IsPentagon(long number) {
   long double inverse = (1+(sqrt(24*number+1)))/6;
   double remainder = fmod(inverse, 1.0);

   return remainder == 0.0;
}

main() {
   int ndx;
   long number = 0, found = 0;
   
   for(ndx=144;!found;ndx++) {
      number = ndx*(2*ndx-1);
      if(IsPentagon(number))
         found = number; 
   }
   
   printf("%ld\n", number);
}
