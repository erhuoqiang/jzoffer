/*
	字符串转整形这个函数需要考虑的细节有很多如
	1字符串为NULL或者NUL
	2字符串前面出现空格
	3字符串代表正负数的时候
	4字符串所代表的数超出了int范围，考虑溢出
	  一开始我的想法是使用汇编混合编程判断溢出位但是不会写汇编下次补上
	5返回值区分不同异常，如果不能使用返回值代表合法和不合法
	  可以使用全局变量或者多传递一个形参来确定（返回值则都相同一般为0)
	
	先测试后提交
	测试例子   “”    NULL   “0”   “+”      “   -123dasf"    "42768"     
*/
#include<stdio.h>
#include<string.h>

enum Status{ kValid = 0,    //合法
			kInvalid_NULL,   //不合法 传递字符串为NULL
			kInvalid_NUL,     //不合法 传递字符串为NUL
			kInvalid_OF,       //不合法  字符串代表数值超出了int范围
			kInvalid_NO_Valid_NUM }; // 不合法  传递字符串有字符但是没有有效数值如"+"
int s2i_status = kValid;
int StrToInt(const char  * src)
{
	int flag = 1;
	long long num = 0;
	s2i_status = kValid;
 	if( src== NULL  )   //NULL
	{
		s2i_status = kInvalid_NULL;
		return 0;
	}
	if( *src == '\0' )  //NUL  这个判断放在判断空格和正负后避免 "   " ," +"这些情况
	{
		s2i_status = kInvalid_NUL;
		return 0;
	}
	while( *src == ' ' )  //空格情况
		 src++;

	if ( *src == '+' )  //考虑正负
	{
		src++;
		flag = 1;
	}
	else if( *src == '-' )
	{
		src++;
		flag = 0;
	}

	if( *src > '9' || *src < '0'  )  //NUL  这个判断放在判断空格和正负后避免 "   " ," +"这些情况
	{
		s2i_status = kInvalid_NO_Valid_NUM;
		return 0;
	}
	while( *src <= '9' && *src >= '0' )
	{
		num = num * 10 + *src - '0';
		if( flag &&  num > 0x7FFFFFFF || \
		 !flag && num > 0x80000000)
		{
			s2i_status = kInvalid_OF;
			return 0;
		}
		src++;
	}
	return flag == 1? (int)(num) : (int)(0 - num);
}


int main(int argc,  char **argv)
{
	char  str[100] = "";
	int result = 0;
	//测试例子   “”    NULL   “0”   “+”      “   -123dasf"    "42768"     
	while(1)
	{
		printf("input str:\n");
		gets(str);
		if(strcmp(str,"exit") == 0)
			break;
		result = StrToInt(str);
		if( s2i_status == kInvalid_NULL )
			printf("kInvalid_NULL\n");
		else if( s2i_status == kInvalid_NUL )
			printf("kInvalid_NUL\n");
		else if( s2i_status == kInvalid_OF )
			printf("kInvalid_OF\n");
		else if( s2i_status == kInvalid_NO_Valid_NUM )
			printf("kInvalid_NO_Valid_NUM\n");
		else 
			printf("result: %d\n",result);
	}
}

