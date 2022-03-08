#include <iostream>
using namespace std;
int const N=5e3+10,K=1e5+10,M=1e9+7;
int n,k,dp[N];
string s,ss;
void madd(int &a,int b){
    a+=b;
    if(a>M)a-=M;
}
struct node{
    char me;
    node* nxt[26];
    int cnt;
    node(){for(int i=0;i<=26;++i)nxt[i]=NULL;}
    node(char a){me=a;for(int i=0;i<=26;++i)nxt[i]=NULL;}
};
void build(int i,node *cur){
    if(i==ss.size()){cur->flag=1;return;}
    if(cur->nxt[ss[i]-'a']==NULL){
        cur->nxt[ss[i]-'a']=new node(ss[i]);
    }
    build(i+1,cur->nxt[ss[i]-'a']);
}
int main(){
    cin>>s;
    cin>>k;
    node root;
    for(int i=1;i<=k;++i){
        cin>>ss;
        build(0,&root);
    }
    for(int i=1;i<=s.size();--i){//dp[i] from size-i to size-1
        node *now=&root;
        for(int j=s.size()-i;j<s.size();++j){
            if(now->s[j]==NULL)break;
            if(now->flag)madd(dp[i],dp[s.size()-j]);
            now->
        }
    }
}
