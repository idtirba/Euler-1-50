#include <stdio.h>
#include <math.h>

main() {
   double c;
   int pMax = 1001;
   int triangleCount[pMax], ndx;
   int ndxA, ndxB, largest=0, perimeter;

   for(ndx=0;ndx<pMax;ndx++) {
      triangleCount[ndx] = 0;
   }

   for(ndxA=1;ndxA<1000;ndxA++) {
      for(ndxB=1;ndxB<1000;ndxB++) {
         c = sqrt(ndxA * ndxA + ndxB * ndxB);
         if(c<1000 && fmod(c, 1.0) == 0) {
            perimeter = ndxA + ndxB + (int)c;
            triangleCount[perimeter]++;
         }
      }
   }

   ndxA = 0;
   for(ndx=0;ndx<1001;ndx++) {
      if(triangleCount[ndx] > largest) {
         largest = triangleCount[ndx];
         ndxA = ndx;
         printf("%d:%d\n", ndxA, largest);
      }
   }

   printf("%d\n", ndxA);
}
