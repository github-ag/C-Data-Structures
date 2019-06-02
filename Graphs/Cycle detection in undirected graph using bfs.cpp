#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T> >adjList;
    public:
    Graph()
    {
        //We do not require the number of vertices in this case because hash maps are dynamic.
    }
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void is_cycle(T src)
    {
        queue<T> q;
        map<T,T> parent;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(T neighbor:adjList[node])
            {
                if(visited[neighbor]==false)
                {
                    parent[neighbor]=node;
                    visited[neighbor]=true;
                    q.push(neighbor);
                        
                }
                else if(visited[neighbor]==true&&parent[node]!=neighbor)
                {
                    cout<<"cycle is present ";
                    return;
                }
                    
            }

        }
         cout<<"cycle is not present";
        
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,4);
    g.is_cycle(1);
    return 0;
}
