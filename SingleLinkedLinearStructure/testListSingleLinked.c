#include "listSingleLinked.h"
void PrintElem(ElemType e);
Status CmpGreater(ElemType e, ElemType data);

int main(int argc, char **argv)
{
		LinkList L;
		int i;
		ElemType e;
		printf("InitList_L\n");
		InitList_L(&L);
		printf("\n");
		PressEnter;

		printf("listEmpty_l\n");
		ListEmpty_L(L)? printf("L is empty\n") : printf("L is not empty\n");
		PressEnter;


		printf("ListInsert_L\n");
		for (i = 1; i <= 6; i++) {
				printf("insert %d in %dth position\n",2*i, i);
				ListInsert_L(L, i, 2*i);
		}
		printf("\n");
		PressEnter;

		printf("ListTraverse_L\n");
		ListTraverse_L(L, PrintElem);
		printf("\n");
		PressEnter;


		printf("ListLength_l\n");
		printf("The length of L is %d\n", ListLength_L(L));
		printf("\n");
		PressEnter;


		printf("ListDelete_L\n");
		ListDelete_L(L, 6, &e);
		printf("The 6th elem deleted is %d\n", e);
		ListTraverse_L(L, PrintElem);
		printf("\n");
		PressEnter;

		printf("GetElem_L\n");
		GetElem_L(L, 4, &e);
		printf("get 4'th elem is %d\n", e);
		printf("\n");
		PressEnter;


		printf("LocateElem_L\n");
		i = LocateElem_L(L, e, CmpGreater);
		printf("the location of elem satisfying great than %d is %d\n", e, i);
		PressEnter;

		printf("PriorElem_L\n");
		PriorElem_L(L, 5, &e) ? printf("the prior elem of 5 is %d\n", e) : printf("prior error\n");;
		printf("\n");
		PressEnter;

		printf("NextElem_L\n");
		NextElem_L(L, 5, &e)? printf("the next elem of 5 is %d\n", e) : printf("next error\n");
		printf("\n");
		PressEnter;

		printf("ClearList_L\n");
		printf("before clear\n");
		ListEmpty_L(L)? printf("L is empty\n") : printf("L is not empty\n");
		ClearList_L(L);
		ListEmpty_L(L)? printf("L is empty\n") : printf("L is not empty\n");
		printf("\n");
		PressEnter;

		printf("DestoryList_L\n");
		printf("before destroy\n");
		L ? printf("L exists\n") : printf("L does not exist\n");
		DestoryList_L(&L);
		printf("after destroy\n");
		L ? printf("L exists\n") : printf("L does not exist\n");
		printf("\n");
		PressEnter;

		return 0;
}

void PrintElem(ElemType e)
{
		printf("%d\n", e);
}

Status CmpGreater(ElemType e, ElemType data)
{
		return data > e ? TRUE : FALSE; 
}
