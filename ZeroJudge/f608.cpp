#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
pii data[200010];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>data[i].X>>data[i].Y;
	sort(data,data+n);
	vector<int> s;
	s.push_back(0);
	for(int i=0;i<n;++i){
		int ay=data[i].Y;
		if(ay>=s.back())
			s.push_back(ay);
		else
			*upper_bound(s.begin(),s.end(),ay)=ay;
	}
	cout<<s.size()-1<<'\n';
}
