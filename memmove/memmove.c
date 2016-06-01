#include<stdio.h>

void * my_memmove(char * dest, const char *src, int num)
{
	void * tempdest = dest;
	if( dest == NULL || src == NULL || num <0 )
		return NULL;	

	if(dest > src && dest < src + num) //如果dest 在src和src+count之间 则从尾巴开始复制，其他情况则从首部开始
	{
		while(num--)
		{
			dest[num] = src[num];
		}
	}
	else
	{
		while(num--)
		{
			*dest++ = *src++;
		}	
	}
	
	return (void *)tempdest;
}	

 
int main()
{
	int srcpos = 0, destpos = 0;
	int count = 0;
	char num[20] = "!!!!!!!!!!!!!!!!!!!";
	scanf("%s",num);
	scanf("%d",&count);
	my_memmove(num+count-1, num+10, 5);
	for(count = 0; count<20;count++)
	printf("%c",num[count]);
	putchar('\n');
}
