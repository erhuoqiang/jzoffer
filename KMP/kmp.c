#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用于求出需要查找字符串的next数组
int * GetNext(const char * str)
{
	int i = 0, j = 0;
	int len = 0;
	int * next = NULL;
	if(str == NULL)
		return NULL;

	len = strlen(str);
	next = (int *)malloc(4*(len + 1));   //next表示位长度为i的字符从的前缀和后缀的最长公共部分，下标从1开始
	next[0] = next[1] = 0;

	for(i = 1; i < len; i++) //i表示字符串的下标从0开始
	{
        //j在每次循环开始都表示next[i]的值，同时也表示下一次需要比较的位置
		while( j > 0 && str[i] != str[j] )
			j = next[j];
		if( str[i] == str[j] )
			j++;
		next[i + 1] = j;
	}

	return next;
}

int KMP_Search(const char * origin, const char * sub,  int * next)
{
	int i = 0, j = 0;
	int origin_len = 0;
	int sub_len = 0;

	if(origin == NULL || sub == NULL || next == NULL)
		return -1;

	origin_len = strlen(origin);
	sub_len = strlen(sub);

	for( ; i < origin_len; i++ )
	{
		while( j > 0 && origin[i] != sub[j] )
			j = next[j];
		if( origin[i] == sub[j] )
			j++;
		if(j == sub_len)
		{
			printf("%s:%d\n",sub, i - j + 1);
			j = next[j];//用于接着查找下一个匹配位置
			//printf("%d\n",j);
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	char origin[] = "I xix xixix why xiao zhi qiang\n";
	char sub[] = "xix";
	int * temp = NULL;
	printf("KMP:\n");
	KMP_Search(origin, sub, temp = GetNext(sub));
	free(temp);
	return 0;
}
