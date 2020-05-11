// Building segment tree by actually building the binary tree.
#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        left = NULL;
        right = NULL;
        data = d;
    }
};
node* buildTree(int *a,int n,int s,int e){
    //Base Case
    if(s==e){
        node *root = new node(a[s]);
        return root;
    }
    //Recursive Case
    int mid = (s+e)/2;
    node *root = new node(-1);
    root->left = buildTree(a,n,s,mid);
    root->right = buildTree(a,n,mid+1,e);
    root->data= min(root->left->data,root->right->data);
    return root;
}
// Preorder Traversal
void printTree(node *root){
    //Base Case
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}
int main(){
    int n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    node *root = buildTree(a,n,0,n-1);
    printTree(root);
    return 0;    
}
