#include <iostream>
#define ll long long
using namespace std;
int const N=10000+10;
ll const P=257,M=998244353;
ll hashes[N],modp[N];
string S;
ll myhash(string s){
	ll h=0;
	for(char c:s){
		h=((h*P)%M+c)%M;
	}
	return h;
}
void dohashes(){
	ll h=0;
	int index=0;
	for(char c:S){
		h=((h*P)%M+c)%M;
		hashes[index++]=h;
	}
}
void makemodp(int base,int exp){
	modp[0]=1;
	for(int e=1;e<=exp;e++){
		modp[e]=modp[e-1]*base%M;
	}
}
ll getsubstrhash(int start,int len){
	return ((hashes[start+len-1]-hashes[start-1]*modp[len])%M+M)%M;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	makemodp(P,10000);
	for(int i=0;i<n;i++){
		int q;
		cin>>S>>q;
		dohashes();
		string check;
		int check_hash;
		for(int j=0;j<q;j++){
			cin>>check;
			int len=check.size(),match=0;
			check_hash=myhash(check);
			for(int start=0;start+len<=S.size();start++){
				if(check_hash==getsubstrhash(start,len)){
					match++;
				}
			}
			cout<<match<<"\n";
		}
	}
}
