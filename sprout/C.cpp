#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,q,r,blank;
struct pai{
	int n;
	char t;
	bool st;
	bool operator<(pai o){
		return (t==o.t)?n<o.n:t<o.t;
	}
	bool operator==(pai &o){
		return n==o.n&&t==o.t;
	}
}data[13];
istream& operator>>(istream& s,pai& a){
	s>>a.n>>a.t;
	a.st=1;
	return s;
}
int find_(pai &a){
	return lower_bound(data,data+r+1,a)-data;
}
void throw_(pai &a){
	blank=find_(a);
}
void insert_(pai &a){
	data[blank]=a;
}
void pon(pai &c1,string from,pai &c2){
	int ind=find_(c1);
	throw_(c2);
	if(c1==c2)blank++;
	insert_(c1);
	swap(data[ind],data[r--]);
	swap(data[ind+1],data[r--]);
	swap(data[blank],data[r--]);
	if(from=="left"){
		data[r+1].st=0;
	}else if(from=="opposite"){
		data[r+2].st=0;
	}else{
		data[r+3].st=0;
	}
}
void chi(pai &c1,pai &c2,pai &c3,pai &c4){//always c2<c3
	int ind=find_(c2),ind2=find_(c3);
	throw_(c4);
	if(c2==c4)blank++;
	if(c3==c4)blank++;
	insert_(c1);
	swap(data[ind2],data[r--]);
	swap(data[ind],data[r--]);
	swap(data[blank],data[r]);
	data[r--].st=0;
}
void print(){
	for(int i=0;i<13;++i){
		if(data[i].st)cout<<data[i].n;
		else cout<<"..";
	}
	cout<<'\n';
	for(int i=0;i<13;++i){
		if(data[i].st)cout<<data[i].t;
		else cout<<data[i].n<<data[i].t;
	}
	cout<<'\n';
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		for(int i=0;i<13;++i){
			cin>>data[i];
		}
		sort(data,data+13);
		print();
		r=12;
		string op,from;
		pai a,b,c,d;
		cin>>q;
		while(q--){
			cin>>op;
			if(op=="insert"){
				cin>>a>>op>>b;
				if(a==b)goto end;
				throw_(b);
				insert_(a);
			}else if(op=="pon"){
				cin>>a>>op>>from>>op>>b;
				pon(a,from,b);
			}else{
				cin>>a>>op>>b>>op>>c>>op>>d;
				if(c<b)swap(b,c);
				chi(a,b,c,d);
			}
			sort(data,data+r+1);
			end:
			print();
		}
	}
}
