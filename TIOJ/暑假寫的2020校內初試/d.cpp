#include <iostream>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int const N=5010;
ll x[N],y[N],z[N];
int n;
int p[N];
struct edge{
	int start;
	ll len;
	int end;
};
bool cmp(edge& a,edge& b){
	return a.len<b.len;
}
int find(int& a){
	if(p[a]==a)return a;
	p[a]=find(p[a]);
	return p[a];
}
edge edges[12600000];
int total=0;
inline ll read(){
	ll x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i){
		x[i]=read();y[i]=read();z[i]=read();
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i>=j)continue;
			edges[total].start=i;
			edges[total].len=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
			edges[total++].end=j;
		}
		p[i]=i;
	}
	sort(edges,edges+total,cmp);
	ll ans=0;
	int j,k;
	for(int i=0;i<total;++i){
		j=find(edges[i].start);
		k=find(edges[i].end);
		if(j==k)continue;
		p[j]=k;
		ans+=edges[i].len;
	}
	cout<<ans<<'\n';
}
