#ifndef STACKLINKED_H 
#define STACKLINKED_H 

#include "listSingleLinked.h"
#include "Status.h"
#include <stdio.h> 
#include <stdlib.h>
typedef Node *StackLinked;

Status InitStack(StackLinked *S);
Status DestroyStack(StackLinked *S);
Status ClearStack(StackLinked S);

Status StackEmpty(StackLinked S);
int StackLength(StackLinked S);
Status GetTop(StackLinked S, ElemType *e);
Status Push(StackLinked S, ElemType e);
Status Pop(StackLinked S, ElemType *e);
Status StackTraverse(StackLinked S, void(Visit)(ElemType));



#endif

