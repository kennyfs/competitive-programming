#include <bits/stdc++.h>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 25
#define pii pair<int,int>
#define p first
#define c second
#define pb push_back
#define iter(x) (x).begin(),(x).end()
using namespace std;
const int N=2.5e5+10,inf=8e7*wiwiho;
int n;
vector<pii> arrx[N],arry[N<<1];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1,x,y,c;i<=n;++i){
		cin>>x>>y>>c;
		y+=30000;
		arrx[x].pb({y,c});
		arry[y].pb({x,c});
	}
	for(int i=0;i<=30000;++i){
		if(!arrx[i].empty())sort(iter(arrx[i]));
		if(!arry[i].empty())sort(iter(arry[i]));
		if(!arry[i+30001].empty())sort(iter(arry[i+30001]));
	}
	int x=0,y=30000,d=4,cnt=0;//up, down, left, right
	while(true){
		pii pxi={x,0}, pxa={x,5}, pyi={y,0}, pya={y,5};
		if(d==1){
			auto s=upper_bound(iter(arrx[x]),pya);
			if(s==arrx[x].end())break;
			y=(*s).p;
			if((*s).c)d=3;
			else d=4;
		}else if(d==2){
			auto s=lower_bound(iter(arrx[x]),pyi);
			if(s==arry[y].begin())break;
			s=prev(s);
			y=(*s).p;
			if((*s).c)d=4;
			else d=3;
		}else if(d==3){
			auto s=lower_bound(iter(arry[y]),pxi);
			if(s==arry[y].begin())break;
			s=prev(s);
			x=(*s).p;
			if((*s).c)d=1;
			else d=2;
		}else{
			auto s=upper_bound(iter(arry[y]),pxa);
			if(s==arry[y].end())break;
			x=(*s).p;
			if((*s).c)d=2;
			else d=1;
		}
		cnt++;
	}
	cout<<cnt;
}
