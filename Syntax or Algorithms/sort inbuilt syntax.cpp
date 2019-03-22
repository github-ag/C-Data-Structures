#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    //applying sort function on integer array
    int a[5]={2,6,1,3,0};
    sort(a,a+5);//remember this syntax
    for(int i=0;i<5;i++)
    cout<<a[i];
    
    //applying sort function on strings array(sorted lexographically)
    string arr={"Apple","Mango","Banana"};
    sort(arr,arr+3);
    for(int j=0;j<3;j++)
    cout<<arr[j]<<" ";
    return 0;
}
