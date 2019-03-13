#include<iostream>
#include<cstring>
#include"Hashtable.h"
using namespace std;
int main()
{
	hashtable t;
	t.insert("mango",5);
	t.insert("apple",4);

	t.print();
	cout<<endl;
	cout<<t.search("mango");
	t["banana"]=100;
	cout<<endl;
	t.print();
	return 0;

}
