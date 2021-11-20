#include <iostream>
using namespace std;
const int N=3e5+10;
int n;
char c;
bool a[N];
void click(int i){
    a[i]^=1;
    if(i-1>=1)a[i-1]^=1;
    if(i+1<=n)a[i+1]^=1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c;
        if(c-'0')a[i]=1;
        else a[i]=0;
    }
    for(int i=1;i<=n-1;++i){
        if(!a[i])click(i+1);
        /*for(int j=1;j<=n;++j) cout<<a[j]<<' ';
        cout<<'\n';*/
    }
    if(a[n])cout<<"Yes\n";
    else{
        if(n%3==2)cout<<"No\n";
        else cout<<"Yes\n";
    }
}
