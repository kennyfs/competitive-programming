#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=133333+100,NUM=1e6+100;
int n,q,k;
struct query{
    int a,b,t;
};
int l,r,t,p,cnt,A[N],s[NUM],ans[N];
vector<query> Q[54][54],R;
stack<query> changed;
void move(int ql,int qr,int qt){
    while(l>ql)cnt+=!s[A[--l]]++;//l go to left
    while(r<qr)cnt+=!s[A[++r]]++;//r go to right
    while(l<ql)cnt-=!--s[A[l++]];//l go to right
    while(r>qr)cnt-=!--s[A[r--]];//r go to left
    while(t<qt){
        ++t;
        if(p>=R.size()||t<R[p].t)continue;
        changed.push({A[R[p].a],R[p].b,R[p].a});//save changing a to b, at position t
        if(ql<=R[p].a&&R[p].a<=qr){
            cnt-=!--s[A[R[p].a]];
            cnt+=!s[R[p].b]++;
        }
        A[R[p].a]=R[p].b;
        ++p;
    }
}
void undo(){
    //undo
    while(!changed.empty()){
        auto [ori,to,x]=changed.top();
        changed.pop();
        if(l<=x&&x<=r){
            cnt+=!s[to]++;
            cnt-=!--s[ori];
        }
        A[x]=ori;
    }
}
void MO(int i,int j){
    t=p=0;
    undo();
    for(auto [ql,qr,qt]:Q[i][j]){
        move(ql,qr,qt);
        ans[qt]=cnt;
    }
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>q;
    k=ceil(pow(n,(2.0/3.0)));
    for(int i=1;i<=n;++i)cin>>A[i];
    char op;
    for(int i=1,tmpa,tmpb;i<=q;++i){
        cin>>op>>tmpa>>tmpb;
        if(op=='Q')
            Q[tmpa/k][tmpa/k].pb({tmpa,tmpb,i});
        else
            R.pb({tmpa,tmpb,i});
    }
    l=0;r=-1;
    for(int i=0;i<=n/k;++i){
        for(int j=i;j<=n/k;++j){
            MO(i,j);
        }
    }
    for(int t=1;t<=q;++t){
        if(ans[t])cout<<ans[t]<<'\n';
    }
}
