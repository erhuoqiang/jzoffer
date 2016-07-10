/*
输入两个整数序列，第一个序列表示栈的压入顺序，写一个函数
判断第二个输入序列是否为栈弹出序列。
思路：压栈是先进后出的，如果压入栈的栈顶元素不等于当前弹出的元
素则把压栈序列中后面还没有压入的元素压入栈，直到碰到和当前弹出
元素相等为止，如果这个数没找到则说明，该弹出序列错误。如果栈顶
元素等于当前弹出元素则直接弹出。
*/

#include<iostream>
#include<stack>
using namespace std;


bool IsPopOrder(int * pPush, int *pPop, int len)
{
    if(pPush == NULL || pPop == NULL || len <0)
        return false;
    int countPush = 0, countPop = 0;
    stack<int> s;
    s.push(pPush[countPush++]);
    while(countPop< len)
    {
        if(s.top() != pPop[countPop])
        {
            for(; countPush  <  len; countPush++ )
            {
                if(pPush[countPush] != pPop[countPop])
                {
                    s.push(pPush[countPush]);
                }
                else
                    break;
            }
            if(countPush == len)
                return false;
            else
            {
                countPush++;
                countPop++;
            }
        }
        else
        {
            s.pop();
            if(s.empty())
            {
                s.push(pPush[countPush++]);
            }
            countPop++;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    int push[5] = {1,2,3,4,5};
    int pop[5] =  {4,3,5,1,2};
    cout<<(IsPopOrder(push, pop, 5)?"yes":"no")<<endl;;
}
