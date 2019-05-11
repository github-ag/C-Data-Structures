//quick sort
#include<iostream>
#include<algorithm>
using namespace std;
void QuickSort(int *a,int n)
{
	//base case
	if(n<=1)
		return;
	int b[1000],c[1000];
	int x=0,y=0;
	int pivot = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<=pivot)
			b[x++]=a[i];
		else
			c[y++]=a[i];
	} 
	QuickSort(b,x);
	QuickSort(c,y);
	for(int i=0;i<x;i++)
	{
		a[i]=b[i];
	}
	a[x]=pivot;

	for(int j=0;j<y;j++)
	{
		a[x+j+1]=c[j];
	}

}
int main()
{
	int a[1000],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	QuickSort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
