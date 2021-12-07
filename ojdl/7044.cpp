#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void exgcd(int a,int b,int &x,int &y){
    //a always > b
    if(b==0){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    //x:x_2 y:y_2
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}
int m,q;
int main(){
    Hirasawa_Yui_My_Wife
    cin>>m>>q;
    int a;
    while(q--){
        cin>>a;
        if(gcd(a,m)!=1){cout<<"jizz\n";continue;}
        int x,y;
        exgcd(a,m,x,y);
        cout<<(x+m)%m<<'\n';
    }
}
