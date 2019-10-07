#include "stackLinked.h" 
void printElem(ElemType e);
int main()
{
		int i;
		StackLinked S;
		ElemType e;
		printf("InitStack()\n");
		if(InitStack(&S) != OK)
				PRINT("init failure\n");
		PressEnter;


		printf("StackEmpty()\n");
		StackEmpty(S)?printf("stack is empty\n"):printf("stack is not empty\n");
		PressEnter;


		printf("push()\n");
		for (i = 0; i < 6; i++)
		{
				if (Push(S,2*i) != OK)
						PRINT("push error\n");

		}
		StackEmpty(S)?printf("stack is empty\n"):printf("stack is not empty\n");
		printf("stack length is %d\n", StackLength(S));
		PressEnter;



		printf("GetTop()\n");
		GetTop(S, &e);
		printf("Top elem is %d\n", e);
		PressEnter;



		printf("StackTraverse()\n");
		StackTraverse(S, printElem);
		PressEnter;


		printf("Pop\n");
		for (i = 0; i < 3; i++)
		{
				Pop(S, &e);
				printf("pop %d\n", e);
		}
		PressEnter;



		printf("StackTraverse()\n");
		StackTraverse(S, printElem);
		PressEnter;



		return 0;
}

void printElem(ElemType e)
{
		printf("elem is %d\n", e);
}
