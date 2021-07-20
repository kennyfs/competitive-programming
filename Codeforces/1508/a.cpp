#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+5;
int t,n;
string mydata[3];
string ans(3*N,'0');
bool ty(string& a){
	int tmp[2]={0,0};
	for(char c:a){
		++tmp[c-'0'];
	}
	return tmp[0]<tmp[1];
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		bool ch[3];
		for(int i=0;i<3;++i){
			cin>>mydata[i];
			ch[i]=ty(mydata[i]);
		}
		bool flag=0;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){if(i>=j||ch[i]!=ch[j])continue;
				int ind1=0,ind2=0,ind=0;
				char nch=ch[i]?'1':'0';
				while(ind1<2*n&&ind2<2*n){
					if(mydata[i][ind1]==nch&&mydata[j][ind2]==nch){
						ans[ind++]=nch;
						++ind1,++ind2;
					}else if(mydata[i][ind1]!=nch){
						ans[ind++]=mydata[i][ind1++];
					}else if(mydata[j][ind2]!=nch){
						ans[ind++]=mydata[j][ind2++];
					}
				}
				while(ind1<2*n){
					ans[ind++]=mydata[i][ind1++];
				}
				while(ind2<2*n){
					ans[ind++]=mydata[j][ind2++];
				}
				flag=1;
				for(int m=0;m<ind;++m)cout<<ans[m];
				cout<<'\n';
				break;
			}
			if(flag)break;
		}
	}
}
