#include <iostream>
#include <stack>
#define Hirasawa_Yui_my_wife ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_my_wife
	int len;
	while(cin>>len&&len){
		int list[len];
		while(true){
			stack<int> s;
			cin>>list[0];
			if(!list[0])break;
			for(int i=1;i<len;++i)cin>>list[i];
			bool pass=true;
			int cur=2;
			s.push(1);
			for(int a:list){
				while(true){
					if(!s.empty()){
						if(s.top()==a){
							s.pop();
							break;
						}
					}
					s.push(cur);cur++;
					if(cur>len+1){
						pass=false;
						break;
					}
				}
				if(!pass)break;
			}
			if(pass)cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<'\n';
	}
}
