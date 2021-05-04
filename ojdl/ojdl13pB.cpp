#include <iostream>
#include <vector>
using namespace std;
int n,q,tmp;
int ai[100010];
vector<int> num[100010];
int main(){
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>tmp;
		num[tmp].push_back(i);
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		int a=0,b=0,last=-1,ans=0;
		while(a<num[x].size()||b<num[y].size()){
			if(a<num[x].size()&&(b>=num[y].size()||num[x][a]<num[y][b])){//choose x
				ans=max(ans,num[x][a]-last);
				last=num[x][a];
				++a;
			}else{
				ans=max(ans,num[y][b]-last);
				last=num[y][b];
				++b;
			}
			//cout<<a<<','<<b<<",last:"<<last<<'\n';
		}
		ans=max(ans,n-1-last);
		cout<<ans<<'\n';
	}
}
