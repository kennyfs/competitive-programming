#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define pb emplace_back
using namespace std;
int const N=4e5+10;
int n,l;
string s;
int myrank[N],tmp[N],pos[N],lcp[N],num[N],cnt[N];
void counting_sort(int pos[],int rank[]){
	int cnt[l]={};
	for(int i=0;i<l;++i)++cnt[rank[pos[i]]];
	for(int i=1;i<l;++i)cnt[i]+=cnt[i-1];
	int ans[l];
	for(int i=l-1;i>=0;--i)
		ans[--cnt[rank[pos[i]]]]=pos[i];
	for(int i=0;i<l;i++)pos[i]=ans[i];
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	if(n==1){cin>>s;cout<<s<<'\n';return 0;}
	for(int i=0;i<n;++i){
		string tmp;
		cin>>tmp;
		s+=(i<n-1)?tmp+'$':tmp;
	}
	s+='#';
	l=s.size();
	for(int i=0;i<l;++i)pos[i]=i;
	sort(pos,pos+l,[&](int a,int b){return s[a]<s[b];});
	myrank[pos[0]]=0;
	for(int i=1;i<l;++i)//index is myrank
		myrank[pos[i]]=myrank[pos[i-1]]+(s[pos[i-1]]<s[pos[i]]);
	for(int k=1;1<<(k-1)<l;++k){
		for(int i=0;i<l;++i)pos[i]=(pos[i]-(1<<(k-1))+l)%l;
		counting_sort(pos,myrank);
		tmp[pos[0]]=0;
		for(int i=1;i<l;++i){
			pii prev={myrank[pos[i-1]],myrank[(pos[i-1]+(1<<(k-1)))%l]};
			pii cur={myrank[pos[i]],myrank[(pos[i]+(1<<(k-1)))%l]};
			tmp[pos[i]]=tmp[pos[i-1]]+(prev<cur);
		}
		for(int i=0;i<l;++i)myrank[i]=tmp[i];
	}
	int k=0;
	for(int i=0;i<l;i++){
		int pi=myrank[i];
		int j=pos[pi-1];
		while(i+k<l&&j+k<l&&s[i+k]==s[j+k])k++;
		lcp[pi]=k;
		k=max(0,k-1);
	}
	for(int i=l-1,c=0;i>=0;--i){
		if(s[i]=='$')++c;
		num[myrank[i]]=c;
	}
	int head=0,tail=1;
	int toobig=0,toosmall=n;
	while(true){
		if((!toobig)&&(!toosmall)){
			int len=1<<30;
			for(int i=tail+1;i<=head;++i)len=min(len,lcp[i]);
			if(len&&lcp[head+1]<len&&lcp[tail]<len){
				cout<<s.substr(pos[head],len)<<'\n';
				break;
			}
			++head;
			++cnt[num[head]];
			if(cnt[num[head]]==2)++toobig;
			if(cnt[num[head]]==1)--toosmall;
		}
		if(head==l&&(!toobig)){cout<<"7122\n";break;}
		while(head<l&&toosmall){
			++head;
			++cnt[num[head]];
			if(cnt[num[head]]==2)++toobig;
			if(cnt[num[head]]==1)--toosmall;
		}
		while(tail<head&&toobig){
			--cnt[num[tail]];
			if(cnt[num[tail]]==0)++toosmall;
			if(cnt[num[tail]]==1)--toobig;
			++tail;
		}
	}
}
