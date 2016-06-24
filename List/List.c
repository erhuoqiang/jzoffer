#include "List.h"
#include <stdio.h>
/* CreatHeader */
List CreatHeader(void)
{
	List L = ( List )malloc( sizeof(Node) );
	if( L == NULL )
		printf("Creat error !Out of space!!");  //����ʹ�õ���STDIO����ĺ��� �����ƽ̨��Ҫע��
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

	if( !IsLast(P, L) ) //�������һ�� ��ɾ��
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
		printf(" Insert error ! Out of space!!");  //����ʹ�õ���STDIO����ĺ��� �����ƽ̨��Ҫע��

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

/*****������*******/
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

/******���������м�Ԫ��*******/
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

/*******�ػ�������**********/
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

/*************������K���ڵ�*******************/
/*
	ע��㣺
		1 ����������С��k�Ϳ���k = 0 ���
		2 ����ΪNULL����ûԪ��
		3 ���һ���ڵ�ָ��NULL ����ڵ�

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
	if( k == 0 )//k == 0���
	{
		FKTT_Status = kInvalid_Z;
		return NULL;
	}
	for( i = 1;  i < k; i++)  //ע�� ���ǰ��û��k != 0�ж����ﲻҪ��<=k-1����Ϊk=0ʱ k-1=0XFFFFFFFF���ᵼ�±���
	{
		pHead = pHead->Next;
		if( pHead->Next  == NULL)  //����������С��k
		{
			FKTT_Status = kInvalid_GT;
			return NULL;
		}
	}
	while(pHead->Next != NULL)  //���ﲻ����pHead != NULL ��Ϊ�����൱�ڰ�NULL Ҳ����һ���ڵ����ȥ�ˣ���K = 1Ҳ���ǵ�����һ��ʱ ���ص���NULL
	{
		pHead = pHead->Next;
		pBehind = pBehind->Next;
	}
	return pBehind;
}
/*������ϲ� �ǵݹ�*/
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
/*������ϲ� �ݹ�*/
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
