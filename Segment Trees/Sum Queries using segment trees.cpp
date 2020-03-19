//Segment Trees to find the sum queries.
#include<iostream>
using namespace std;
class node
{
    public:
    int sum;
    node* left;
    node *right;
    node()
    {
        left=NULL;
        right=NULL;

    }
};
node* build(int *arr,int s=0,int e=1)
{
    //Base Case
    if(s==e)
    {
        node *root = new node();
        root->sum = arr[s];
        return root;
    }

    //Recursive Case
    node *root = new node();
    int mid = (s+e)/2;
    root->left = build(arr,s,mid);
    root->right = build(arr,mid+1,e);
    root->sum = root->left->sum+root->right->sum;
    return root;

}
//Printing the tree(inorder Printing)
void print(node *root)
{
    if(root==NULL)
    return;
    cout<<root->sum<<" ";
    print(root->left);
    print(root->right);
}

//Solving the sum queries
int solveQuery(node *root,int l,int r,int s,int e)
{
    int mid = (s+e)/2;
    //Base Case --> When the required range is present at the current segment.
    if(l==s && r==e)
    {
        return root->sum;
    }
    // 3 Cases
    // Case 1 --> When the required range is present in the left segment.
    if(r<=mid)
    {
        return solveQuery(root->left,l,r,s,mid);
    }
    // Case 2 --> When th required range is present in the right segment.
    if(l>mid)
    {
        return solveQuery(root->right,l,r,mid+1,e);
    }
    // Case 3 --> When the required segment is partially present in the right segment and partially in the left segment.
    if(l<=mid && r>mid)
    {
        int sum1 = solveQuery(root->left,l,mid,s,mid);
        int sum2 = solveQuery(root->right,mid+1,r,mid+1,e);
        return sum1+sum2;
    }
}
// updation in the segment tree -> We will be traversing only in those segments in which the current index is prsent.
void update(node *root,int idx,int ele,int prev,int s,int e)
{
    //Base case --> If we reach the leaf node of the index.
    if(s==e && s==idx)
    {
        // Update the value of the sum by element and return
        root->sum = ele;
        return;
    }
    root->sum -= prev;
    root->sum += ele;
    int mid = (s+e)/2;
    if(idx<=mid)
    {
        update(idx,ele,prev,s,mid);
    }
    else
    {
        update(idx,ele,prev,mid+1,e);
    }

}


int main()
{
    int arr[5] = {1,3,-2,8,-7};
    node *root = build(arr,0,4);
    print(root);
    int q,c,l,r,idx,ele; // c decides the type of query -> c=='s' for finding the sum and c=='u' for making the updation.
    cin>>q;

    cout<<endl;
    for(int i=0;i<q;i++)
    {
        cin>>c;
        
        if(c=='s')
        {
            cin>>l>>r;
            cout<<solveQuery(root,l,r,0,4)<<endl;
        }
        else if(c=='u')
        {
            cin>>idx>>ele;
            int prev = arr[idx];
            //Updating in the array.
            arr[idx] = ele;
            //Updating in the segment tree
            update(root,idx,ele,prev,0,4);
        }
        
    }
    return 0;
}
