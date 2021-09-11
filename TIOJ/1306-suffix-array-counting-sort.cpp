#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define pb emplace_back
using namespace std;
int const N=10000+10;
int t,n;
string s;int q;
void counting_sort(int pos[],int rank[]){
	vector<int> cnt[n];
	int temp;
	for(int i=0;i<n;++i)temp=pos[i],cnt[rank[temp]].pb(temp);
	for(int i=0,ind=0;i<n;++i){
		for(int j:cnt[i]){
			pos[ind++]=j;
		}
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	int pos[N],rank[N],tmp[N];
	while(t--){
		cin>>s>>q;
		s+='$';
		n=s.size();
		//k = 0
		//tmp1的作用為暫存我們之後要排序的東西
		for(int i=0;i<n;++i)pos[i]=i;
		sort(pos,pos+n,[&](int a,int b){return s[a]<s[b];});
		rank[pos[0]]=0;
		for(int i=1;i<n;i++){
			rank[pos[i]]=rank[pos[i-1]]+(s[pos[i-1]]<s[pos[i]]);
		}
		for(int k=1;1<<(k-1)<n;++k){//已知以前2^(k-1)個排序完的順序，就可以算出以前2^k個排序完的順序，以第一個做排序已經在上面排好了
			//tmp2的作用為暫存我們之後要排序的東西
			for(int i=0;i<n;i++)pos[i]=(pos[i]-(1<<(k-1))+n)%n;
			counting_sort(pos,rank);
			tmp[pos[0]]=0;
			for(int i=1;i<n;i++){
				pii prev={rank[pos[i-1]],rank[(pos[i-1]+(1<<(k-1)))%n]};
				pii cur={rank[pos[i]],rank[(pos[i]+(1<<(k-1)))%n]};
				tmp[pos[i]]=tmp[pos[i-1]]+(prev<cur);
			}
			swap(tmp,rank);
		}
		//rank[n-1] is always 0 because $ is smaller than a-z
		//so never care rank[n-1] or r2i[0], as it's $xxxx
		
		//all of the ranks are distinct because the index of the first $ in all strings are distinct
		//remove '$'
		n--;
		for(int i=0;i<q;++i){
			string p;
			cin>>p;int ps=p.size();
			int l=1,r=n+1;//[l,r)
			for(int cur=0;cur<ps;++cur){//the first cur are checked, going to check cur
				//l<=real l and r>=real r
				while(l<n+1&&(pos[l]+cur>=n||s[pos[l]+cur]<p[cur]))++l;
				while(r>1&&(pos[r-1]+cur>=n||s[pos[r-1]+cur]>p[cur]))--r;
				//ensure only [l,r) match p's first cur characters
				if(l>=r){l=r;break;}
			}
			cout<<r-l<<'\n';
		}
	}
}
//reference:https://sam571128.codes/2020/10/02/Suffix-Array/
