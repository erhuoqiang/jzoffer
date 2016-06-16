#include<stdio.h>
#define  JUDGE_DOUBLE_ZERO 0.0000001
enum status
{
	Kvalid,
	Kinvalid_Input
};
int input_status = Kvalid;

double Power_With_Unsign_Exp(double base, unsigned int exp)
{
	double result = 0;
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	
	result =  Power_With_Unsign_Exp(base,exp>>1);
	result *= result;
	
	if( (exp & 0x1) == 1)
		result *=base;
	
	return result;
}

double Power(double base, int exp)
{
	double result = 0;
	input_status = Kvalid;
	if(base < JUDGE_DOUBLE_ZERO && base > -JUDGE_DOUBLE_ZERO)
	{
		if(exp < 0)
		{
			input_status = Kinvalid_Input;
			return  0.0;				
		}
		else 
		{
			return 0.0;
		}
	}
	if(exp < 0)
	{
		exp = ~exp + 1;
		result = 1 / Power_With_Unsign_Exp(base, (unsigned int)exp);
	}
	else
	{
		result = Power_With_Unsign_Exp(base, (unsigned int)exp);
	}

	return result;
}

int main(int argc, char ** argv)
{
	double base = 0.0;
	int exp = 0;
	while(1)
	{	
		printf("base, exp\n");
		scanf("%lf%d",&base, &exp);
		printf("input status = %d,result = %lf \n",input_status,Power(base,exp));
	}
}
		
