// This code includes - >
// building bu dfs
// building by bfs
// preorder,postorder, inorder traversal
// height of the tree
// diameter/Optimized Diameter
// Print at k level
// Print all levels
// finding the sum and count
// top view,bottom view,left view, right view
// Creating tree from any two traverasals.
// Print mirror of the given tree.
// Find if the tree is height balanced or not.
// Lowest Common Ancestor/LCA(space optimized)
// finding path from root to any node
// finding all the nodes at Kth distance from the particular node.


#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<bits/stdc++.h>

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
//building by dfs
node* build()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;

    node *root = new node(d);
    root->left = build();
    root->right = build();
    
    return root;
}
// building by bfs
void buildBfs(node *root,int d)
{
    root->data = d;
    root->left = new node(-1);
    root->right = new node(-1);

    int leftData,rightData;
    cin>>leftData>>rightData;
    if(leftData!=-1)
    buildBfs(root->left,leftData);
    else
    root->left = NULL;
    if(rightData!=-1)
    buildBfs(root->right,rightData);
    else
    root->right = NULL;
    

}
//printing inorder
void PrintInorder(node *root)
{
    if(root==NULL)
    return ;
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}
// Preorder Traversal
void Preorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
//Postorder Traversal
void Postorder(node *root)
{
    if(root==NULL)
    return;
    cout<<root->data;
    Postorder(root->right);
    Postorder(root->left);
}
// Height of the tree
int height(node *root)
{
    if(root==NULL)
    return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1+max(leftHeight,rightHeight);
}
// Sum of all nodes
int sum(node *root)
{
    if(root==NULL)
    return 0;
    return root->data+sum(root->left)+sum(root->right);
}
//Diameter
//Brute Force Approach
int Diameter(node *root)
{
    if(root==NULL)
    return 0;
    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    return max(leftDiameter,max(rightDiameter,heightLeft+heightRight));
}
//Optimized Diameter
class Pair
{
    public:
    int height;
    int diameter;
};
Pair OptimizedDiameter(node *root)
{
    Pair p;
    //Base Case
    if(root==NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    //Recursive Case
    Pair left = OptimizedDiameter(root->left);
    Pair right = OptimizedDiameter(root->right);
    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.diameter,max(right.diameter,left.height+right.height));
    return p;

}
// PrintAt k level
void printKlevel(node *root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
    cout<<root->data<<" ";
    printKlevel(root->left,k-1);
    printKlevel(root->right,k-1);

}
//Printing all levels - Printing Level Wise.
void printAllLevels(node *root)
{
    int h = height(root);
    cout<<"Level Wise Print"<<endl;
    for(int i=0;i<h;i++)
    {
        printKlevel(root,i);
        cout<<endl;
    }
}
//Top View
void topView(node *root)
{
    queue<pair<node*,int>> q;
    map<int,bool> visited;
    set<pair<int,int>> s; // To print in the same order;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        node *temp = q.front().first; // For the address of q.front()
        int index = q.front().second; // For the index of q.front()
        if(visited[index]==false)
        {
            visited[index] = true;
            s.insert(make_pair(index,temp->data));
        }
        if(temp->left!=NULL)
        q.push(make_pair(temp->left,index-1));
        if(temp->right!=NULL)
        q.push(make_pair(temp->right,index+1));
        q.pop();
    }
    cout<<"Top View is->"<<endl;
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<(*it).second<<" ";
    }
    cout<<endl;
}
//Bottom View
void bottomView(node *root)
{
    queue<pair<node*,int>> q;
    map<int,bool> visited;
    set<pair<int,int>> s;
    map<int,int>lastValue;//To store the last value at particular index;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        node *temp = q.front().first;
        int index = q.front().second;
        if(visited[index]==false)
        {
            visited[index] = true;
            s.insert(make_pair(index,temp->data));
            lastValue[index] = temp->data;

        }
        else
        {
            s.erase(make_pair(index,lastValue[index]));
            s.insert(make_pair(index,temp->data));
            lastValue[index] = temp->data;
        }
        if(temp->left!=NULL)
        q.push(make_pair(temp->left,index-1));
        if(temp->right!=NULL)
        q.push(make_pair(temp->right,index+1));
        q.pop();
    }
    cout<<"Bottom View is->"<<endl;
    for(auto it=s.begin();it!=s.end();it++)
    {
        cout<<(*it).second<<" ";
    }
    cout<<endl;
}
//Left View
int level = 0;
void leftView(node *root,int nodeLevel=0)
{
    if(root==NULL)
    return;
    if(nodeLevel==0)
    cout<<root->data<<" ";
    if(nodeLevel>level)
    {
        cout<<root->data<<" ";
        level = nodeLevel;
        
    }
    leftView(root->left,nodeLevel+1);
    leftView(root->right,nodeLevel+1);

}
// Right View
void rightView(node *root,int nodeLevel=0)
{
    if(root==NULL)
    {
        return;
    }
    if(nodeLevel==0)
    cout<<root->data<<" ";
    if(nodeLevel>level)
    {
        cout<<root->data<<" ";
        level = nodeLevel;
    }
    rightView(root->right,nodeLevel+1);
    rightView(root->left,nodeLevel+1);

}

// Creating tree from inorder and preorder.
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
// Checking if the tree is height balanced or not.
bool isHeightBalanced(node *root)
{
    if(root==NULL)
    return true;
    bool leftBalanced = isHeightBalanced(root->left);
    bool rightBalanced = isHeightBalanced(root->right);
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftBalanced && rightBalanced && abs(leftHeight-rightHeight)<=1)
    return true;
    else
    return false;
}
// Creating mirror of the given tree.
void mirror(node *root)
{
    if(root==NULL)
    return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
    
}
// Finding Lowest Common Ancestor
void make_vector(node *root,int n,vector<int> &v,bool &found)
{
    if(root==NULL)
    return ;
    v.push_back(root->data);
    if(root->data==n)
    {
        found = true;
        return ;
    }
    make_vector(root->left,n,v,found);
    if(found)
    return ;
    make_vector(root->right,n,v,found);
    if(found)
    return ;

    if(!found)
    v.pop_back();
}
int lca(node *root,int n1,int n2)
{
    vector<int> v1,v2;
    bool found = false;
    make_vector(root,n1,v1,found);
    found = false;
    make_vector(root,n2,v2,found);

    //Printing the stack
    /*
    while(!v1.empty())
    {
        cout<<v1.front()<<" ";
        v1.erase(v1.begin());
    }
    cout<<endl;
    while(!v2.empty())
    {
        cout<<v2.front()<<" ";
        v2.erase(v2.begin());
    }
    cout<<endl;
    */

    //Algorithm
    int ans = 0;
    while(!v1.empty()&&!v2.empty())
    {
        if(v1.front()==v2.front())
        {
            ans = v1.front();
            
        }
        v1.erase(v1.begin());
        v2.erase(v2.begin());
    }
    return ans;

}
int lcaOptimized(node *root,int n1,int n2)//Optimizing Space
{
    if(root==NULL)
    return -1;
    if(root->data==n1||root->data==n2)
    return root->data;
    int left = lcaOptimized(root->left,n1,n2);
    int right = lcaOptimized(root->right,n1,n2);
    if(left==-1&&right==-1)
    return -1;
    if(left!=-1&&right!=-1)
    return root->data;
    if(left!=-1)
    return left;
    if(right!=-1)
    return right;
}

// Finding the path of any node from the root node.
void pathVector(node *root,int n,vector<int> &v)
{
    static bool found = false;
    if(root==NULL)
    return ;
    v.push_back(root->data);
    if(root->data==n)
    {
        found = true;
        return;
    }
    if(!found)
    pathVector(root->left,n,v);
    if(!found)
    pathVector(root->right,n,v);
    if(!found)
    v.pop_back();


}
vector<int> path(node *root,int n)
{
    vector<int> v;
    pathVector(root,n,v);
    return v;

}

//finding nodes at Kth distance from the particular node.
void set_distance(node *root,int n,map<int,int> &distances,map<int,int>inPath,int t=0)
{
    if(root==NULL)
    return;
    if(inPath.find(root->data)!=inPath.end())
    {
        t = inPath[root->data];
        set_distance(root->left,n,distances,inPath,t+1);
        set_distance(root->right,n,distances,inPath,t+1);
    }
    else
    {
        distances[root->data] = t;
        set_distance(root->left,n,distances,inPath,t+1);
        set_distance(root->right,n,distances,inPath,t+1);
    }
    
}

void nodesAtKDistance(node* root,int n,int k)
{
    vector<int> p; //stores the path from root to node.
    p = path(root,n);

    while(!p.empty())
    {
        cout<<p.front();
        cout<<endl;
        
        p.erase(p.begin());
    }

    map<int,int> distances;
    //storing distances of all the nodes in path and distances.
    map<int,int> inPath;
    int d = p.size()-1;
    while(!p.empty())
    {
        inPath[p.front()] = d;
        distances[p.front()] = d;
        //cout<<p.front()<<" "<<d;
        //cout<<endl;
        d--;
        p.erase(p.begin());
    }
    cout<<endl<<endl;

    //Traversing over all the nodes in path to find the distances of other nodes.
    set_distance(root,n,distances,inPath);
    //Print nodes at Kth distance by iterating over the map.
    for(auto node:distances)
    {
        cout<<node.first<<" "<<node.second;
        cout<<endl;
    }
}


int main()
{
    node *root = new node(5);
    buildBfs(root,5);
    cout<<"Inorder traversal ->"<<endl;
    PrintInorder(root);
    cout<<endl;
    cout<<"Preorder traversal ->"<<endl;
    Preorder(root);
    cout<<endl;
    int h = height(root);
    cout<<"height of the tree is -> "<<h<<endl;
    int s = sum(root);
    cout<<s<<endl;
    Pair d = OptimizedDiameter(root);
    cout<<"diameter of the tree is -> "<<d.diameter<<endl;
    cout<<"Kth level of the tree is->"<<endl;
    printKlevel(root,3);
    cout<<endl<<endl;
    printAllLevels(root);
    cout<<endl<<endl;
    topView(root);
    bottomView(root);
    cout<<"Left View of the tree-> "<<endl;
    leftView(root,0);
    cout<<endl;
    level = 0; // Global variable cannot be updates in the global scope.
    cout<<"Right View of the tree->"<<endl;
    rightView(root);

    int pre[8] = {5,1,2,3,10,11,4,5};
    int ino[8] = {1,5,11,10,3,2,4,5};
    node *root2 = createTreeFromTraversal(ino,pre,0,7);
    cout<<endl<<endl;
    PrintInorder(root2);

    cout<<endl;
    if(isHeightBalanced(root))
    cout<<"Given tree is height balanced"<<endl;
    else
    cout<<"Given tree is not height balanced"<<endl;

    mirror(root);
    printAllLevels(root);
    mirror(root);
    cout<<endl<<endl;
    int lowestCommonAncestor = lca(root,10,11);
    cout<<lowestCommonAncestor<<endl;

    cout<<lcaOptimized(root,10,11)<<endl;

    vector<int> p;//stores the path
    p = path(root,4);
    

    //printing the path
    cout<<"The path is->"<<endl;
    while(!p.empty())
    {
        cout<<p.front()<<" ";
        p.erase(p.begin());
    }
    cout<<endl;

    cout<<endl<<endl<<endl<<endl;
    nodesAtKDistance(root,4,2);
    return 0;
}
