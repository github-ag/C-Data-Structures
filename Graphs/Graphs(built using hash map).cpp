//unweighted graph containing only bidirectional edges built using hash map.

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

    void print()
    {
        //iterate over the map
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            //i.second is the linked list
            for(auto entry:i.second)
            {
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T src)//taking the source node 
    {
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            T node =q.front();
            cout<<node<<" ";
            q.pop();
            //for the neighbour of the nodes which are not visited
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    Graph<string>g;
    g.addEdge("putin","Trump");
    g.addEdge("putin","modi");
    g.addEdge("putin","pope");
    g.addEdge("modi","Trump");
    g.addEdge("modi","yogi");
    g.addEdge("yogi","prabhu");
    g.addEdge("prabhu","modi");
    
    //g.print();
    g.bfs("modi");
    return 0;

}
