// Extended Euclidean Algorithm
#include<iostream>
using namespace std;
int ExtendedEuclidean(int a,int b,int &x,int &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1;
    int gcd = ExtendedEuclidean(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return gcd;
}
int main(){
    int a,b;
    cin>>a>>b;
    int x,y;
    int gcd = ExtendedEuclidean(a,b,x,y);
    cout<<gcd<<" "<<x<<" "<<y;
    return 0;
}
