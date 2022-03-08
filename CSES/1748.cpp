#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int const N=2e5+10,M=1e9+7;
int n,len,a[N],b[N],BIT[N];
using namespace std;
void madd(int &a,int b){
    a+=b;
    if(a>M)a-=M;
}
int query(int p){
    int ans=0;
    for(;p;p-=p&-p){
        madd(ans,BIT[p]);
    }
    return ans;
}
void add(int p,int x){
    for(;p<=len;p+=p&-p){
        madd(BIT[p],x);
    }
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    sort(a+1,a+1+n);
    len=unique(a+1,a+n+1)-a-1;
    int sum=0;
    for(int i=1,ind,ans;i<=n;++i){
        ind=lower_bound(a+1,a+len+1,b[i])-a;
        ans=query(ind-1)+1;
        add(ind,ans);
        madd(sum,ans);
    }
    cout<<sum;
}
