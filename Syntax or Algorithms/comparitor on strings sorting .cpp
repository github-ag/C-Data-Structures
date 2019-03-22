#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//comparitors
bool compare(string a,string b)
{
    return a>b;
}
bool compare2(string a,string b)
{
    return a<b;
}
bool compare_length(string a,string b)
{
    return a.length()>b.length();
}
int main()
{
    string arr[4]={"Apple","Mango","Banananana","Guava"};
    sort(arr,arr+4,compare);
    for(int i=0;i<4;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    sort(arr,arr+4,compare2);
    for(int i=0;i<4;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    sort(arr,arr+4,compare_length);
    for(int i=0;i<4;i++)
    cout<<arr[i]<<" ";

    return 0;
}
