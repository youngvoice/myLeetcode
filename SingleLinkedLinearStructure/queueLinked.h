#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#include "listSingleLinked.h"
typedef Node *QueuePtr;
typedef struct{
		QueuePtr front;
		QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestoryQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
/* return queue head element*/
Status GetHead(LinkQueue Q,ElemType *e);
Status EnQueue(LinkQueue *Q, ElemType e);
Status DeQueue(LinkQueue *Q, ElemType *e);
void QueueTraverse(LinkQueue Q, void(Visit)(ElemType));


#endif
