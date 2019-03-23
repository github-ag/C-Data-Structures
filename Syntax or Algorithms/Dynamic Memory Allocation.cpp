 #include<iostream>
using namespace std;
int main()
{
    int *a = new int(30);//initialization is done using curve brackets
    cout<<*a<<endl;
    cout<<a<<endl;
    
    
    int *arr = new int[5];
    for(int i=0;i<5;i++)
    arr[i]=i*i;
    for(int j=0;j<5;j++)
    cout<<arr[j]<<" ";

    //delete operator
    delete a;
    delete []arr;

// Dynamic Memory Allocation in 2-D arrays.

 int **arr = new int*[3];//created a primary array in the heap area
    for(int i=0;i<3;i++)
    {
        arr[i]=new int[4];//created a secondary arrays of size 4;

    }
    int counter=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr[i][j]=counter;
            counter++;
        }

    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting a 2-D array
    for(int i=0;i<3;i++)
    {
        delete []arr[i];//deleting secondary arrays first

    }
    delete []arr;
    //deleting primary array
    return 0;
   }
