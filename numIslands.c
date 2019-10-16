#ifndef STATUS_H
#define STATUS_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define PressEnter \
{\
		fflush(stdin);\
		printf("Press Enter ...");\
		getchar();\
		fflush(stdin);\
}


#endif
//#include "listSingleLinked.h"

#ifndef LISTSINGLELINKED_H
#define LISTSINGLELINKED_H
#include<stdio.h>
#include<stdlib.h>

#define __DEBUG
#ifdef __DEBUG
#define PRINT(info) printf(info)
#else
#define PRINT(info)
#endif


typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef Node *LinkList;

/*init single linked list*/
Status InitList_L(LinkList *L);
/*clear single linked list, head node is keeped*/
Status ClearList_L(LinkList L);
/*destroy list and head node is also destroyed*/
void DestoryList_L(LinkList *L);
/**/
Status ListEmpty_L(LinkList L);
/**/
int ListLength_L(LinkList L);
/*return ith element of L*/
Status GetElem_L(LinkList L,int i,ElemType *e);

/*return the element position that relation Compare between e and the element hold*/
int LocateElem_L(LinkList L,ElemType e,Status(Compare)(ElemType,ElemType));
/*return previous element of cur_e*/
Status PriorElem_L(LinkList L,ElemType cur_e,ElemType *pre_e);

/*return next element of cur_e*/
Status NextElem_L(LinkList L,ElemType cur_e,ElemType *next_e);

/*insert element e before i_th position*/
Status ListInsert_L(LinkList L,int i,ElemType e);

/*delete element that in i_th position and return to e*/
Status ListDelete_L(LinkList L,int i,ElemType *e);

/**/
Status ListTraverse_L(LinkList L,void(Visit)(ElemType));
/*create list, input element in inverse sequence*/
Status CreateList_HL(FILE *fp,LinkList *L,int n);

/*create list, input element in sequence*/
Status CreateList_TL(FILE *fp,LinkList *L,int n);


#endif

//#include"listSingleLinked.h"

Status InitList_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L))
			exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;

}
Status ClearList_L(LinkList L)
{
	LinkList pre,p;
	if(!L)
			return ERROR;
	pre = L->next;

	while(pre)
	{
			p = pre->next;
			free(pre);
			pre = p;
	}
	L->next = NULL;
	return OK;
}


void DestoryList_L(LinkList *L)
{
		LinkList p = *L;
		while(p)
		{
				p = (*L)->next;
				free(*L);
				(*L) = p;
		}

}

/*why use LinkList *L 
 what relationship between *L and head node
 */
/*
because we take through function to create a head node 
 */
Status ListEmpty_L(LinkList L)
{
		if(L != NULL && L->next == NULL)
				return TRUE;
		else
				return FALSE;
}


int ListLength_L(LinkList L)
{
		LinkList p;
		int i = 0;
	
		if(L)
		{

				i = 0;
				p = L->next;
				while(p)
				{
						i++;
						p = p->next;
				}
		}
		return i;
}


Status GetElem_L(LinkList L,int i,ElemType *e)
{
		int j;
		LinkList p = L->next;

		j = 1;
		//j = 0;//Should this be 0
		p = L->next;
		
		while(p && j < i)
		{
				j++;
				p = p->next;
		}
		if(!p || j > i)
				return ERROR;
		*e = p->data;
		return OK;

}


int LocateElem_L(LinkList L,ElemType e,Status(Compare)(ElemType,ElemType))
{
		int i = -1;
		LinkList p;
		if(L)
		{

				i = 0;
				p = L->next;
				while(p)
				{

						i++;
						if(!Compare(e,p->data))
						{
								p = p->next;
								if(p == NULL)
										i++;//The element to find is not exiting, i > the length of L.

						}
						else
								break;
				}
		}
		return i;

}


Status PriorElem_L(LinkList L,ElemType cur_e,ElemType *pre_e)
{
		LinkList p,suc;

		if(L)
		{
				p = L->next;
				if(p->data != cur_e)
				{
						while(p->next)
						{
								suc = p->next;
								if(suc->data == cur_e)
								{
										*pre_e = p->data;
										return OK;
								}
								p = suc;
						}
				}
		}
		return ERROR;
}


Status NextElem_L(LinkList L,ElemType cur_e,ElemType *next_e)
{
		LinkList pre,p;
		
		if(L)
		{
				pre = L->next;
				while(pre && pre->next)
				{
						p = pre->next;
						if(p && pre->data == cur_e)
						{
								*next_e = p->data;
								return OK;
						}
						if(p)
								pre = p;
						else
								break;
				}
		}
		return ERROR;

}


Status ListInsert_L(LinkList L,int i,ElemType e)
{
		LinkList p,s;
		int j = 0;
		p = L;//?????
		while(p && (j < i - 1))
		{
				p = p->next;
				++j;
		}
		if(!p || j > i-1)//?????
				return ERROR;
		s = (LinkList)malloc(sizeof(Node));
		if(!s)
				exit(OVERFLOW);
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
}


Status ListDelete_L(LinkList L,int i,ElemType *e)
{
		int j;
		LinkList pre, p;
		pre = L;
		j = 1;
		while(pre->next && j<i) //?????????
		{
				++j;
				pre = pre->next;
		}
		if(!pre->next || j > i)
				return ERROR;

		p = pre->next;
		pre->next = p->next;

		*e = p->data;
		free(p);
		return OK;

}



Status ListTraverse_L(LinkList L,void(Visit)(ElemType))
{
		LinkList p;
		if(!L)
				return ERROR;
		else
				p = L->next;
		while(p)
		{
				Visit(p->data);
				p = p->next;
		}
		return OK;
}

/*
Status CreateList_HL(FILE *fp,LinkList *L,int n)
{
		int i;
		LinkList p;
		ElemType tmp;

		*L = (LinkList)malloc(sizeof(Node));
		if(!(*L))
				exit(OVERFLOW);
		(*L)->next = NULL;

		for(i = 1;i <= n;++i)
		{
				if(Scanf(fp,"%d",&tmp)==1)
				{
						p = (LinkList)malloc(sizeof(Node));
						if(!p)
								exit(OVERFLOW);
						p->data = tmp;
						p->next = (*L)->next;
						(*L)->next = p;
				}
				else
						return ERROR;
		}
		return OK;

}


Status CreateList_TL(FILE *fp,LinkList *L,int n)
{
		int i;
		LinkList p,q;
		ElemType tmp;

		*L = (LinkList)malloc(sizeof(Node));
		if(!(*L))
				exit(OVERFLOW);
		(*L)->next = NULL;
		for(i = 1,q = *L; i <= n; ++i)
		{

				if(Scanf(fp,"%d",&tmp)== 1)
				{
						p = (LinkList)malloc(sizeof(Node));
						if(!p)
								exit(OVERFLOW);
						p->data = tmp;
						q->next = p;
						q = p;

				}
				else
						return ERROR;
		}

		q->next = NULL;
		return OK;

}
*/


#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include <stdio.h>
#include <stdlib.h>
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

//#include "queueLinked.h"
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



int numIslands(char (*grid)[5], int gridSize, int *gridColSize)
{
		LinkQueue R, C;
		InitQueue(&R);
		InitQueue(&C);

		int nr = gridSize;
		if (!nr) return 0;
		int nc = *gridColSize;

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
				for (int c = 0; c < nc; ++c) {
						if (grid[r][c] == '1') {
								++num_islands;
								grid[r][c] = '0';

								EnQueue(&R,r);
								EnQueue(&C,c);

								while (!QueueEmpty(R))
								{
										int row, col;
										DeQueue(&R,&row);
										DeQueue(&C,&col);
										if (row - 1 >= 0 && grid[row-1][col] == '1') {
												EnQueue(&R,row-1);
												EnQueue(&C,col);
												grid[row-1][col] = '0';
										}

										if (row + 1 < nr && grid[row+1][col] == '1') {
												EnQueue(&R,row+1);
												EnQueue(&C,col);
												grid[row+1][col] = '0';
										}
										if (col - 1 >= 0 && grid[row][col-1] == '1') {
												EnQueue(&R,row);
												EnQueue(&C,col-1);
												grid[row][col-1] = '0';
										}
										if (col + 1 < nc && grid[row][col+1] == '1') {
												EnQueue(&R,row);
												EnQueue(&C,col+1);
												grid[row][col+1] = '0';
										}



								}

						}
				}
		}

		DestoryQueue(&R);
		DestoryQueue(&C);
		return num_islands;
}

int main()
{
		char grid[4][5] = {{'1','1','1','1','0'},
						   {'1','1','0','1','0'},
						   {'1','1','0','0','0'},
						   {'0','0','0','0','0'}};
		int r = 4;
		int c = 5;
		printf("%d \n",numIslands(grid, r, &c));

}
