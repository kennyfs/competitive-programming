#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define int long long
const int N=1e9+10,K=2e5+10;
int n,m,k;
int pos[K];
set<int> st;
int tonum(int x,int y){
	int ans=(x-1)*m;
	if(x&1)ans+=y;
	else ans+=m-y+1;
	return ans;
}
signed main(){
	cin>>n>>m>>k;
	int x,y;
	int stk=0;
	while(k--){
		cin>>x>>y;
		pos[stk++]=tonum(x,y);
		st.insert(pos[stk-1]);
	}
	sort(pos,pos+stk);
	int cur=0,step=0;
	for(int i=0;i<stk;++i){
		if(cur>=pos[i])continue;
		step+=(pos[i]-cur-1)/6;cur+=(pos[i]-cur-1)/6*6;
		int nxt=6;
		while(nxt){
			if(!st.count(cur+nxt))break;
			--nxt;
		}
		if(!nxt){cout<<"-1\n";return 0;}
		step++;
		cur+=nxt;
	}
	if(cur<n*m){
		step+=(n*m-cur)/6;cur+=(n*m-cur)/6*6;
		if(cur!=n*m)step++;
	}
	cout<<step<<'\n';
}
