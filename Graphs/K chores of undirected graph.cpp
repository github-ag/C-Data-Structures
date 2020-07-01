#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adjList;
    unordered_map<int,int> indegree;
    
    void addEdge(int u,int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    void print(){
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto ele:node.second){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
    void dfsHelper(int node,unordered_map<int,bool> &visited){
        visited[node] = true;
        for(auto ele:adjList[node]){
            indegree[ele] += 1;
            if(visited[ele]==false)
            dfsHelper(ele,visited);
        }
    }
    void dfs(){
        unordered_map<int,bool>visited;
        for(auto node:adjList){
            if(visited[node.first]==false){
                dfsHelper(node.first,visited);
            }
        }
    }
    void printIndegree(){
        cout<<"INDEGREES"<<endl;
        for(auto node:indegree){
            cout<<node.first<<"-> "<<node.second<<endl;
        }
    }
    void solution(int k){
        queue<int> q;
        unordered_map<int,bool> deleted;
        for(auto node:indegree){
            if(node.second<k){
                q.push(node.first);
            }
        }
        while(!q.empty()){
            int temp = q.front();
            for(auto ele:adjList[temp]){
                indegree[ele]-=1;
                if(indegree[ele]<k && deleted[ele]==false){
                    q.push(ele);
                }
            }
            cout<<"Removing "<<temp<<endl;
            adjList.erase(temp);
            deleted[temp] = true;
            q.pop();
        }
        cout<<"PRINTING NEW MAP"<<endl;
        for(auto node:adjList){
            cout<<node.first<<"-> ";
            for(auto ele:adjList[node.first]){
                if(deleted[ele]==false)
                cout<<ele<<", ";
            }
            cout<<endl;
        }
    }
    
};
int main(){
    Graph g;
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,7);
    g.addEdge(5,9);
    g.addEdge(5,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.addEdge(2,8);
    g.addEdge(3,4);
    g.print();
    g.dfs();
    g.printIndegree();
    g.solution(2);
    
    return 0;
}
