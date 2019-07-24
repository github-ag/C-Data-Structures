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
    bool is_cycle_helper(T src,map<T,bool> &visited,map<T,bool> &inStack)
    {
        //Base case
        if(visited[src]==true&&inStack[src]==true)
        return true;
        visited[src]=true;
        inStack[true]=true;
        for(T neighbor:adjList[src])
        {
             if(is_cycle_helper(neighbor,visited,inStack))
             {
                 return true;
                 
             }
        }
        inStack[src]=false;
        return false;
    }
    void is_cycle(T src)
    {
        map<T,bool> visited;
        map<T,bool> inStack;
        if(is_cycle_helper(src,visited,inStack))
        {
            cout<<"cycle is present ";
        
        }
        else
        {
            cout<<"cycle is not present";
        }

    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1,false);
    g.addEdge(1,5,false);
    g.addEdge(4,5,false);
    g.addEdge(2,4,false);
    g.addEdge(2,3,false);
    g.addEdge(0,2,false);
    g.addEdge(3,0,false);
    
    g.is_cycle(0);
    return 0;
}
