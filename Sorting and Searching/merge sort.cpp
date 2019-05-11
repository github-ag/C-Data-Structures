//merge sort
#include<iostream>
using namespace std;
void merge(int *a,int s,int e)
{
	int mid = (s+e)/2;
	int fs = s;
	int ss = mid+1;
	int b[10000],j=s;
	while(fs<=mid &&ss<=e)
	{
		if(a[fs]<=a[ss])
		{
			b[j++]=a[fs++];

		}
		else
		{
			b[j++]=a[ss++];
		}
	}
	while(fs<=mid)
	{
		b[j++]=a[fs++];
	}
	while(ss<=e)
	{
		b[j++]=a[ss++];
	}
	for(int i=s;i<=e;i++)
		a[i]=b[i];
}
void merge_sort(int *a,int e,int s=0)
{
	if(s==e)
	{
		return ;

	}
	int mid = (s+e)/2;
	merge_sort(a,s,mid);
	merge_sort(a,mid+1,e);
	merge(a,s,e);

}
int main()
{
	int a[1000],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	merge_sort(a,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
