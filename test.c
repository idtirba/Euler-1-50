#include <stdio.h>
#include <stdlib.h>

main(){
   FILE *fp =  fopen("in.txt", "r");

   int x;

   while(fscanf(fp, "%c",&x)!=EOF) {
      printf("%c\n", x);
   }
}
