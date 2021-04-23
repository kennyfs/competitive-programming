#include <iostream>
#include <queue>
#define Hirasawa_Yui_my_wife ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_my_wife
	int num;
	while(cin>>num&&num){
		cout<<"Discarded cards: ";
		if(num==1){
			cout<<"\nRemaining card: 1\n";
			continue;
		}
		queue<int> q;
		for(int i=1;i<=num;++i)q.push(i);
		while(q.size()>1){
			if(q.front()==1)cout<<'1';
			else cout<<", "<<q.front();
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout<<"\nRemaining card: "<<q.front()<<"\n";
	}
}
