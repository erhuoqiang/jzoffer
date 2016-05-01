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

enum Status{ kValid = 0, kInvalid };
int s2i_status = kInvalid;
int StrToInt(const char  * str)
{
 	

}


int main(int argc,  char **argc)
{

}
