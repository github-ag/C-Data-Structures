#include <iostream>
#include<vector>
using namespace std;
class Stack
{
    vector<int> v;
public:
    void push(int x)
    {
        v.push_back(x);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size()-1];
    }
    void print()
    {
        int i=v.size()-1;
        while(i>=0)
            {
                cout<<v[i]<<" ";
                i--;
            }
    }
};

int main()
{
    Stack s;
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    cout<<"\n";
    s.print();
    return 0;
}
