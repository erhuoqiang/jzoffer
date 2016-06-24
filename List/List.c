#include "List.h"
#include <stdio.h>
/* CreatHeader */
List CreatHeader(void)
{
	List L = ( List )malloc( sizeof(Node) );
	if( L == NULL )
		printf("Creat error !Out of space!!");  //这里使用的是STDIO里面的函数 如果换平台需要注意
	L->Next = NULL;
//	L->Element = 0;
	return L;
}
/* Return ture if L is empty */
int IsEmpty( List L )
{
	return L->Next == NULL;
}

/* Return ture if P is the last position in List L*/
/* Parameter L is unused in this implementation */
int IsLast( Position P, List L )
{
	return P->Next == NULL;
}

/* Return Position of X in L; if not found return NULL */
Position Find( ElementType X, List L )
{
	Position P;

	P = L->Next;
	while( P != NULL && P->Element != X )
		P = P->Next;
	return P;
}

/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assume a header */
Position FindPrevious( ElementType X, List L )
{
	Position P;

	P = L;
	while( P != NULL && P->Next->Element != X )
		P = P->Next;
	return P;
}
/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete( ElementType X, List L )
{
	Position P, TempCell;

	P = FindPrevious( X, L );

	if( !IsLast(P, L) ) //不是最后一个 则删除
	{
		TempCell = P->Next;
		P->Next = TempCell->Next;
		free( TempCell );
	}
}

/* Insert (after legal position p) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert( ElementType X, List L, Position P )
{
	Position TempCell;

	TempCell = malloc( sizeof(Node) );
	if(TempCell == NULL )
		printf(" Insert error ! Out of space!!");  //这里使用的是STDIO里面的函数 如果换平台需要注意

	TempCell->Element = X;
	TempCell->Next = P->Next;
	P->Next = TempCell;
}

/*  DeleteList */
void DeleteList( List L )
{
	Position P, TempCell;

	P = L->Next;
	L->Next = NULL;
	while( P != NULL )
	{
		TempCell = P->Next;
		free(P);
		P = TempCell;
	}
}

List First( List L )
{
	if( L->Next != NULL )
		return L->Next;
	else
		return NULL;
}

ElementType Retrieve( Position P )
{
		return P->Element;
}

/*****链表倒叙*******/
List List_Reverse(List L)
{
	if (L != NULL && L->Next != NULL)
	{
	  List Fir, Sec, Thi;
	  Fir = L->Next;
	  Sec = Fir->Next;

	  while(Sec != NULL)
	  {
		  Thi = Sec->Next;
		  Sec->Next = Fir;
		  Fir = Sec;
		  Sec = Thi;
	  }
	  L->Next->Next = NULL;
	  L->Next = Fir;

      return L;
	}

	perror("List is NULL\n");
	return L;
}

/******查找链表中间元素*******/
Position Search_Moddle(List L)
{
    Position cur = NULL, middle = L->Next;
    int i = 0, j = 0;
    if(L == NULL || L->Next == NULL)
    {
        printf("List is NULL");
        return NULL;
    }
    cur = middle = L->Next;
    while(cur != NULL)
    {
        if( i / 2 > j )
        {
            j++;
            middle = middle->Next;
        }
        cur = cur->Next;
        i++;
    }
    return middle;
}

/*******回环链表检测**********/
int IsLoop(List L, List *start)
{
    Position stepone = L, steptwo = L;
    if( L == NULL || start == NULL || L->Next == NULL )
    {
        return 0;
    }
    do
    {
        stepone = stepone->Next;
        steptwo = steptwo->Next->Next;
    }
    while( steptwo != NULL && steptwo->Next && stepone != steptwo );

    if( stepone != steptwo )
    {
	*start = NULL;
        return 0;
    }
    *start = stepone;
    return 1;
}

/*************求倒数第K个节点*******************/
/*
	注意点：
		1 考虑链表长度小于k和考虑k = 0 情况
		2 链表为NULL或者没元素
		3 最后一个节点指向NULL 不算节点

	2016.05.10
					 				*/
enum FindKthToTaik_Status
{
	kValid = 0,kInvalid_GT,kInvalid_Z,ListInvalid
};
int FKTT_Status = kValid;
Position FindKthToTail(List  L, unsigned int k)
{
	int i = 0;
	Position pHead = L;
	Position pBehind = 	L;
	FKTT_Status = kValid;
	if(L == NULL || L->Next == NULL)
	{
		FKTT_Status = ListInvalid;
		return NULL;
	}
	if( k == 0 )//k == 0情况
	{
		FKTT_Status = kInvalid_Z;
		return NULL;
	}
	for( i = 1;  i < k; i++)  //注意 如果前面没有k != 0判断这里不要用<=k-1，因为k=0时 k-1=0XFFFFFFFF，会导致崩溃
	{
		pHead = pHead->Next;
		if( pHead->Next  == NULL)  //考虑链表长度小于k
		{
			FKTT_Status = kInvalid_GT;
			return NULL;
		}
	}
	while(pHead->Next != NULL)  //这里不能是pHead != NULL 因为这样相当于把NULL 也当成一个节点算进去了，当K = 1也就是倒数第一个时 返回的是NULL
	{
		pHead = pHead->Next;
		pBehind = pBehind->Next;
	}
	return pBehind;
}
/*两链表合并 非递归*/
/*
Position  List_Merge( Position  pHead1,  Position  pHead2 )
{
	Position  merge = NULL;
	Position  head = NULL;

	if(pHead1 == NULL)
		return pHead2;
	else if( pHead2 == NULL)
		return pHead1;
	
	if(pHead1->Element <= pHead2->Element)
	{
		head = merge = pHead1;	
		pHead1 = pHead1->Next;
	}
	else
	{
		head = merge = pHead2;	
		pHead2 = pHead2->Next;
	}

	while(pHead1 && pHead2)
	{	
		if(pHead1->Element <= pHead2->Element)
		{
			merge->Next = pHead1;
			pHead1 = pHead1->Next;
			merge = merge->Next;
		}
		else
		{
			merge->Next = pHead2;
			pHead2 = pHead2->Next;
			merge = merge->Next;
		}
	}
	while(pHead1 != NULL)
	{
		merge->Next = pHead1;
		pHead1 = pHead1->Next;
		merge = merge->Next;
	}
	while(pHead2 != NULL)
	{
		merge->Next = pHead2;
		pHead2 = pHead2->Next;
		merge = merge->Next;
	}
	return head;	
}
*/
/*两链表合并 递归*/
Position  List_Merge( Position  pHead1,  Position  pHead2 )
{
	Position  head = NULL;

	if(pHead1 == NULL)
		return pHead2;
	else if( pHead2 == NULL)
		return pHead1;
	
	if(pHead1->Element <= pHead2->Element)
	{
		head = pHead1;	
		head->Next =  List_Merge(pHead1->Next,pHead2);
	}
	else
	{
		head = pHead2;	
		head->Next =  List_Merge(pHead1,pHead2->Next);
	}


	return head;	
}
