#include<iostream>
#include<stack>

using namespace std;

template <typename T>
class MStack
{
    public:
        void push(const T & value);
        void pop(void);
        const T & get_min(void) ;
    private:
        stack<T>  data_stack;
        stack<T>  min_stack;
};

template <typename T>
void MStack<T>::push(const T & value)
{
    data_stack.push(value);
    if(min_stack.empty() || value <= min_stack.top())
        min_stack.push(value);
}
template <typename T>
void MStack<T>::pop(void)
{
    if(!data_stack.empty())
    {
        if(data_stack.top() == min_stack.top())
            min_stack.pop();
        data_stack.pop();
    }
}
template <typename T>
const T & MStack<T>::get_min(void)
{
    if(!min_stack.empty())
    return min_stack.top();

}

int main()
{
    MStack<int> s;
    int num[5] = {4,3,2,44,1};
    cout<<"input:"<<endl;
    for(int i =0 ; i  < 5; i++)
    {
        cout<<num[i]<<" ";
        s.push(num[i]);
    }
    cout<<endl<<"current min:"<<endl;
    for(int i =0; i  < 5; i++)
    {
         cout<<s.get_min()<<" ";
         s.pop();
    }
  cout <<endl;
}
