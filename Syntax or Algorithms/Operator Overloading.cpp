#include<iostream>
#include<vector>
using namespace std;

void operator << (ostream &a,vector<int>&v)
{
    for(unsigned i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

void operator >>(istream &a,vector<int>&v)
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
    vector<int> v;
    cin>>v;
    cout<<v;
    return 0;
}
