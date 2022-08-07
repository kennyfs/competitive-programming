#include <iostream>
using namespace std;
int main(){
    int x,y;char a;
    cin>>x>>a>>y;
    if(y<=2)cout<<x<<'-';
    else if(y<=6)cout<<x;
    else cout<<x<<'+';
    cout<<'\n';
}
