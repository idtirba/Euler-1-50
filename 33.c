#include <stdio.h>

int Common(int numX, int numY, int denX, int denY) {
   if(numX == numY)
      return 0;
   if(denX == denY)
      return 0;
   if(numY == 0 && denY ==0)
      return 0;
   if(numX == denX || numX == denY)
      return numX;
   if(numY == denX || numY == denY)
      return numY;

   return 0;
}

int CommonDivisor(int num, int den) {
   int x=den;
   if(num>den)
      x=num;

   if(!x)
      return 0;

   while(x) {
      if(num%x==0 && den%x==0)
         return x;
      x--;
   }
   
   return 0;
}

int CheckTrivial(int numX, int numY, int denX, int denY, int common, int commonDivisor) {
   int newNum, newDen, oldNum = (numX*10+numY)/commonDivisor;
   int oldDen = (denX*10 + denY)/commonDivisor;
   double difference;

   if(numX == common)
      numX = 0;
   if(numY == common)
      numY = 0;
   if(denX == common)
      denX = 0;
   if(denY == common)
      denY = 0;


   newNum = numX*10 + numY;
   newDen = denX*10 + denY;

   if(!newNum||!newDen||!oldNum||!oldDen)
      return 0;

   difference = oldNum/newNum;

   if(difference == 0)
      return 0;

   if(oldDen*difference == newDen || newDen*difference == oldDen)
      return 1;

   return 0;
}

int Remove(int x, int y, int common){
   if(x==common) 
      x=0;
   if(y==common)
      y=0;

   return x + y;
}

main() {
   int numX, numY, denX, denY;
   int productNum=1, productDen=1;
   int tempNum, tempDen, commonDivisor, common;
   int origNum, origDen, redNum, redDen;
   int numberOfFractions = 0, temp;
   double a, b;

   for(numX=1;numX<10;numX++) {
      for(numY=0;numY<10;numY++) {
         for(denX=1;denX<10;denX++) {
            for(denY=1;denY<10;denY++) {
               if(common = Common(numX, numY, denX, denY)) {
                  tempNum = numX*10+numY;
                  tempDen = denX*10+denY;
                  commonDivisor = CommonDivisor(tempNum, tempDen);
                  redNum = Remove(numX,numY,common);
                  redDen = Remove(denX, denY, common);
                  if(tempNum&&tempDen&&redDen && redNum && tempNum != tempDen){
                     a = (double)tempDen / tempNum;
                     b = (double)redDen / redNum;
                     if(a==b && tempNum < tempDen) {
                        printf("%d/%d\n", tempNum, tempDen);
                        numberOfFractions++;
                        productNum*=tempNum;
                        productDen*=tempDen;
                     }
                  }
               }
            }
         }
      }
   }

   commonDivisor = CommonDivisor(productNum, productDen);

   printf("%d fractions whose product is %d/%d\n", numberOfFractions, productNum, productDen);
   printf("This reduces to %d/%d\n", productNum/commonDivisor, productDen/commonDivisor);
}
