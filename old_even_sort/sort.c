#include<stdio.h>



int QuickSort(int * num, int begin, int end)
{
	int temp = 0;
	int i = begin, j = end;
	if( num == NULL || begin < 0 || end < 0 )
		return -1;
	if(begin < end)	
	{
		temp = num[begin];
		while(i < j)
		{
			while( i < j && temp <= num[j])
				j--;
			if( i < j )
				num[i++] = num[j];
			while( i < j && temp >= num[i])
				i++;		
			if( i < j )
				num[j--] = num[i];
		}
		num[i] = temp;
		QuickSort(num, begin, i - 1);
		QuickSort(num, i + 1, end);
	}
	return 1; 	
}
	
int IsEven(int num)
{
	if(num & 0x1)
		return 0;
	else
		return 1;
}

void Reorder(int * num, unsigned int len, int (*func)(int))
{
	int index1 = 0 ,index2 = len - 1;
	int temp = 0;
	if(num == NULL || len < 0 || func == NULL)
		return;
		
	while(index1 < index2)
	{
		while( index1 < index2 && !func(num[index1]) )
			index1++;
		while( index1 < index2 && func(num[index2]) )
			index2--;
		if(index1 < index2)
		{
			num[index1] ^= num[index2];
			num[index2] ^= num[index1];
			num[index1] ^= num[index2];
		}
	}
	QuickSort(num, 0, index1 - 1); //最后index1指向第一个偶数,而index2因为条件index1<index2 所以最后index2 = index1
	QuickSort(num, index2, len - 1);
	
}

int main()
{	
	int i = 0; 
	int a[10] = {1,23,5,24,1,2,4,1,421,2};
	Reorder(a, 10, IsEven);
	for(i = 0; i < 10; i++)
		printf("%d ",a[i]);
	putchar('\n');
}
	
		
	
