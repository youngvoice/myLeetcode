#ifndef LISTSINGLELINKED_H
#define LISTSINGLELINKED_H
#include<stdio.h>
#include<stdlib.h>
#include "Status.h"

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

