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
    void topologicalSort()
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;

        // iniitializind indegree of every node as zero.
        for(auto i:adjList)
        {
            //i is pair of node and its list
            T node = i.first;
            visited[node] = false;
            indegree[node] =0;
        }

        //initializing indegrees
        for(auto i:adjList)
        {
            T u =i.first;
            for(T v:adjList[u])
            {
                indegree[v]++;
            }
         }
         //find all the nodes with zero indegrees
         for(auto i:adjList)
         {
             T node  = i.first;
             if(indegree[node]==0)
             {
                 q.push(node);
             }
         }
         // Start with algorithm
    while(!q.empty())
    {
         T node = q.front();
         q.pop();
         cout<<node<<"-->";
         for(T neighbor:adjList[node])
         {
             indegree[neighbor]--;
             if(indegree[neighbor]==0)
             {
                 q.push(neighbor);
             }
         }


    }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("english","programming logic",false);
    g.addEdge("maths","programming logic",false);
    g.addEdge("programming logic","html",false);
    g.addEdge("programming logic","python",false);
    g.addEdge("programming logic","java",false);
    g.addEdge("programming logic","js",false);
    g.addEdge("python","web dev",false);
    g.addEdge("html","css",false);
    g.addEdge("css","js",false);
    g.addEdge("js","web dev",false);
    g.addEdge("java","web dev",false);
    g.addEdge("python","web dev",false);

    g.topologicalSort();
    return 0;

}
