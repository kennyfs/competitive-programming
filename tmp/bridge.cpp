#include "bits/stdc++.h"
#define pii pair<int,int>
using namespace std;
int connum,concol,condi;//NESW
int curnum,curcol,curdi;
int numtonum[256],coltonum[256];
char numtocol[5],numtotext[15],ditotext[5];
int firstcon[6];
int num_double,doubledi;
int point[2];
bool nopai[5][5];//nopai[i][j]==1 <=> i don't have j (j is a color)
bool paipresent[5][15];
istream& operator>>(istream& in, pii &a){
	char c,num;
	in>>c>>num;
	a.first=coltonum[c];
	a.second=numtonum[num];
	return in;
}
void reset(){
	connum=concol=condi=curnum=curcol=curdi=num_double=doubledi=0;
	for(auto &a:firstcon)a=0;
	for(auto &a:point)a=0;
	memset(nopai,0,sizeof(nopai));
	memset(paipresent,0,sizeof(paipresent));
}
int main(){
	for(int i=1;i<=9;++i){
		numtonum[i+'0']=i;
		numtotext[i]=i+'0';
	}
	numtonum['A']=14;
	numtonum['K']=13;
	numtonum['Q']=12;
	numtonum['J']=11;
	numtonum['T']=10;
	coltonum['C']=1;
	coltonum['D']=2;
	coltonum['H']=3;
	coltonum['S']=4;
	numtocol[1]='C';
	numtocol[2]='D';
	numtocol[3]='H';
	numtocol[4]='S';
	numtotext[14]='A';
	numtotext[13]='K';
	numtotext[12]='Q';
	numtotext[11]='J';
	numtotext[10]='T';
	ditotext[1]='N';
	ditotext[2]='E';
	ditotext[3]='S';
	ditotext[4]='W';
	int t;
	cin>>t;
	int tmpnum,tmpcol,tmpdi;
	while(t--){
		reset();
		char first;
		string con;
		cin>>first;
		if(first=='N')tmpdi=1;
		else if(first=='E')tmpdi=2;
		else if(first=='S')tmpdi=3;
		else if(first=='W')tmpdi=4;
		bool b=0;
		int passinrow=-1;
		while(1){
			cin>>con;
			if(con[0]=='X'){
				passinrow=0;
				if(con[1]=='X'){
					if(num_double!=1||(doubledi+tmpdi)%2==0){cout<<"error\n";b=1;break;}
					num_double=2;
					doubledi=tmpdi;
				}else{	
					if(num_double!=0||(tmpdi+curdi)%2==0){cout<<"error\n";b=1;break;}
					num_double=1;
					doubledi=tmpdi;
				}
			}else if(con[0]=='P'){
				passinrow++;
				if(passinrow==3){
					if(curnum==0)cout<<"ALL PASS\n",b=1;
					break;
				}
			}else{
				passinrow=0;
				tmpnum=numtonum[con[0]];
				if(con[1]=='C'){
					tmpcol=1;
				}else if(con[1]=='D'){
					tmpcol=2;
				}else if(con[1]=='H'){
					tmpcol=3;
				}else if(con[1]=='S'){
					tmpcol=4;
				}else if(con[1]=='N'){
					tmpcol=5;
				}
				if(tmpnum*6+tmpcol<=curnum*6+curnum){cout<<"error\n";b=1;break;}
				curnum=tmpnum;curcol=tmpcol;curdi=tmpdi;
				if(firstcon[curcol]==0)firstcon[curcol]=tmpdi;
			}
			tmpdi++;if(tmpdi==5)tmpdi=1;
		}
		if(b)continue;
		connum=curnum;concol=curcol;
		condi=firstcon[concol];
		tmpdi=condi+1;
		if(tmpdi==5)tmpdi=1;
		pii mx,cur;
		int mxdi;
		for(int row=1;row<=13;row++){
			cin>>mx;
			if(paipresent[mx.first][mx.second]){cout<<"error\n";b=1;break;}
			paipresent[mx.first][mx.second]=1;
			mxdi=tmpdi;
			tmpdi++;if(tmpdi==5)tmpdi=1;
			for(int round=2;round<=4;++round){
				cin>>cur;
				if(paipresent[cur.first][cur.second]){cout<<"error\n";b=1;break;}
				paipresent[cur.first][cur.second]=1;
				if(nopai[tmpdi][cur.first]){cout<<"error\n";b=1;break;}
				if(concol!=5&&cur.first!=mx.first){
					nopai[tmpdi][mx.first]=1;
				}
				if(cur.second>mx.second){
					if(concol==5||cur.first==mx.first){
						mx=cur;
						mxdi=tmpdi;
					}
				}
				tmpdi++;if(tmpdi==5)tmpdi=1;
			}
			if(b)break;
			tmpdi=mxdi;
			point[mxdi%2]++;
		}
		if(b)continue;
		cout<<connum<<numtocol[concol];
		for(int i=0;i<num_double;++i)cout<<'X';
		cout<<ditotext[condi];
		int target=connum+6,result;
		if(condi%2==1)result=point[1]-target;
		else result=point[0]-target;
		if(result==0)cout<<'=';
		else if(result>0)cout<<'+'<<result;
		else cout<<'-'<<-result;
		cout<<'\n';
	}
}