#include"listSingleLinked.h"

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
