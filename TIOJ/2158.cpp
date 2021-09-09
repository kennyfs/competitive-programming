#include <iostream>
#include <algorithm>
using namespace std;
int const N=2e3+10;
struct p{//pair<store,people>
	int pp,st,d,dis;
};
struct store{
	int x,y,d;
};
struct people{
	int x,y;
};
p a[N*N];
store st[N];
people pp[N];
int n,m,choice[N],chosen[N];
istream& operator>>(istream& s,store& t){
	return s>>t.x>>t.y>>t.d;
}
istream& operator>>(istream& s,people& t){
	return s>>t.x>>t.y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>st[i];
	for(int i=1;i<=m;++i)cin>>pp[i];
	int cnt=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[cnt].st=i,a[cnt].pp=j;
			a[cnt].d=st[i].d;
			a[cnt++].dis=max(abs(st[i].x-pp[j].x),abs(st[i].y-pp[j].y));
		}
	}
	sort(a+1,a+cnt,[&](p i,p j){
		return i.dis<j.dis;
	});
	int k=0,ans=0,big=0;
	for(int i=1;i<cnt;){
		k=a[i].dis;
		while(a[i].dis==k){
			if(choice[a[i].pp]==0){
				choice[a[i].pp]=a[i].st;
				chosen[a[i].st]++;
				if(chosen[a[i].st]==1)++ans;
			}else if(a[i].d>st[choice[a[i].pp]].d){
				chosen[choice[a[i].pp]]--;
				if(chosen[choice[a[i].pp]]==0)--ans;
				chosen[a[i].st]++;
				if(chosen[a[i].st]==1)++ans;
				choice[a[i].pp]=a[i].st;
			}
			++i;
			if(i>cnt)break;
		}
		big=max(big,ans);
	}
	cout<<big<<'\n';
}
