// Area of the polygon with given n ordered vertices.
#include<iostream>
using namespace std;
class Pair{
    public:
    int x;
    int y;
};
float triangleArea(Pair a, Pair b, Pair c){
    int x1 = a.x-b.x;
    int y1 = a.y-b.y;
    int x2 = a.x-c.x;
    int y2 = a.y-c.y;
    
    return (x1*y2)-(x2*y1);
}
float findArea(Pair *vertices,int n){
    
    if(n<=2){
        return 0;
    }
    int i=1;
    int j=2;
    float area = 0;
    while(j<n){
        float temp = triangleArea(vertices[0],vertices[i],vertices[j]);
        area+=(temp/2);
        i++;
        j++;
    }
    return area;
    
}
int main(){
    int n;
    cin>>n;
    Pair vertices[n];
    for(int i=0;i<n;i++){
        cin>>vertices[i].x;
    }
    for(int i=0;i<n;i++){
        cin>>vertices[i].y;
    }
    /*
    for(int i=0;i<n;i++){
        cout<<vertices[i].x<<" "<<vertices[i].y<<endl;
    }*/
    float area = findArea(vertices,n);
    cout<<area<<endl;
    return 0;
}
