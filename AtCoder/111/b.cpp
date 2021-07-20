#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Would
#define you
#define please
using namespace std;
int const N=200010,NUM=400010;
int reverse[2*N],tail[NUM],pre[2*N];
//reverse[i] means an edge (i to reverse[i])
//tail[x] means the last edge of x
//pre[i] means the previous edge that starts from the same num as i starts from
int n,total=0;
bool visit[NUM];
void add(int x,int y){//add an edge of x to y
	reverse[total]=y;
	pre[total]=tail[x];
	tail[x]=total;
	++total;
}
bool dfs(int cur,int exedge){//the pre edge is exedge, don't go there.
	/*false means I will choose the other number considering all edges that contains cur:
	 * cur--
	 * | \ \
	 * a  b c
	 *choose a,b,and c but not cur */
	 
	//and true means choose cur
	visit[cur]=1;
	for(int i=tail[cur];i>=0;i=pre[i]){
		if(i==(exedge^1))continue;//for an edge of (i,j), (i,j) and (j,i) are numbered as xxxx0 and xxxx1;
		int revers=reverse[i];
		if(visit[revers])return true;
		if(dfs(revers,i))return true;
	}
	return false;
}
int main(){
	Hirasawa_Yui_My_Wife
	fill(pre,pre+N,-1);
	fill(tail,tail+NUM,-1);
	cin>>n;
	int u,v,m=0;
	while(n--){
		cin>>u>>v;
		m=max(m,max(u,v));
		add(u,v);
		add(v,u);
	}
	int ans=m;
	for(int i=1;i<m;++i)
		if(!visit[i]&&!dfs(i,-1))--ans;
	cout<<ans<<'\n';
	Would you please return 0;
}
