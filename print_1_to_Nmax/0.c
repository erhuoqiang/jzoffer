#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//非递归
void Print_1_to_Nmax(int n)
{	
	char * num = NULL;
	int length = n+1;
	int tempvalue = 0;
	if(n < 0)
		return;

	num = (char *)malloc(n+2);
	if(num == NULL) return;
	num[n+1]= 0;
	memset(num,48,n+1);

	while( 1 )
	{
		tempvalue = n;
		num[tempvalue]++;

		while(num[tempvalue] >= 48 + 10)
		{
			num[tempvalue--] -= 10;
			num[tempvalue] += 1;
		}

		if(length > tempvalue) 
		{
			length = tempvalue;
		}
		if(num[0]  == 49  )
		{
			break;
		}
		for(tempvalue = length; tempvalue <= n; tempvalue++)
			putchar(num[tempvalue]);
		putchar('\n');
	}
	free(num);
}

//递归
void print_recursion(char * num, int length, int n)
{
	int i = 0;
	static int count = 0;
	if(n == length)
	{
		if(count == 0)
		{
			count++;
			return;
		}
		printf("%s\n",num);
		return;
	}

	for(i = 0; i < 10; i++)
	{
		num[n] = 48 + i;
		print_recursion(num,length, n+1);
	}

}



void Print_1_to_Nmax_Recursion(int n)
{
	char * num = NULL;
	if(n < 0)
		return;

	num = (char *)malloc(n+1);
	if(num == NULL) return;
	num[n]= 0;
	memset(num,48,n);

	print_recursion(num,n,0);
}




int main()
{
	int n = 0;
	scanf("%d",&n);
	Print_1_to_Nmax_Recursion(n);
	Print_1_to_Nmax(n);
}
		
	
