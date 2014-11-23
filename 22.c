#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nameStruct {
   char *name;
   struct nameStruct *next;
} nameStruct;

main() {

   nameStruct *head = calloc(1, sizeof(nameStruct)), *current = head, *temp;
   char tempString[30], tempChar;
   FILE *names  = fopen("22.txt", "r");
   int ndx, stringSize, stringSum, namePlace = 1;
   unsigned long totalSum = 0;


   while(fscanf(names, "%c", &tempChar)!=EOF) {
      if(tempChar == '"') {
         ndx = 0;
         while(fscanf(names, "%c", &tempChar) != EOF && tempChar != ',') {
            tempString[ndx++]  = tempChar;
         }
         tempString[ndx-1] = '\0';
         stringSize = ndx + 1;
         current = head;
         while(current->next && strcmp(current->next->name, tempString) < 0) {
            current = current->next;
         }
         temp = calloc(1, sizeof(nameStruct));
         temp->name = malloc(stringSize);
         strcpy(temp->name, tempString);
         temp->next = current->next;
         current->next = temp;
      }   
   }
   current = head->next;
   while(current) {
      stringSum = 0;
      ndx = 0;
      tempChar = current->name[ndx];
      while(tempChar != '\0') {
         stringSum+=tempChar - 64;
         //printf("%c", current->name[ndx]);
         ndx++;
         tempChar = current->name[ndx];
      }
      //printf("%c", ' ');
      printf("(%d * %d):", stringSum, namePlace);
      totalSum += (stringSum * namePlace++);
      printf("%s ", current->name);
      current = current->next;
   }
   printf("\n%lu names: %d\n", totalSum, namePlace);
}
