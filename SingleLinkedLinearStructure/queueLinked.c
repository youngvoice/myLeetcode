#include "queueLinked.h"
Status InitQueue(LinkQueue *Q)
{
		if (InitList_L(&((*Q).front)) != OK)
		{
				printf("init list failure\n");
				return ERROR;
		}
		(*Q).rear = (*Q).front;
		return OK;
}
Status DestoryQueue(LinkQueue *Q)
{
		DestoryList_L(&((*Q).front));
		(*Q).rear = NULL;
		return OK;

}


Status ClearQueue(LinkQueue *Q)
{
		if (ClearList_L((*Q).front) != OK)
		{
				printf("clear failure\n");
				return ERROR;
		}
		(*Q).rear = (*Q).front;
		return OK;
}
Status QueueEmpty(LinkQueue Q)
{
		if (Q.front == Q.rear)
				return TRUE;
		else
				return FALSE;
}
int QueueLength(LinkQueue Q)
{
		return ListLength_L(Q.front);
}


Status GetHead(LinkQueue Q,ElemType *e)
{
		return GetElem_L(Q.front, 1, e);

}
Status EnQueue(LinkQueue *Q, ElemType e)
{
		QueuePtr p;
		p = (QueuePtr)malloc(sizeof(Node));
		if (!p)
				exit(OVERFLOW);
		p->data = e;
		p->next = NULL;
		(*Q).rear->next = p;
		(*Q).rear = p;
		return OK;

		//ListInsert_L();


}

Status DeQueue(LinkQueue *Q, ElemType *e)
{
		ListDelete_L((*Q).front, 1 , e);
		if (ListEmpty_L((*Q).front))
				(*Q).rear = (*Q).front;
		return OK;
}
void QueueTraverse(LinkQueue Q, void(Visit)(ElemType))
{
		ListTraverse_L(Q.front, Visit);
}
