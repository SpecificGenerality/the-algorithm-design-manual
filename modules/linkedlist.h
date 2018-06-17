/*----------------------------------------------------------*/
/* linkedlist.h                                             */
/* Author: Justin Yan                                       */
/*----------------------------------------------------------*/
#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED
typedef struct LList * LList_T;
typedef struct Node * Node_T;
/*----------------------------------------------------------*/
void LList_insert(LList_T psLList, void * pvItem);
/*----------------------------------------------------------*/
int LList_delete(LList_T psLList, void * pvItem);
/*----------------------------------------------------------*/
LList_T LList_new();
/*----------------------------------------------------------*/
void LList_free(LList_T psLList);
/*----------------------------------------------------------*/
#endif