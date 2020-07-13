//Union find algorithm (weight balanced algorithm)
// Both Union and find algorithm will take O(log n)time.

#include<iostream>
using namespace std;
int root(int a,int *parent){
    int temp = a;
    while(parent[temp] != temp){
        temp = parent[temp];
    }
    return temp;
}
void unionOp(int a,int b,int *parent,int *size){
    int root_a = root(a,parent);
    int root_b = root(b,parent);
    if(size[root_a]<size[root_b]){
        parent[root_a] = root_b;
        size[root_b]+=1;
    }
    else{
        parent[root_b] = root_a;
        size[root_a]+=1;
    }
}
bool find(int a,int b,int *parent){
    int root_a = root(a,parent);
    int root_b = root(b,parent);
    if(root_a == root_b)
    return true;
    else
    return false;
}
void print(int n,int *parent){
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<parent[i]<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int ch; // ch -> 0 (union), 1(find), 2(exit).
    int a,b;
    int parent[100000];
    int size[100000];
    for(int i=0;i<n;i++){
        parent[i] = i;
        size[i] = 1;
    }
    while(1){
        cin>>ch;
        if(ch==0){
            cin>>a>>b;
            unionOp(a,b,parent,size);
        }
        if(ch==1){
            cin>>a>>b;
            if(find(a,b,parent))
            cout<<"Present in same subset"<<endl;
            else
            cout<<"Present in different subset"<<endl;
        }
        if(ch==2){
            break;
        }
        
    }
    print(n,parent);
    return 0;
}
