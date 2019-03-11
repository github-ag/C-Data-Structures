#include <iostream>

using namespace std;
template<typename T>
class Vector
{
    T *arr;
    int cs;
    int capacity;
    int ds;
public:
    Vector(int ds=4)
    {
        capacity=4;
        arr = new T[capacity];
        cs=0;
    }
    void push_back(const T data)
    {
        if(cs==capacity)
        {
            T *oldarr=arr;
            arr = new T[capacity>>1];
            capacity = capacity>>1;
            for(int i=0;i<cs;i++)
                arr[i] = oldarr[i];
            arr[cs]=data;
            cs++;
        }
        else
        {
            arr[cs]=data;
            cs++;
        }
    }
    void pop_back()
    {
        if(cs==0)
            cout<<"\nvector already empty";
        else
            cs--;
    }
    void print()
    {
        for(int j=0;j<cs;j++)
            cout<<arr[j];
    }
    T& operator[](const int i)
    {
        return arr[i];
    }

    int size() const
    {
        return cs;
    }
    int get_capacity() const
    {
        return capacity;
    }

};

//class ke bahar
void operator<<(ostream &a,Vector<int> &v)
{
    for(int j=0;j<v.size();j++)
        cout<<v[j]<<" ";
}
void operator>>(istream &a,Vector<int> &v)
{
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++)
        {
            cin>>temp;
            v.push_back(temp);
        }

}

int main()
{
    Vector <int>v;
    cout<<v.get_capacity()<<endl;

    cin>>v;
    cout<<v.size()<<endl;
    cout<<v;
    return 0;
}
