/*           OJDL TestCase Generater             */
/*  Made by FHVirus with patience for cin/cout   */
/*
How this works:
1.  Generate a file (testcase#.in)
2.  Read that file as input and solve,
    output to another file(testcase#.out)

How to use it:
0.  Put this program into a folder where
    you want to store the testcases.
1.  Input number of subtasks
2.  For each subtask, input the number of
    desired testcase for the subtask, then
    the arguments for generate().
3.  Done!
*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define INF 8000000
#define GOAL 250000
#define ll long long
using namespace std;

auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);

// For generate(), you can add additional arguments
// for generating a testcase.
// But for solve(), just write a normal solution
// like that in main() for most of the time.
int const N=1e3+10;
int s[N][N],dp[N][N];
struct g{int t,v;}all[N*N];
int n,m,k,u;
bool operator<(g a,g b){return a.v>b.v;}
priority_queue<g> pq;
set<pii> st;
void generate(ofstream &cout){
	uniform_int_distribution<int> szd(700,700),vd(0,1000);
	n=szd(mt);m=szd(mt);
	uniform_int_distribution<int> kud(0,n*m*0.8),nd(1,n),md(1,m);
	k=kud(mt);u=kud(mt);
	cout<<n<<' '<<m<<' '<<k<<' '<<u<<'\n';
	for(int i=0;i<n;++i){for(int j=0;j<m;++j)cout<<vd(mt)<<' ';cout<<'\n';}
	int x,y;
	st.clear();
	for(int i=0;i<k;++i){
		x=nd(mt),y=md(mt);
		while(st.find({x,y})!=st.end())x=nd(mt),y=md(mt);
		cout<<x<<' '<<y<<'\n';
		st.insert({x,y});
	}
	st.clear();
	for(int i=0;i<u;++i){
		x=nd(mt),y=md(mt);
		while(st.find({x,y})!=st.end())x=nd(mt),y=md(mt);
		cout<<nd(mt)<<' '<<x<<' '<<y<<'\n';
		st.insert({x,y});
	}
}
bool solve(ifstream &cin, ofstream &cout){
	cin>>n>>m>>k>>u;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>s[i][j];
		}
	}
	int t,x,y;
	for(int i=1;i<=k;++i){
		cin>>x>>y;
		s[x][y]=-INF;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			all[(i-1)*m+j-1]={INF,s[i][j]};
		}
	}
	while(u--){
		cin>>t>>x>>y;
		if(t<=x+y-1)s[x][y]=-INF,all[(x-1)*m+y-1].t=t-1;
	}
	//dp
	clock_t begin_time = clock();
	int dpminstep=INF;
	for(int i=1;i<=n;++i){dp[i][1]=dp[i-1][1]+s[i][1];if(s[i][1]<0)dp[i][1]=-INF;if((dp[i][1]<<1)>=GOAL)dpminstep=min(dpminstep,i);}
	for(int i=1;i<=m;++i){dp[1][i]=dp[1][i-1]+s[1][i];if(s[1][i]<0)dp[1][i]=-INF;if((dp[1][i]<<1)>=GOAL)dpminstep=min(dpminstep,i);}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+s[i][j];
			if(s[i][j]<0)dp[i][j]=-INF;
			if((dp[i][j]<<1)>=GOAL)dpminstep=min(dpminstep,i+j-1);
		}
	}
	std::cout<<"dp: "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<'\n';
	begin_time = clock();
	sort(all,all+n*m,[&](g a,g b){return a.t<b.t;});
	std::cout<<"sort: "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<'\n';
	begin_time = clock();
	int l=1,r=n*m+1,st=0;//[l,r)
	while(all[st].t==0)st++;
	while(l<r){
		while(!pq.empty())pq.pop();
		ll now=0;int M=(l+r)>>1;
		for(int i=st;i<n*m;++i){
			if(all[i].v<0)continue;
			if(all[i].t<=pq.size()||pq.size()==M){if(all[i].v>pq.top().v)now+=all[i].v-pq.top().v,pq.pop(),pq.push(all[i]);}
			else{pq.push(all[i]);now+=all[i].v;}
		}
		if(GOAL<=now)r=M;
		else l=M+1;
	}
	//cout<<dpminstep<<' '<<l<<'\n';
	cout<<dpminstep<<' '<<l<<'\n';
	std::cout<<"greedy: "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<'\n';
	if(dpminstep==INF&&l==n*m+1){cout<<"NO Giita QQ\n";return 0;}
	else cout<<min(dpminstep,l)<<'\n';
	return 1;
}

int main(){
    int testcaseCount;
	int numOfTestCase;
	cin >> numOfTestCase>>testcaseCount;
	// You can add some other arguments for
	// generating testcases.
	int sum=0;
	for(int i=0;i< numOfTestCase; ++i, ++testcaseCount){
		cout<<"flag1"<<endl;
		string in = to_string(testcaseCount) + ".in";
		string ou = to_string(testcaseCount) + ".out";
		{
			ofstream tsezi;
			tsezi.open(in);
			// Remember to add arguments here too.
			generate(tsezi);
			tsezi.close();
		}
		{
			ifstream tsezi;
			ofstream da_an;
			tsezi.open(in);
			da_an.open(ou);
			clock_t begin_time = clock();
			sum+=solve(tsezi, da_an);
			// do something
			cout << "final: "<<float( clock () - begin_time ) /  CLOCKS_PER_SEC<<'\n';
			tsezi.close();
			da_an.close();
		}
	}
	cout<<sum<<'\n';
    return 0;
}
