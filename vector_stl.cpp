#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.reserve(100);//makes its capacity initially to 100
    // it is better to initially reserve some capacity as exapnding array is expensive function
    for(int i=0;i<=5;i++)
        v.push_back(i*i);
    for(int j=0;j<v.size();j++)
    {
        cout<<v.at(j)<<" ";
    }
    vector<int> v2(3,100);
    cout<<"\n";
    for(int k=0;k<v2.size();k++)
        cout<<v2[k]<<" ";

    //swap function
    swap(v,v2);
    cout<<"\nvalues after swapping are->\n";
      for(int j=0;j<v.size();j++)
    {
        cout<<v.at(j)<<" ";
    }
    cout<<"\n";
    for(int k=0;k<v2.size();k++)
        cout<<v2[k]<<" ";


    cout<<"\nmax size->"<<v.max_size();//depends upom the RAM
    cout<<"\ncapacity ->"<<v.capacity();
    
    //sorting in the vector
    sort(v.begin(),v.end());
    //clearing the whole vector
    v.clear();
    return 0;
}
