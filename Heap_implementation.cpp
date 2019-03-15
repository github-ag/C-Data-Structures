#include<iostream>
#include<vector>
using namespace std;
class Heap
{
    vector <int>v;
    void heapify(int i)
    {
        int left = 2*i;
        int right = (2*i)+1;
        int min_i=i;
        if(left<v.size()&&v[left]<v[min_i])
        {
            min_i=left;
        }
        if(right<v.size()&&v[right]<v[min_i])
        {
            min_i=right;

        }
        if(min_i!=i)
        {
            swap(v[min_i],v[i]);
            i=min_i;
            heapify(i);

        }

    }
public:
    Heap(int ds=1000)
    {
        v.reserve(ds);
        v.push_back(-1);//block 0th position
    }

    void push(int data)
    {
        v.push_back(data);
        int idx = v.size()-1;
        int parent = idx/2;
        while(idx>1&&v[parent]>v[idx])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent = parent/2;
        }

    }
    int top()
    {
        //get min element
        return v[1];
    }

    void pop()
    {
        int idx = v.size()-1;
        swap(v[idx],v[1]);
        v.pop_back();
        heapify(1);
    }
    void print()
    {
        for(int i=1;i<v.size();i++)
            cout<<v[i]<<" ";

    }

};
int main()
{
    Heap h;
    h.push(5);
    h.push(4);
    h.push(6);
    h.print();
    return 0;
}
