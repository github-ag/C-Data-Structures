#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;
template<typename T>

class Graph 
{
    unordered_map<T,list<pair<T,int>> >adjList;

    public:
    void addEdge(T u,T v,int dist,bool bidir = true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(bidir==true)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }

    void print()
    {
        for(auto j:adjList)
        {
            cout<<j.first<<"-->";
            for(auto l: j.second)
            {
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }

    }

    void dijsktraSSSP (T src)
    {
        unordered_map<T,int> dist;
        //Set all distance to infinity
        for(auto j:adjList)
        {
            dist[j.first] = INT_MAX;
        }
        //Make a set to find out the minimum distance
        set<pair<int,T> >s; // sorting in the set is done with respect to the first parameter
                            // therefore we have kept the first parameter as distance.
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over neighbors/children of the current node.
            for(auto childPair:adjList[node])
            {
                if(nodeDist + childPair.second<dist[childPair.first])
                {
                    //In the set updation is not possible
                    //we have to remove the old pair and insert the new pair to stimulate updation.
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    //insert the new pair
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }
        }

        //Lets print distances to all other nodes from src.
        for(auto d:dist)
        {
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }

    }


};
int main()
{
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);

    india.dijsktraSSSP("Amritsar");
    return 0;
    
}
