#include<iostream>
using namespace std;
void prime_seive(int *ps,long long size)//size represent the range upto which we require the prime seive .
{
    //initially all the elements of the prime seive are 0.
    //step 1
    ps[0]=ps[1]=0;
    ps[2]=1;
    //step 2-->mark all the odd numbers as 1.
    for(long long i=3;i<=size;i=i+2)
    {
        ps[i]=1;
    }
    //step 3-->marking all the multiples of odd numbers as 1.
    for(long long i=3;i<=size;i=i+2)
    {
        if(ps[i])
        {
            for(long long j=i*i;j<=size;j=j+(2*i))
            {
                ps[j]=0;
            }
        }
    }

}
int main()
{
    int ps[1000005]={0};
    prime_seive(ps,1000005);
    // Now ps is the prime seive required.
    // to print primt numbers between let 100 and 200
    for(int i=100;i<200;i++)
    {
        if(ps[i]==1)
        cout<<i<<" ,";
    }
    return 0;
}
