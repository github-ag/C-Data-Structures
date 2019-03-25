#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>l;
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    int size=l.size();
    for(int i=0;i<size;i++)
    {
        cout<<l.front();
        l.pop_front();
    }
    //similarly we have pop_back() and pop_front() function present in the list.
    return 0;
}
