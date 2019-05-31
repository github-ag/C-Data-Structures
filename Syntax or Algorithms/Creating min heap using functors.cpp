#include<iostream>
#include<functional>
#include<queue>
using namespace std;
//creating a functor for the heaps.
class CarCompare
{
public:
    bool operator()(int a ,int b)
    {
        return a>b;//creates min heap.
        
    }
};
int main()
{
    priority_queue<int,vector<int>,CarCompare> pq;
    int a[6]={6,5,8,2,10};
    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;

}
