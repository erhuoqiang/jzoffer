#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class CQueue
{
public:
//	CQueue(void);
	~CQueue(void);

	void push(const T &data);
	T pop(void);

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
CQueue<T>::~CQueue(void)
{
    while(!stack1.empty())
        stack1.pop();

    while(!stack2.empty())
        stack2.pop();
}

template <typename T>
void CQueue<T>::push(const T & data)
{
    stack1.push(data);
}

template<typename T>
T CQueue<T>::pop(void)
{
    T temp;
    if(stack2.empty())
    {
        while(stack1.size() > 1)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if(stack1.size() == 1)
        {
            temp = stack1.top();
            stack1.pop();
            return temp;
        }
        else
        {
            cout<<"QUEUE  IS NULL"<<endl;
            throw "queue is empty";
        }
    }
    else
    {
        temp = stack2.top();
        stack2.pop();
        return temp;
    }
}
int main(int argc, char **argv)
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    CQueue<int> Q;
    for( i = 0; i < 10; i++)
        Q.push(num[i]);
    for( i = 0; i < 10; i++)
        cout<<Q.pop()<<" ";

}
