#include<iostream>
using namespace std;
void countbits(int k)
{
	int n=k;
	//first method
	int c=0;
	while(n>0)
	{
		c+= (n&1);
		n=(n>>1);
	}
	cout<<"no. of bits are"<<c;
	cout<<"\n";
	//second method
	 n=k;
	int i=0;
	while(n>0)
	{
		i++;
		n=(n&(n-1));

	}
	cout<<i;
	
}
void swap(int &a,int &b)
{
	int temp=a;
	a=a^b^a;
	b=temp;

}
int getibit(int n,int i)
{
   int b=((n&(1<<(i-1)))==0?0:1);
   return b;
}
void setibit(int &n,int i)
{
   int mask = 1<<i;
   n = (n|mask);
}
void clearibit(int &n,int i)
{
	int mask = 1<<i;
	mask = ~mask;
	n = (n&mask);
}
int main()
{
	int a=9;
	clearibit(a,0);
	cout<<a;
	return 0;
}
