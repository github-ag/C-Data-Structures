// Building segment tree using array. (Soloving min range query question)
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
void buildTree(int *a,int n,int *tree,int index,int s,int e){
    //Base Case
    if(s>e)
    return;
    if(s==e){
        tree[index] = a[s];
        return;
    }
    //Recursive Case
    int mid = (s+e)/2;
    // Find the left child.
    buildTree(a,n,tree,2*index,s,mid);
    //Find the right child.
    buildTree(a,n,tree,2*index+1,mid+1,e);

    int left = tree[2*index];
    int right = tree[2*index+1];
    tree[index] = min(left,right);
}
void printTree(int *tree,int n){
    for(int i=0;i<(4*n+1);i++){
        cout<<tree[i]<<" ";
    }
}
int query(int low,int high,int *tree,int index,int s,int e){
    // Case 1-> Complete overlap
    if(low<=s && high>=e){
        return tree[index];
    }
    //Case 2->No Overlap
    else if(low>e || high<s){
        return INT_MAX;
    }
    //Case 3-> Partial Overlap
    int mid = (s+e)/2;
    int left = query(low,high,tree,2*index,s,mid);
    int right = query(low,high,tree,(2*index)+1,mid+1,e);
    return min(left,right);
}
int update(int j,int up,int *tree,int index,int s,int e){ // j is the index of the array needs to be updated.
    // Base case -> if we reached the node that needs to be updated.
    if(s==e && s==j){
        tree[index] = up;
        return tree[index];
    }
    if(s>j || j>e){
        return tree[index];
    }
    int mid = (s+e)/2;
    int left = update(j,up,tree,2*index,s,mid);
    int right = update(j,up,tree,2*index+1,mid+1,e);
    tree[index] = min(left,right);
    return tree[index];
}
int main(){
    int n,a[100000],q;
    cin>>n;
    int *tree = new int[4*n+1];
    tree[0] = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildTree(a,n,tree,1,0,n-1);
    cin>>q;
    int low,high,up,j;
    char ch;
    
    for(int i=0;i<q;i++){
        cin>>ch;
        if(ch=='q'){
            cin>>low>>high;
            cout<<query(low,high,tree,1,0,n-1)<<endl; 
        }
        else{
            cin>>j>>up;
            int temp = update(j,up,tree,1,0,n-1);
        }   
    }
    printTree(tree,n);
    return 0;
}
