#include <stdio.h>

int IsEqual(int a[210], int b[210]) {
   int ndx;
   for(ndx=0;ndx<210;ndx++) {
      if(a[ndx] != b[ndx])
         return 0;
   }
   return 1;
}

Reduce(int temp[210]) {
   int ndx;
   for(ndx=0;ndx<209;ndx++) {
      if(temp[ndx] > 9) {
         temp[ndx+1] += temp[ndx]/10;
         temp[ndx] = temp[ndx]%10;
      }
   }
}

Initialize(int temp[210], int base) {
   int ndx;
   for(ndx=0;ndx<210;ndx++) {
      temp[ndx] = 0;
   }
   temp[0] = base;
   Reduce(temp);
}

Power(int temp[210], int base, int power) {
   int ndx;
   while(power--) {
      for(ndx=0;ndx<210;ndx++) {
         temp[ndx]= temp[ndx]*base;
      }
      Reduce(temp);
   }
}

//returns 1 if not contained(distinct), 0 otherwise
int IsDistinct(int temp[210], int terms[10000][210], int size) {
   int x, y, ndx=0;
   for(x=0;x<size+1;x++) {
      if(IsEqual(temp, terms[x])) {
         Print(terms[x]);
         printf("NOT DISTINCT! %d SAME AS ", x);
         /*if(x==704) {
            for(ndx=5;ndx>-1;ndx--) {
               printf("%d", temp[ndx]);
            }
            printf("\n");
         }*/
         return 0;
      }
   }
   for(y=0;y<210;y++) {
      terms[size][y] = temp[y];
   }
   return 1;
}

Print(int terms[210]) {
   int ndx;
   for(ndx=209;ndx>-1;ndx--) {
      printf("%d", terms[ndx]);
   }
   printf("\n");
}

main() {
   int terms[10000][210], x, y, temp[210], size=0, ndx;
   for(x=0;x<10000;x++) {
      for(y=0;y<210;y++) {
         terms[x][y] = 0;
      }
   }

   for(x=2;x<101;x++) {
      for(y=2;y<101;y++) {
         Initialize(temp, x);
         Power(temp, x, y);
         if(IsDistinct(temp, terms, size)) {
            printf("%d: %d^%d\n", size, x, y);
            size++;
         }
         else {
            /*if(x==100 && y == 2) {
               for(ndx=5;ndx>-1;ndx--) {
                  printf("%d", temp[ndx]);
               }
               printf("\n");
            }*/
            printf("%d^%d\n", x, y);
         }
      }
   }
   printf("%d\n", size);
}
