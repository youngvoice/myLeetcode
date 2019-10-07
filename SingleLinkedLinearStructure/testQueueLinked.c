#include "queueLinked.h"
void PrintElem(ElemType e);
int main()
{
		int i;
		LinkQueue Q;
		ElemType e;
		printf("InitQueue()\n");
		InitQueue(&Q);
		PressEnter;

		printf("QueueEmpty()\n");
		QueueEmpty(Q)?printf("Queue is empty\n"):printf("Queue is not empty\n");
		PressEnter;

		printf("EnQueue()\n");
		for (i = 1; i <= 6; i++)
		{
				EnQueue(&Q, 2*i);
		}
		PressEnter;

		printf("QueueTraverse()\n");
		QueueTraverse(Q, PrintElem);
		PressEnter;

		printf("QueueLength()\n");
		printf("Queue length is %d\n", QueueLength(Q));
		PressEnter;

		printf("GetHead()\n");
		for (i=0; i < 3; i++)
		{
				GetHead(Q, &e);
				printf("GetHead elem is %d\n", e);
		}
		PressEnter;


		printf("DeQueue()\n");
		for (i=0; i < 3; i++)
		{
				DeQueue(&Q, &e);
				printf("Dequeue elem is %d\n", e);
		}
		PressEnter;
		printf("ClearQueue()\n");
		QueueEmpty(Q)?printf("Queue is Empty\n"):printf("Queue is not Empty\n");
		ClearQueue(&Q);
		QueueEmpty(Q)?printf("Queue is Empty\n"):printf("Queue is not Empty\n");
		PressEnter;


		printf("DestoryQueue()\n");
		Q.front != NULL && Q.rear != NULL? printf("Q exists\n"):printf("Q doesn't exist\n");
		DestoryQueue(&Q);
		Q.front != NULL && Q.rear != NULL? printf("Q exists\n"):printf("Q doesn't exist\n");
		PressEnter;
		return 0;



}

void PrintElem(ElemType e)
{
		printf("%d\n", e);
}


