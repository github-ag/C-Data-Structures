
#include<iostream>
#include<map>
#include<list>
using namespace std;
class Graph{
    public:
    map<int,list<int> > adjList;
    int timer;
    int parent[10000];
    int p[1000];
    Graph(){
        timer = 0;
        for(int i=0;i<1000;i++)
        {
            parent[i]=-1;
            p[i] = -1;
        }

    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void print(){
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto ele:adjList[node.first]){
                cout<<ele<<", ";
            }
            cout<<endl;
        }
    }
    void dfsHelper(int node,map<int,bool>&visited){
        if(visited[node]==true){
            return;
        }
        visited[node] = true;
        parent[node] = timer++;
        for(auto ele:adjList[node]){
            if(p[node]!=ele){
                p[ele] = node;
                dfsHelper(ele,visited);
                if(parent[ele]>parent[node]){
                    cout<<node<<" to "<<ele<<" is the bridge node"<<endl;
                }

                else{
                    parent[node] = parent[ele];
                }
            }
        }

    }
    void dfs(){
        map<int,bool>visited;
        for(auto node:adjList){
            if(visited[node.first]==false){
                parent[node.first] = timer++;
                dfsHelper(node.first,visited);
            }
        }
    }
};
int main(){
    Graph g;
    g.addEdge(1,0);
    g.addEdge(0,5);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.print();
    g.dfs();
    return 0;
}
