#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* build()
{
    int d;
    cin>>d;
    //base case
    if(d==-1)
    {

        return NULL;
    }
    // rec case
   node* root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}
void print_pre_order(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data;
    print_pre_order(root->left);
    print_pre_order(root->right);

}
/*void print_in_order(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data;
    print(root->right);

}
*/
/*void print_post_order(node *root)
{
    if(root==NULL)
        return;
    print(root->left);
    print(root->right);
    cout<<root->data;
}
*/
int count (node *root)
{
    if(root==NULL)
        return 0;

    return 1+count(root->left)+count(root->right);
}
int sum(node *root,int s)
{
    if(root==NULL)
        return 0;
    return root->data;
    s+=sum(root->left,s);
    s+=sum(root->right,s);
    return s;
}
int height(node *root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
void printAtLevelK(node* root,int k)
{
    //base case
    if(root==NULL ||  k<0)
        return;
    if(k==0)
        {cout<<root->data<< " ";
          return;
        }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);

}
void printALLLevels(node *root)
{
    int H=height(root);
    for(int i=0;i<H;i++)
    {
        printAtLevelK(root,i);
        cout<<endl;
    }
}
//Iteratively-->>Breadth First Search
void printBFS(node *root)
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node *f=q. front();
        cout<<f->data;
        q.pop();
        if(f->left)
           {
                q.push(f->left);
           }
        if(f->right)
        {
            q.push(f->right);
        }
    }
}
/*void buildBFS(node *root,int d)
{


    root->data=d;
    int d_left,d_right;
    cin>>d_left>>d_right;
    if(d_left!=-1)
    {
        buildBFS(root->left,d_left);
    }
    else
        return ;
    if(d_right!=-1)
        buildBFS(root->right,d_left);
    else*
        return ;
}
*/




void mirror(node *&root)
{

    if(root==NULL)
        return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);

}
int sumofallnodes(node *root)
{
    if(root==NULL)
        return 0;
    root->data +=sumofallnodes(root->left)+sumofallnodes(root->data);
    return root->data;
}
int sumofall(node *root)
{
    if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
            return root->data;
    int temp=root->data;
    root->data= sumofall(root->left)+sumofall(root->right);
    return temp+root->data;
}

int diameter(node *root)//works with the complexity of O(n^2)
{

    if(root==NULL)
        return 0;


    int d = height(root->left)+height(root->right);
    int d_left = diameter(root->left);
    int d_right = diameter(root->right);
    return max(d,max(d_left,d_right));

}
//optimized
class Pair
{
    public:
    int height;
    int diameter;
};
Pair fastDiameter(node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    
    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}


class pairHB
{
    public:
        int height;
        bool balance;
};
pairHB isHeight_balanced(node *root)
{
    pairHB p;
    if(root==NULL)
    {
        p.balance=true;
        p.height =0;
        return p;
    }
    pairHB left,right;
    left = isHeight_balanced(root->left);
    right = isHeight_balanced(root->right);
    p.height = max(left.height,right.height)+1;
    if(left.balance==true&&right.balance==true&&(abs(left.height-right.height)<=1))
    {
        
        p.balance  = true;
    }
    else
        p.balance = false;
    return p;


}

node* buildTreeFromArray(int *a , int s,int e)
{
    //base case
    if(s>e)
        return NULL;
    //recursive case
    int mid = (s+e)/2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
}

node *createTreeFromTraversal(int *in,int *pre,int s,int e)//creating a tree from inorder and preorder traversal
{
    static int i=0;
    //property of static varible - it is only initialized once that means every time the function is called it is not initialized.
    //base case
    if(s>e)
        return NULL;
    //rec case
    node *root = new node(pre[i]);
    int index =-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTraversal(in,pre,s,index-1);
    root->right = createTreeFromTraversal(in,pre,index+1,e);
    return root;



}

int main()
{

    node *root;
    int data;
    cin>>data;
    root=build();
    print_pre_order(root);
    mirror(root);
    print_pre_order(root);
    return 0;
}
