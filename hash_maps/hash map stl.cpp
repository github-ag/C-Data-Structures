#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
int main()
{
    unordered_map<string,int> mymap;

    //insert in 3 ways..............................
    mymap["mango"]=100;
    mymap.insert(make_pair("apple",120));
    pair<string,int> p("Guava",130);
    mymap.insert(p);
    //cout<<p.first;

    //print...........................

    //1-node itertion (mostly(always)used)
    for(auto node:mymap)//in hash maps all the key value pairs exist similar to the pair
    {
        cout<<node.first<<","<<node.second<<endl;
    }
    cout<<endl<<endl;

    //2-bucket iteration
    for(int i=0;i<mymap.bucket_count();i++)
    {
        cout<<"bucket"<<i<<"-->";
        //iterate over every linked list
        for(auto it=mymap.begin(i);it!=mymap.end(i);it++)
        //it is a pointer to  pair
        cout<<it->first<<"["<<it->second<<"]"<<" , ";
        cout<<endl;

    }

    //search.......................
    // first way
    auto f=mymap.find("mango");
    if(f!=mymap.end())
    	cout<<"price of mango is"<<(f->second)<<endl;
    else
    	cout<<"mango doesn't exist";
    //second way
    if(mymap.count("mango"==0))
    	cout<<"mango doesn't exist";
    else
    	cout<<"price of mango is"<<mymap["mango"];

   //deletion
    mymap.erase("mango");

    return 0;


}

//while iterating nodewise node exist as a pair but while iterating bucket wise it exist as the pointer
