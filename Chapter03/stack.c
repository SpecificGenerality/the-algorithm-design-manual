/*----------------------------------------------------------*/
/* stack.c                                                  */
/* Author: Justin Yan                                       */
/*----------------------------------------------------------*/
#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------*/
struct Stack {
   unsigned long ulSize;
   Node_T psFirst;  
};
/*----------------------------------------------------------*/
struct Node {
   void * pvItem;
   Node_T psNext;
};
/*----------------------------------------------------------*/
Stack_T Stack_new() {
   Stack_T psStack;
   psStack = (Stack_T) malloc(sizeof(struct Stack));
   if (psStack == NULL) {
      fprintf(stderr, "%s\n", "malloc failed");
      exit(EXIT_FAILURE);
   }
   psStack -> ulSize = 0;
   psStack -> psFirst = NULL;
   return psStack;
}
/*----------------------------------------------------------*/
void * Stack_pop(Stack_T psStack) {
   Node_T psNode;
   void * pvItem;

   assert(psStack != NULL);
   if (psStack -> psFirst == NULL) {
      return NULL;
   }

   psNode = psStack -> psFirst;
   pvItem = psNode -> pvItem;
   psStack -> psFirst = psNode -> psNext;
   free(psNode);
   psStack -> ulSize--;
   return pvItem;
}
/*----------------------------------------------------------*/
void Stack_free(Stack_T psStack) {

   Node_T psNode;
   Node_T psPrev;
   assert(psStack != NULL);

   psNode = psStack -> psFirst;
   while (psNode != NULL) {
      psPrev = psNode;
      psNode = psNode -> psNext;
      free(psPrev);
   }
   free(psStack);
}
/*----------------------------------------------------------*/
void Stack_push(Stack_T psStack, void * pvItem) {
   Node_T psNode;
   Node_T psFirst;
   assert(psStack != NULL);

   psNode = (Node_T) malloc(sizeof(struct Node));
   if (psNode == NULL) {
      fprintf(stderr, "%s\n", "malloc failure");
      exit(EXIT_FAILURE);
   }
   psFirst  = psStack -> psFirst;
   psNode -> pvItem = pvItem;
   psNode -> psNext = psFirst;
   psFirst -> psNext= psNode;
   psStack -> ulSize++;
}
/*----------------------------------------------------------*/
unsigned long Stack_size(Stack_T psStack) {
   assert(psStack != NULL);
   return psStack -> ulSize;
}

