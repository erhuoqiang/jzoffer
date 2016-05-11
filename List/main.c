#include <stdio.h>
#include <stdlib.h>
#include "List.h"
/*** 输入和输出的顺序一样*************/

int main()
{
	List L = CreatHeader();
	Position P = L;
	Position middle = NULL;
	Position KthToTail = NULL;
	int temp = 0;
	printf("Please input  int Element, end with 0.\n");
	while( scanf("%d", &temp) == 1 && temp != 0)
	{
		Insert( temp, L, P ); //从末尾插入
		P = P->Next;
	}
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}

    middle = Search_Moddle(L);
    if(middle != NULL)
    printf("middle element is %d\n", middle->Element);
    
    printf("Please input kth To List Tail:");
    scanf("%d",&temp);
    KthToTail = FindKthToTail(L,(unsigned int )temp);
    if(KthToTail != NULL)
   	printf("Kth To Tail is: %d\n",  KthToTail->Element);
    else 
	printf("K is ERROR status = %d\n", FKTT_Status);

	/******将L倒叙****/
	L = List_Reverse(L);
	P = L->Next;
	while( P != NULL )
	{
		printf("%d ",P->Element);
			P = P->Next;
	}
	L->Next->Next = L->Next;
    printf("IsLoop ? %s\n", IsLoop(L, &P)? "yes": "no");
    printf("%d", P->Element);
    getchar();
    return 0;
}



/*** 输入和输出的顺序相反*************/
/*
int main()
{
	List L = CreatHeader();
	Position P = L;
	int temp = 0;

	while( scanf("%d", &temp) == 1 )
	{
		Insert( temp, L, L );	//从开头插入
	//	P = P->Next;
	}
	P = L->Next;
	while( P != NULL )
	{
		printf("%d",P->Element);
			P = P->Next;
	}

	while(1);
}
*/
