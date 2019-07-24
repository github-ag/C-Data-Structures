#include<bits/stdc++.h>
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
    void dfsHelper(T node,map<T,bool> &visited,list<T> & ordering)
    {
        visited[node]=true;
        //will call dfs on the unvisited neighbors of the current node.
        for(T neighbors:adjList[node])
        {
            
            if(!visited[neighbors])
            dfsHelper(neighbors,visited,ordering);
        }
        //add 1 line for topological sort
        //at this point all the children of the current node has been visited 
        //so we can add current node to the list.
        ordering.push_front(node);
    }
    void dfsTopologicalSort()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto i:adjList)
        {
            // i is a pair of node followed by list
            T node = i.first;
            if(!visited[node])
            {
                dfsHelper(node,visited,ordering);
            }
        }
        for(T element:ordering)
        {
            cout<<element<<"-->";
        }
    }
};

int main()
{
    Graph<string>g;
    g.addEdge("english","programming logic",false);
    g.addEdge("maths","programming logic",false);
    g.addEdge("programming logic","HTML",false);
    g.addEdge("programming logic","python",false);
    g.addEdge("programming logic","java",false);
    g.addEdge("programming logic","js",false);
    g.addEdge("python","web dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","web dev",false);
    g.addEdge("java","web dev",false);
    g.addEdge("python","web dev",false);

    g.dfsTopologicalSort();
    return 0;

}
