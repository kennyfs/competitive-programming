#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int const N=10000+10;
int t;
string s;int q;
int n,pos[N],myrank[N];
pair<char,int> tmp1[N];
pair<pii,int> tmp2[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>s>>q;
		s+='$';
		n=s.size();
		//k = 0
		//tmp1的作用為暫存我們之後要排序的東西
		
		for(int i=0;i<n;i++)tmp1[i]={s[i],i};
		sort(tmp1,tmp1+n);
		for(int i=0;i<n;i++)pos[i]=tmp1[i].S;
		myrank[pos[0]]=0;
		for(int i=1;i<n;i++){
			if(tmp1[i].F==tmp1[i-1].F)myrank[pos[i]]=myrank[pos[i-1]];
			else myrank[pos[i]]=myrank[pos[i-1]]+1;
		}
		int k = 1;
		while(1<<(k-1)<=n){//已知以前2^(k-1)個排序完的順序，就可以算出以前2^k個排序完的順序，以第一個做排序已經在上面排好了
			//tmp2的作用為暫存我們之後要排序的東西
			for(int i=0;i<n;i++)tmp2[i]={{myrank[i],myrank[(i+(1<<(k-1)))%n]},i};
			sort(tmp2,tmp2+n);
			for(int i=0;i<n;i++)pos[i]=tmp2[i].second;
			myrank[pos[0]]=0;
			for(int i=1;i<n;i++){
				if(tmp2[i].first==tmp2[i-1].first)myrank[pos[i]]=myrank[pos[i-1]];
				else myrank[pos[i]]=myrank[pos[i-1]]+1;
			}
			k++;
		}
		//myrank[n-1] is always 0 because $ is smaller than a-z
		//so never care myrank[n-1] or r2i[0], as it's $xxxx
		
		//all of the myranks are distinct because the index of the first $ in all strings are distinct
		//remove '$'
		int r2i[n-1];//all myrank-1, remove myrank[0]
		for(int i=0;i<n-1;++i)r2i[myrank[i]-1]=i;
		n--;
		for(int i=0;i<q;++i){
			string p;
			cin>>p;int ps=p.size();
			int l=0,r=n;//[l,r)
			for(int cur=0;cur<ps;++cur){//the first cur are checked, going to check cur
				//l<=real l and r>=real r
				while(l<n&&(r2i[l]+cur>=n||s[r2i[l]+cur]<p[cur]))++l;
				while(r>0&&(r2i[r-1]+cur>=n||s[r2i[r-1]+cur]>p[cur]))--r;
				//ensure only [l,r) match p's first cur characters
				if(l>=r){l=r;break;}
			}
			cout<<r-l<<'\n';
		}
	}
}
//reference:https://sam571128.codes/2020/10/02/Suffix-Array/
