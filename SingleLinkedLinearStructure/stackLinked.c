#include "stackLinked.h"
Status InitStack(StackLinked *S)
{
		return InitList_L(S);
}
Status DestroyStack(StackLinked *S)
{
		DestoryList_L(S);
		return OK;
}

Status ClearStack(StackLinked S)
{
		return ClearList_L(S);
}


Status StackEmpty(StackLinked S)
{
//		return ClearList_L(S); ???????????? how to debug
		return ListEmpty_L(S);
}


int StackLength(StackLinked S)
{
		return ListLength_L(S);
}



Status GetTop(StackLinked S, ElemType *e)
{
		return GetElem_L(S, 1, e);
}
/*
//Status GetElem_L(Linklist L,int i,ElemType *e)
Status GetTop(StackLinked S,ElemType *e)
{
		GetElem(S,1,*e);
}
*/

//Status ListInsert_l(LinkList L, int i,ElemType e)
/*
 
Status Push(StackLinked S, ElemType e)
{
	ListInsert_L(S,1,*e);
}
 */
Status Push(StackLinked S, ElemType e)
{

		return ListInsert_L(S, 1, e);
}
/*
 * //Status ListDelete_L(LinkList L, int i,ElemType *e)
Status Pop(StackLinked S, ElemType *e)
{
 ListDelete_L(S,1,*e);
}

 * */

Status Pop(StackLinked S, ElemType *e)
{
		return ListDelete_L(S, 1, e);
}


Status StackTraverse(StackLinked S, void(Visit)(ElemType))
{
		return ListTraverse_L(S, Visit);
}
