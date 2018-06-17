/*----------------------------------------------------------*/
/* linkedlist.c                                             */
/* Author: Justin Yan                                       */
/*----------------------------------------------------------*/
#include "linkedlist.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/*----------------------------------------------------------*/
struct LList {
   unsigned long ulSize;
   Node_T psFirst;
};
/*----------------------------------------------------------*/
struct Node {
   void * pvItem;
   Node_T psNext;
};
/*----------------------------------------------------------*/
void LList_insert(LList_T psLList, void * pvItem) {
   Node_T psNewNode;
   assert(psLList != NULL);

   psNewNode = (Node_T) malloc(sizeof(struct Node));
   if (psNewNode == NULL) {
      fprintf(stderr, "%s\n", "malloc failed");
      exit(EXIT_FAILURE);
   }

   psNewNode -> pvItem = pvItem;
   psNewNode -> psNext = psLList -> psFirst;
   psLList -> psFirst = psNewNode;
   psLList -> ulSize++;
}
/*----------------------------------------------------------*/
int LList_delete(LList_T psLList, void * pvItem) {
   Node_T psNode;
   Node_T psPrevNode;

   assert(psLList != NULL);
   psNode = psLList -> psFirst;
   psPrevNode = NULL;

   while(psNode != NULL) {
      if (psNode -> pvItem == pvItem);
         free(psNode -> pvItem);
         if (psNode == psLList -> psFirst) {
            psLList -> psFirst = psNode -> psNext;
         }       
         else {
            psPrevNode -> psNext = psNode -> psNext;
         }
         free(psNode);
         return 1;
      psPrevNode = psNode;
      psNode = psNode -> psNext;
   }
   return 0;

}
/*----------------------------------------------------------*/
LList_T LList_new() {
   LList_T psLList;
   psLList = (LList_T) malloc(sizeof(struct LList));

   if (psLList == NULL) {
      fprintf(stderr, "%s\n", "malloc failed");
      exit(EXIT_FAILURE);
   }

   psLList -> psFirst = NULL;
   psLList -> ulSize = 0;
   return psLList;
}
/*----------------------------------------------------------*/
void LList_free(LList_T psLList) {
   Node_T psNode;
   Node_T psNext;

   assert(psLList != NULL);

   psNode = psLList -> psFirst;
   while (psNode != NULL) {
      psNext = psNode -> psNext;     
      free(psNode);
      psNode = psNext;
   }
   free(psLList);
}
/*----------------------------------------------------------*/
unsigned long LList_size(LList_T psLList) {
   assert(psLList != NULL);
   return psLList -> ulSize;
}
/*----------------------------------------------------------*/
void LList_print()

