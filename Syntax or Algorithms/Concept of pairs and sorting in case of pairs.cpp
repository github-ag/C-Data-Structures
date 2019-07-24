#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool compare(pair<string,int>a,pair<string,int> b)
{
	return a.second<b.second;
}
int main()
{
	pair<string,int> a[3];
	
	a[0] = make_pair("abhishek",50);
	a[1] = make_pair("sethi",30);
	a[2] = make_pair("shubham",27);
	// sorting in the pair is done according to the first elements
	// to do the sorting according to the second element we have to use  comparitor
	sort(a,a+3,compare);
	for(int i=0;i<3;i++)
	{
		cout<<a[i].first<<"-->"<<a[i].second;
		cout<<endl;
	}
	return 0;
}
