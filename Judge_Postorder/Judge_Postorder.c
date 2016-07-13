#include<stdio.h>
/*输入一个整形数组判断是不是二叉排序树后序遍历的结果*/

/*根据二叉排序数后序遍历特点 root在数据结尾，左子树比root小
右子树比root大，根据这个原理递归实现判断*/
int Judge_Postorder(int  * sequence, int length)
{
	int leftflag = 1, rightflag = 1;
	int i = 0, j = 0;
	int root  = 0;
	if(sequence == NULL)
		return -2;
	if(length <= 0)
		return -1;
	root = sequence[length - 1];
	/*不能是i<length 因为如果是只有左子树的情况下 就变成i = length后面递归 Judge_Postorder(sequence, i ); 就变成死循环了*/
	for( ; i < length - 1; i++)
	{
		if(sequence[i] > root )
			break;
	}

	for( j = i; j < length - 1; j++)
	{
		if(sequence[j] < root)
			return 0;
	}

/*当length = 1时 i =0, leng-1 = 0*/
	if(i  != 0)
	{
		leftflag = Judge_Postorder(sequence, i );
	}
	if(i != length - 1)
	{
		rightflag = Judge_Postorder(sequence + i, length -  i - 1);  //不要把root也算进去
	}
	return leftflag != 0 && rightflag != 0;
}

int main()
{
	int sequence1[] = {5,7,6,9,11,10,8};
	int sequence[] = {7,4,6,5};
	printf("%d\n",  Judge_Postorder(sequence1, sizeof(sequence1)/sizeof(sequence1[0])));
	printf("%d",  Judge_Postorder(sequence, sizeof(sequence)/sizeof(sequence[0])));
}


