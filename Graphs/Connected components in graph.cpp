#include<iostream>
#include<map>
#include<list>
using namespace std;
class Graph{
    public:
    map<int,list<int> >adjList;
    int sno = 0;
    map<int,int> snumber;
    Graph(int n){
        for(int i=0;i<=n;i++){
            snumber[i] = -1;
        }
    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);
    }
    void print(){
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto child:adjList[node.first]){
                cout<<child<<", ";
            }
            cout<<endl;
        }
    }
    void set_snumber(list<int> l,int child,int node){
        std::list<int>::iterator it;
        bool flag = false;
        for(it = l.begin();it!=l.end();it++){
            cout<<*it<<"  ";
            if(*it == child)
            flag = true;
            if(flag==true){
                snumber[*it] = sno;
            }
            if(*it == node){
                cout<<endl;
                return;
            }
            
        }
    }
    void dfsHelper(int node,map<int,bool> &visited,map<int,bool> &inlist,list<int> &l){
        visited[node] = true;
        l.push_back(node);
        inlist[node] = true;
        for(auto child:adjList[node]){
            if(visited[child]==true){
                if(inlist[child]==true){
                    if(snumber[child]!=-1)
                    snumber[node]=snumber[child];
                    else{
                        set_snumber(l,child,node);
                        sno+=1;
                    }
                }
                else if(snumber[child]!=-1)
                snumber[node] = snumber[child];
            }
            else{
                dfsHelper(child,visited,inlist,l);
                if(snumber[child]!=-1){
                    snumber[node] = snumber[child];
                }
            }
            
        }
        l.pop_back();
        inlist[node] = false;
        if(snumber[node]==-1)
        sno+=1;
        return;
        
    }
    
    int dfs(){
        map<int,bool>visited;
        map<int,bool>inlist;
        
        list<int>l;
        for(auto node:adjList){
            if(visited[node.first]==false){
                dfsHelper(node.first,visited,inlist,l);
            }
        }
        return sno;
    }
    
    
};
int main(){
    Graph g(4);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    //g.addEdge(3,5);
    //g.addEdge(5,1);
    g.print();
    cout<<g.dfs();
    return 0;
}
