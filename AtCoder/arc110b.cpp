#include <iostream>
#define ll long long
using namespace std;
int n;
char t;
string s;
int main(){
	cin>>n;
	bool out=0;
	int fz=-1;//first zero
	cin>>s;
	if(s=="11"){cout<<"10000000000\n";return 0;}
	if(s=="1"){cout<<"20000000000\n";return 0;}
	if(s=="0"){cout<<"10000000000\n";return 0;}
	for(int i=0;i<n;++i){
		t=s[i];
		if(fz+1){
			if(t=='0'){
				if((i-fz)%3!=0)out=1;
			}else if((i-fz)%3==0){
				out=1;
			}
		}
		if(out)break;
		if(t=='0'&&fz==-1)fz=i;
		if(t=='1'&&fz==-1&&i>=2)out=1;
	}
	ll all=30000000000;
	if(out) cout<<"0\n";
	else cout<<(all-(n-fz+2))/3+1<<'\n';
}
