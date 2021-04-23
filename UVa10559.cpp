#include <iostream>
using namespace std;
const int N=205;
int q,n,l[N],color[N],ind=0,last;
int main(){
	cin>>q;
	while(q--){
		cin>>n;cin>>l[0];last=l[0];
		for(int i=1;i<n;++i){
			cin>>l[i];
			if(l[i]==last) ++l[ind];
			else l[++ind]=1,last=color[ind]=l[i];
		}
		for(int i=0;i<=ind;++i)cout<<color[i]<<":"<<l[i]<<'\n';
	}
}
