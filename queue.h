#include <iostream>

using namespace std;const int MaxQSize=50;
template <class T>
class Queue
{
private:
    //queue array and its parameters
int front, rear, count;
T qlist[MaxQSize];
public:
//constructor
Queue(void)
{
    front=0;                //initialize data members
    rear=0;
    count=0;
}
//queue modifications operations
void QInsert(const T& item)
{
    if(count==MaxQSize)
    {
        cerr<<"Queue overflow!"<<endl;
        exit(1);
    }
    count++;
    qlist[rear]=item;
    rear=(rear+1)%MaxQSize;
}
T QDelete(void)
{
    T temp;
    if(count==0)
    {
        cerr<<"Deleting from an empty queue!"<<endl;
    }
    temp=qlist[front];
    count--;
    front=(front+1)%MaxQSize;
    return temp;
}
//queue access
T QFront(void) const
{
    return qlist[front];
}
//queue test methods
int QLength(void) const
{
    return count;
}
//returns the number of stored elements
int QEmpty(void) const
{
    return count==0;
}
//returns true if the queue is empty
int QFull(void) const
{
    return count==MaxQSize;
}
//returns true if the queue is full
};
