/*----------------------------------------------------------*/
/* stack.h                                                  */
/* Author: Justin Yan                                       */
/*----------------------------------------------------------*/
#ifndef STACK_INCLUDED
#define STACK_INCLUDED
typedef struct Stack * Stack_T;
typedef struct Node * Node_T;
/*----------------------------------------------------------*/
Stack_T Stack_new();
/*----------------------------------------------------------*/
void Stack_free(Stack_T psStack);
/*----------------------------------------------------------*/
void * Stack_pop(Stack_T psStack);
/*----------------------------------------------------------*/
void Stack_push(Stack_T psStack, void * pvItem);
/*----------------------------------------------------------*/
unsigned long Stack_size(Stack_T psStack);
/*----------------------------------------------------------*/
#endif 