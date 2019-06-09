#include <iostream>

using namespace std;

const int MaxStackSize=50;
template <class T>
class Stack
{
private:
    T stacklist[MaxStackSize];
    int top;
public:
    Stack(void)//constructor to initialize top
    {
        top=0;
    }
    //modification operation
    void Push(const T& item);
    T Pop(void);
    void ClearStack(void);
    T Peek(void) const;
    int StackEmpty(void) const;
    int StackFull(void) const;
};
    template <class T>
    void Stack<T>::Push(const T& item)    //Push into stack if the Stack is not full
    {
    if(top==MaxStackSize-1)
    {
        cerr<<"Stack overflow"<<endl;
        exit(1);
    }
    top++;
    stacklist[top]=item;
    }
    template <class T>
    T Stack<T>::Pop(void)               //Pop from Stack if the Stack is not empty
    {
    T temp;
    if(top==-1)
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    temp=stacklist[top];
    top--;
    return temp;
    }
    template <class T>
    void Stack<T>::ClearStack(void)
    {
        top=-1;
    }
    template <class T>
    T Stack<T>::Peek(void) const        //just copy top item without modifying stack contents
    {
    T temp;
    if(top==-1)
    {
        cerr<<"Stack empty"<<endl;
        exit(1);
    }
    temp=stacklist[top];
    return temp;
    }
    //check stack state returns top element value without removal
    template <class T>
    int Stack<T>::StackEmpty(void) const
    {
        return top==-1;
    }
    //returns true is the stack is empty
    template <class T>
    int Stack<T>::StackFull(void) const
    {
        return top==MaxStackSize-1;
    }

    //returns true if the stack is full
