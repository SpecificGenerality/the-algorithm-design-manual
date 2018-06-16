#include "stack.h"
#include "reader.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum Boolean { FALSE, TRUE };

static int isValid(const char * pcLine) {
   char cChar;
   cChar = *pcLine;
   while (cChar != '\0') {
      if (cChar != '(' || cChar != ')') return FALSE;
   }
   return TRUE;
}
int isValidNesting(const char * pcLine) {
   Stack_T psStack;
   char cChar;
   void * pvPop;
   char * pcLineCpy;
   assert(pcLine != NULL);
   assert(isValid(pcLine));

   psStack = Stack_new();
   pcLineCpy = (char *) pcLine;
   pvPop = NULL;

   while((cChar = *pcLineCpy++) != '\0') {
      if (cChar == '(') Stack_push(psStack, &cChar);
      else pvPop = Stack_pop(psStack);
      if (pvPop == NULL) {
         Stack_free(psStack);
         return FALSE;
      }
   }
   return TRUE;
}

int main(int argc, char *argv[]) {
   char * pcLine;

   while ((pcLine = readLine(stdin)) != NULL)  {
      if (isValidNesting(pcLine)) fprintf(stdout, "%s\n", "valid");
      else fprintf(stdout, "%s\n", "invalid");
      free(pcLine);
   }
}