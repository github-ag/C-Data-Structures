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

    //Calculating Single Source Shortest Path(SSSP) for unweighted graph.
    void shortest_path(T src)//calculate the shortest path for unweighted array for all the nodes from the source node.
    {
        queue<T> q;
        map<T,int> distance;
        for(auto i:adjList)
        {
            distance[i.first]=INT_MAX;
        }
        q.push(src);
        distance[src] = 0;
        while(!q.empty())
        {
            T node =q.front();
            cout<<node<<"-> at a distance "<<distance[node];
            cout<<endl;
            q.pop();
            
            for(auto neighbour:adjList[node])
            {
                if(distance[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    distance[neighbour] = distance[node]+1;
                }
            }
        }
    }
};

void dfsHelper(T node,map<T,bool> &visited)
    {
            //whenever come to a node mark it visited
            visited[node] = true;
            cout<<node<<" ";
            for(auto neighbor:adjList[node])
            {
                if(!visited[neighbor])
                {
                    dfsHelper(neighbor,visited);
                }
            }
        }
int dfs(T src) // return type is int as it would return the number of components
    {
        map<T,bool> visited;
        dfsHelper(src,visited);
        cout<<endl;



        //Adding the code for counting the number of connected components in the graph
        int component =1;
        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
                dfsHelper(i.first,visited);
                component++;
                cout<<endl;
            }
        }

    }

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
    g.addEdge("rahul","sonia");
    //g.print();
    //g.bfs("modi");
    cout<<endl;
    cout<<g.dfs("modi");
    return 0;

}
