#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int t,n,ind;
int a[100000];
set<int> st;
int abs(int num){
	return (num<0)?-num:num;
}
int main(){
	cin>>t;
	while(t--){
		queue<int> todo;
		st.clear();
		cin>>n;
		ind=0;
		int tmp;
		for(int i=0;i<n;++i){
			cin>>tmp;
			a[ind++]=tmp;
			st.insert(tmp);
			todo.push(tmp);
		}
		bool ok=1;
		while(!todo.empty()){
			tmp=todo.front();
			todo.pop();
			int now=ind;
			for(int j=0;j<now;++j){
				int i=a[j];
				if(i==tmp)continue;
				if(st.count(abs(i-tmp))==0){
					st.insert(abs(i-tmp));
					todo.push(abs(i-tmp));
					a[ind++]=abs(i-tmp);
				}
			}
			if(ind>300){ok=0;break;}
		}
		if(ok){
			cout<<"yes\n"<<ind<<'\n';
			for(int i=0;i<ind;++i)cout<<a[i]<<' ';
			cout<<'\n';
		}else{
			cout<<"nO\n";
		}
	}
}
