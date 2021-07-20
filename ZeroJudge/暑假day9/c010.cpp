#include <iostream>
#include <set>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	multiset<int> st;
	int a,n=0,ind,mid;
	auto it=st.begin();
	while(cin>>a){
		st.insert(a);
		++n;
		ind=n/2;
		it=st.begin();
		while(ind)--ind,++it;
		mid=*it;if(!(n&1))mid=(mid+*(--it))/2;
		cout<<mid<<'\n';
	}
}
