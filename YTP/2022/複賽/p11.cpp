#include <bits/stdc++.h>
using namespace std;
const int N=4e3;
bool t[N];
bool toi(int i){
}
bool geti(int i){
    int ind=lower_bound(t+1,t+N,i)-t;
    return (i%2)^((ind/2)%2);
}
int main(){
    t[1]=0;
    for(int i=2;i<N;++i){
        int d=i*(i+1)/2;
        if(t[i-1]==1){
            if(i%2==1)t[i]=!toi(i);
            else t[i]=toi(i);
        }else{
            t[i]=1;
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        int a,ans=0;
        for(int i=1;i<=n;++i){
            cin>>a;
            ans^=geti(a);
        }
        if(ans)cout<<"MM\n";
        else cout<<"TT\n";
    }
}
//時間不夠，沒寫完
