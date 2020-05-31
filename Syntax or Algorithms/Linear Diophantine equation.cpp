// Solving linear diophantine equation in the particular range 
// Linear diophantine equation -> ax+by = c 
// Linear diophantine equation in the particular range -> 
// Find all values of (x,y) which satisfy ax+by=c where x lies between (min_x,max_x) and y lies between (min_y,max_y)

//CODE 
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
    int a,b,c;
    cin>>a>>b>>c;
    int xg,yg;
    int gcd = ExtendedEuclidean(a,b,xg,yg);
    int x0,y0;
    x0 = (xg*c)/gcd;
    y0 = (yg*c)/gcd;
    
    cout<<gcd<<" "<<x0<<" "<<y0<<endl;
    
    int min_x,max_x,min_y,max_y;
    cin>>min_x>>max_x>>min_y>>max_y;
    
    int k = ((min_x-x0)*gcd)/b;
    //k = k+1;
    cout<<"first k is "<<k<<endl;
    int x_ = (x0+(k*b)/gcd);
    if(x_ > max_x){
        cout<<"no solution exists"<<endl;
    }
    else{
        while(x_ < max_x){
            int y_ = (y0-(k*a)/gcd);
            if(y_<max_y && y_> min_y){
                cout<<"Solution "<<x_<<" "<<y_<<endl;
            }
            k++;
            x_ = (x0+(k*b)/gcd); 
        }
    }
    
    return 0;
}
