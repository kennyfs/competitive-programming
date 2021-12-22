#include <iostream>
using namespace std;
const int N=110,Q=1010;
int data[2*N][N];
int n,m,q;

void xrv(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			data[i+n][j]=data[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			data[i][j]=data[i+n][m-j+1];
		}
	}
}
void yrv(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			data[i+n][j]=data[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			data[i][j]=data[n+n-i+1][j];
		}
	}
}
void R(int k){
	int je=m-k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			data[i][je-j+1]+=data[i][je+j];
		}
	}
	m-=k;
}
void L(int k){
	xrv();
	R(k);
	xrv();
}
void D(int k){
	int je=n-k;
	for(int i=1;i<=k;++i){
		for(int j=1;j<=m;++j){
			data[je-i+1][j]+=data[je+i][j];
		}
	}
	n-=k;
}
void U(int k){
	yrv();
	D(k);
	yrv();
}
void LU(int k){
	for(int i=1;i<=k;++i){
		for(int x=1,y;x<=min(n,m);++x){
			y=i-x+1;
			if(y<1)break;
			if(y>m)continue;
			data[x+k+1-i][y+k+1-i]+=data[x][y];
			data[x][y]=0;
		}
	}
}
void LD(int k){
	yrv();
	LU(k);
	yrv();
}
void RD(int k){
	xrv();
	yrv();
	LU(k);
	xrv();
	yrv();
}
void RU(int k){
	xrv();
	LU(k);
	xrv();
}
void print(){
	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<data[i][j]<<' ';
		}
		cout<<'\n';
	}
}
signed main(){
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>data[i][j];
	string op;int num;
	while(q--){
		cin>>op>>num;
		if(op=="L"){
			L(num);
		}else if(op=="R"){
			R(num);
		}else if(op=="D"){
			D(num);
		}else if(op=="U"){
			U(num);
		}else if(op=="LD"){
			LD(num);
		}else if(op=="LU"){
			LU(num);
		}else if(op=="RD"){
			RD(num);
		}else if(op=="RU"){
			RU(num);
		}else return 87;
	}
	print();
}
