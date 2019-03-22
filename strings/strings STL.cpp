#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string s1("Hello World");
    cout<<s1<<endl;
    string s2="Another Way";
    //we can also iterate over different characters of string
    for(int j=0;j<s2.length();j++)
    {
        cout<<s2[j]<<"-";
    }
    cout<<endl;
    cout<<s2<<endl;
    string s3;
    getline(cin,s3);//getline function
    cout<<s3<<endl;
    cout<<s3.length()<<endl;//length function
    //array of strings
    string arr[3]={"Apple","Mango","Banana"};
    for(int i=0;i<3;i++)
    cout<<arr[i]<<" ";
    //sorting of the string
    cout<<endl;
    sort(arr,arr+3);
    for(int i=0;i<3;i++)
    cout<<arr[i]<<" ";//sorting is done lexographically
    //we can use comparitors to sort the strings on the basis of length.


    return 0;
    
}
