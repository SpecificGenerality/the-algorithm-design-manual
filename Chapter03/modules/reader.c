#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

char * readLine(FILE *psFile)
{
   /* line length starts at size two characters */
   const size_t INITIAL_LINE_LENGTH = 2;
   /* line length grows by this factor upon resizing*/
   const size_t GROWTH_FACTOR = 2;

   /* number of characters in the string */
   size_t uLineLength = 0;
   /* number of characters that the string can store */
   size_t uPhysLineLength = INITIAL_LINE_LENGTH;
   /* the string storing characters from psFile */
   char *pcLine;
   /* character read in from psFile*/
   int iChar;

   assert(psFile != NULL);

   /* If no lines remain, return NULL. */
   if (feof(psFile))
      return NULL;
   iChar = fgetc(psFile);
   if (iChar == EOF)
      return NULL;

   /* Allocate memory for the string. */
   pcLine = (char*)malloc(uPhysLineLength);
   if (pcLine == NULL)
      {
         fprintf(stderr,"%s\n", 
            "readLine: memory allocation failed");
         exit(EXIT_FAILURE);
      }

   /* Read characters into the string. */
   while ((iChar != '\n') && (iChar != EOF))
   {
      if (uLineLength == uPhysLineLength)
      {
         uPhysLineLength *= GROWTH_FACTOR;
         pcLine = (char*)realloc(pcLine, uPhysLineLength);
         if (pcLine == NULL)
            {
               fprintf(stderr,"%s\n", 
                  "readLine: memory allocation failed");
               exit(EXIT_FAILURE);}
      }
      pcLine[uLineLength] = (char)iChar;
      uLineLength++;
      iChar = fgetc(psFile);
   }

   /* Append a null character to the string. */
   if (uLineLength == uPhysLineLength)
   {
      uPhysLineLength++;
      pcLine = (char*)realloc(pcLine, uPhysLineLength);
      if (pcLine == NULL)
         {
            fprintf(stderr,"%s\n", 
               "readLine: memory allocation failed");
            exit(EXIT_FAILURE);}
   }
   pcLine[uLineLength] = '\0';

   return pcLine;
}