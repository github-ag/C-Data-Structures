#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
class node 
{
public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* InsertInBST(node *root,int d)
{
	//base case
	if(root==NULL)
		return new node(d);
	//rec case
	if(d<root->data)
	{
		root->left = InsertInBST(root->left,d);

	}
	if(d>root->data)
	{
		root->right = InsertInBST(root->right,d);
	}
	return root;
}
node* build()
{
	//read a list of numbers till -1 and insert them into BST
	int d;
	cin>>d;
	node* root = NULL;
	while(d!=-1)
	{
		root = InsertInBST(root,d);
		cin>>d;
	}
	return root;
}
bool searchInBST(node* root, int d)
{
	if(root==NULL)
		return false;
	if(root->data==d)
		return true;
	if(root->data<d)
		return searchInBST(root->left,d);
	else
		return searchInBST(root->right,d);

}
node* deleteInBST(node* root,int d)
{
	if(root==NULL)
		return NULL;
	else if(d<root->data)
	{
		root->left = deleteInBST(root->left,d);
		return root;
	}
	
	else if(root->data==d)
	{
		//found the node to be deleted .
		//Now we have three cases ->
		//case 1 - node with 0 children.
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			return NULL;
		}
		//case 2-node with one child.
		else if(root->left !=NULL && root->right==NULL)
		{
			node *temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL&&root->right!=NULL)
		{
			node *temp = root->right;
			delete root;
			return temp;
		}
		//case 3 - node with 2 children
		else
		{
			node* replace = root->right;
			while(replace->left!=NULL)
			{
				replace = replace->left;
			}

		
		root->data = replace->data;
		root->right = deleteInBST(root->right,replace->data);
		return root;
	   }
	}
	else
	{
		root->right = deleteInBST(root->right,d);
		return root;
	}
}
bool is_BST(node *root,int lower=INT_MIN , int higher=INT_MAX)
{
	if(root==NULL)
		return true;
	if(root->data>=lower &&root->data<=higher)
	{
		bool left = is_BST(root->left,lower,root->data);
		bool right = is_BST(root->right,root->data,higher);
		if(left==true&&right==true)
			return true;
		else
			return false;

	}
	else
		return false;

}
int main()
{


}
