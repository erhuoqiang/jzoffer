#include<stdio.h>
#define Element int

enum status
{
	kValid_Input = 0,
	kInvalid_Input
};

int Min_Status = kValid_Input;

int Find_MinInorder(Element *num, int low, int high)
{
    int Min = num[low++];
    for( ; low <= high; low++)
        if(num[low] < Min)
            Min = num[low];
    return Min;
}


int Min(Element *num, int length)
{
	int low = 0,high = length - 1;
	int mid = (low + high) / 2 ;

	if(num == NULL || length<= 0)
	{
		Min_Status = kInvalid_Input;
		return -1;
	}

    if(num[low]  < num[high])   //当输入的数组是一个排序数组如1 2 3 4 5 6 则输出第一位
        return num[low];
    else if(num[low] == num[mid] && num[high] == num[high])  //考虑出现 111 01 111 这种情况
        return Find_MinInorder(num,low, high);

	while(low != high - 1)
	{
		mid = (low + high)/2;
		if(num[mid] <= num[low])
			high = mid;
		else if(num[mid] >= num[high])
			low = mid;
	}
	return num[high];
}


int main()
{
    Element num0[10] = {1,2,3,4,5,6,7,8,9,10};
	Element num1[10] = {1,1,1,-1,1,1,1,1,1,1};
	Element num2[10] = {4,5,6,7,8,9,-3,2,3,3};
	printf(" Min_Status = %d Min = %d\n",Min_Status, Min(num0,10));
	printf(" Min_Status = %d Min = %d\n",Min_Status, Min(num1,10));
	printf(" Min_Status = %d Min = %d\n",Min_Status, Min(num2,10));
	printf(" Min_Status = %d Min = %d\n",Min_Status,Min(NULL,0));   //这里因为printf是从右向左入栈，所以Min_status应该放在函数执行后，也就是左边

}
