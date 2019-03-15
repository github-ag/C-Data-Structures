#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main()
{
	//priority_queue <int>h;//by default it will create max heap
	// creating the min heap
	priority_queue<int,vector<int>,greater<int> > h;//this comparitor will create the min heap using inbuilt functor
	int a[6] = {5,4,6,8,2,10};
	for(int i=0;i<6;i++)
	{
		h.push(a[i]);
	}
	while(!h.empty())
	{
		cout<<h.top()<<" ";
		h.pop();
	}
	return 0;
}
