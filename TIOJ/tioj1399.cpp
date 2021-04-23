#include <iostream>
#include <queue>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int T,t,n;
int s[100010],d[100010],r[100010];
const int INF=8e7;
pii tmp;
main(){
	Hirasawa_Yui_My_Wife
	while(cin>>T>>n&&T){
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i)cin>>d[i];
		for(int i=1;i<=n;++i)cin>>r[i];//r[i] is i-1 to 1
		int best=-INF;
		for(int e=1;e<=n;++e){//the fishing ends at i, fishing time is t-r[1]-r[2]...r[e]
			T-=r[e];t=T;
			if(t<=0)break;
			priority_queue<pii> pq;
			for(int i=1;i<=e;++i)pq.emplace(s[i],i);
			int fish,room,now=0;
			while(t--){
				if(pq.empty())break;
				tmp=pq.top();
				fish=tmp.F;room=tmp.S;
				pq.pop();
				now+=fish;
				if(fish-d[room]>0)pq.emplace(fish-d[room],room);
			}
			best=max(best,now);
		}
		cout<<best<<'\n';
	}
}
