#include <iostream>

using namespace std;
template<typename T>
class Queue
{
    T* arr;
    int front;
    int rear;
    int ds;

public:
    Queue(int ds=4)
    {
        arr = new T[ds];
        front=-1;
        rear=-1;
        this->ds=ds;
    }
    void push(const T x)
    {
        if(isEmpty())
        {
            arr[++rear]=x;
            front++;
        }
        else if(rear==ds-1)
        {
            int *oldarr=arr;
            arr = new T[ds<<1];
            for(int i=0;i<=rear;i++)
            arr[i]=oldarr[i];
            arr[++rear]=x;
            ds=ds<<1;

        }
        else
        {
            arr[++rear]=x;
        }
    }
    void pop()
    {
        if(isEmpty())
            cout<<"\nQueue is already empty";
        else if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
    bool isEmpty()
    {
        if(rear==-1)
            return true;
        else
            return false;
    }
    void print()
    {
        if(isEmpty())
            cout<<"\nQueue is empty";
        else
        {
            int i=front;
            while(i<=rear)
            {
                cout<<arr[i]<<" ";
                i++;
            }
        }
    }
};

int main()
{
    Queue<int>qu;
    qu.push(4);
    qu.pop();
    qu.push(3);
    qu.push(2);
    qu.push(5);
    qu.print();
    qu.pop();
    cout<<"\n";
    qu.print();
    return 0;
}
