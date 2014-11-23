#include <stdio.h>
#include <stdlib.h>

int primes[1061];

//returns 1 if digits match(not in order) 0 otherise
int MatchingDigits(int x, int y, int size) {
   int a[size], b[size], ndx, ndx2;
   for(ndx=0;ndx<size;ndx++) {
      a[ndx] = x%10;
      b[ndx] = y%10;
      x/=10;
      y/=10;
   }
   for(ndx=0;ndx<size;ndx++) {
      for(ndx2=0;ndx2<size;ndx2++) {
         if(a[ndx] == b[ndx2]) {
            a[ndx] = 0;
            b[ndx2] = 0;
            break;
         }
      }
   }
   for(ndx=0;ndx<size;ndx++) {
      if(a[ndx] || b[ndx])
         return 0;
   }
   return 1;
}

void Matcher(int base, int matches[24], int matchSize) {
   int ndx1, ndx2, ndx3;
   for(ndx1=0;ndx1<matchSize;ndx1++) {
      for(ndx2=ndx1+1;ndx2<matchSize;ndx2++) {
         for(ndx3=ndx2+1;ndx3<matchSize;ndx3++) {
            if(matches[ndx2] - matches[ndx1] == matches[ndx3] - matches[ndx2]) {
               printf("%d %d %d\n", matches[ndx1],matches[ndx2],matches[ndx3]);
               exit(0);
            }
         }
      }
   }
}

main() {
   FILE *fp = fopen("49.txt", "r");
   int ndx, matchSize, ndx2;
   int matches[24];
   for(ndx=0;ndx<1061;ndx++) {
      fscanf(fp,"%d", &primes[ndx]);
   }
   fclose(fp);
   for(ndx=0;ndx<1061;ndx++) {
      matchSize = 0;
      for(ndx2=ndx+1;ndx2<1061;ndx2++) {
         if(MatchingDigits(primes[ndx], primes[ndx2], 4)){
            matches[matchSize] = primes[ndx2];
            matchSize++;
         }
         Matcher(primes[ndx], matches, matchSize);
      }
   }
}
