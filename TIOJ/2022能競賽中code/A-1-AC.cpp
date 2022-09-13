#include <iostream>
using namespace std;
int n,a[7][7];
int rest[10];//rest[i]: day i who rest
int cur(int d){
    if(d==7)return 1;
    int ans=0;
    for(int p=1;p<=6;++p){
        if(a[p][d])continue;
        ans+=cur(d+1);
    }
    return ans;
}
int main(){
    int tmp;
    for(int i=1;i<=6;++i){
        cin>>n;
        for(int j=1;j<=n;++j){
            cin>>tmp;a[i][tmp]=1;
        }
    }
    cout<<cur(1);
}
