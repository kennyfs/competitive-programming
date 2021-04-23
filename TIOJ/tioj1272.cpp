#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=100010;
vector<int> child[N];
int n,m,k,d;
int p[N],r[N];//p[val] points to the node,r[i] means [i,r[i]) are i's subtree;
int BIT[N];
int ind=1;
void dfs(int n){
	int cur=ind++;
	p[n]=cur;
	for(int i:child[n]){
		dfs(i);
	}
	r[cur]=ind;
}
void add(int pos,int val){
	for(;pos<=n;pos+=pos&(-pos)){
		BIT[pos]+=val;
	}
}
int query(int pos){
	int ans=0;
	for(;pos>0;pos-=pos&-pos){
		ans+=BIT[pos];
	}
	return ans;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int _=0;_<k;++_){
			cin>>d;
			child[i].push_back(d);
		}
	}
	dfs(1);
	for(int i=0;i<m;++i){
		cin>>k>>d;
		if(k==0){
			add(r[p[d]],-1);
			add(p[d],1);
		}else{
			cout<<(query(p[d])%2)<<'\n';
		}
	}
}
