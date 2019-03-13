#include<iostream>
#include<cstring>
using namespace std;
class node 
{
public:
	string key;
	int value;
	node *next;
	node(string key,int value)
	{
		this->key=key;
		this->value=value;
		next=NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}

};
class hashtable
{
    node **table;
    int cs;
    int ts;

    int hashfn(string key)
    {
    	int idx=0;
    	int p=1;
    	for(int i=0;i<key.length();i++)
    	{
    		idx +=(p*key[i])%ts;
    		idx=idx%ts;
    		p=(p*37)%ts;
    	}
    	return idx;

    }
    void resize()
    {
    	node **oldtable=table;
    	table = new node*[2*(ts)];
    	cs=0;
    	for(int i=0;i<2*ts;i++)
    	{
    		table[i]=NULL;
    	}
    	int oldts=ts;
    	ts = 2*ts;
    	for(int i=0;i<oldts;i++)
    	{
    	   node *temp = oldtable[i];
    	   while(temp!=NULL)
    	   {
    	   	insert(temp->key,temp->value);
    	   	temp=temp->next;
    	   }
    	   delete oldtable[i];

    	}
    	delete [] oldtable;
    }
public:
	hashtable(int ds=7)
	{
		ts=ds;
		table = new node*[ds];
		for(int i=0;i<ds;i++)
		{
			table[i]=NULL;
		}
	}
	void insert(string key,int value)
	{
		int idx=hashfn(key);
		node *n=new node(key,value);
		n->next=table[idx];
		table[idx]=n;
		cs++;
		float load_factor = cs/float(ts);
		if(load_factor>0.7)
			resize();

	}
	int search(string k)
	{
		int idx = hashfn(k);
		node *temp=table[idx];
		while(temp!=NULL)
		{
			if(temp->key==k)
				return temp->value;
			temp=temp->next;
		}
		return -1;
	}
	int &operator[](string k)
	{
		int f=search(k);
		if(f==-1)
		{
			insert(k,0);

		}
		else
			cout<<f;


	}
	void print()
	{
		for(int i=0;i<ts;i++)
		{
            cout<<i<<"-->";
            node *temp=table[i];
			while(temp!=NULL)
			{
				cout<<temp->key<<",";
				temp=temp->next;
            }
			cout<<endl;

		}
	}

};

