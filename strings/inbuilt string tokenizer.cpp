#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[]={"hi, Abhishek here, a Programmer"};
    char *ptr;
    ptr = strtok(str," ,");//to tokenize about both space and comma
    while(ptr!=NULL)
    {
        cout<<ptr<<endl;
        ptr = strtok(NULL," ,");
    }
    return 0;
}
