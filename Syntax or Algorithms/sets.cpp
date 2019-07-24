// Concept of sets
//Properties of set-->
// 1 - It stores only the unique elements.
//2 - It stores the elements in the sorted order.
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s;
	s.insert(2);
	s.insert(5);
	s.insert(1);
	s.insert(1);
	// elements can be accessed inside the set only with the help of the iterator.
	// Learn the method to declare the iterator.
	for(set<int>::iterator it = s.begin();it!=s.end();it++)  
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	s.erase(2);//set can also be similar to min_heap but we cannot erase elements in min_heap like this.
	for(set<int>::iterator it = s.begin();it!=s.end();it++)  
	{
		cout<<*it<<" ";
	}


	return 0;

}
