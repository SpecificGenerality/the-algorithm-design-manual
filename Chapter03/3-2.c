#include "linkedlist.h"
#include "reader.h"
#include <assert.h>
#include <stdio.h>

void LList_reverse(LList_T psLList) {
   Node_T psCurrent;
   Node_T psNext;
   Node_T psPrev;

   assert(psLList != NULL);

   psCurrent = psLList -> psFirst;
   psNext = psCurrent -> psNext;
   psPrev = NULL;

   while (psNext != NULL) {
      psCurrent -> psNext = psPrev;
      psPrev = psCurrent;
      psCurrent = psNext;
      psNext = psNext -> psNext; 
   }

   psLList -> psFirst = psCurrent;
}

int main(void) {
   char * pcLine;
   LList_T psLList;

   while ((pcLine = readLine(stdin)) != NULL) {
      psLList = LList_create(pcLine);
      LList_print(psLList);
      LList_reverse(psLList);
      LList_print(psLList);
      LList_free(psLList)
      free(pcLine)
   }
   return 0;
}