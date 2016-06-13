/*青蛙上楼梯问题可以转化为fibonacci公式，青蛙上n阶楼梯，每次可以跳1阶或者2阶
，从后往前想就是最后一步青蛙可以是从n-1阶走一步到N,或者从n-2阶走2步到n。然后在考虑n-1,n-2，也就是递归公司f(n) = f(n-1)+f(n-2),但是如果直接使用这个公式递归的话，会常生很多重复计算,所以我们计算的时候是从前面往后面算，理解的时候是从后面往前面理解*/
#include<stdio.h>
long long Fibonacci(unsigned int n)
{
	int i = 2, sum = 0;
	int fibn_1 = 1,fibn_2 = 0;
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	for(; i <= n; i++)
	{
		sum = fibn_1 + fibn_2;
		fibn_2 = fibn_1;
		fibn_1 = sum;
	}
	return sum;
}

int main()
{
	unsigned int temp = 0;
	while(1)
	{
		scanf("%d",&temp);
		printf("result = %lld\n",Fibonacci(temp));
	}
}
