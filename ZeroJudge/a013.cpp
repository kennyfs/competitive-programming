#include<iostream>
#include <string>
using namespace std;
char r2[7]={'M','D','C','L','X','V','I'};
int s2[7]={1000,500,100,50,10,5,1};
string r[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
int  s[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string intToRoman(int a){
	if(a==0) return "ZERO";
	string roman="";
	for(int i=0;i<13;i++){
		while(a>=s[i]){
			a-=s[i];
			roman+=r[i];
		}
	}
	return roman;
}
int romanToInt(string a){
	int b,c,point=0;
	for(int i=0;i<a.size();i++){
		b=0,c=0;
		for(int j=0;j<7;j++){
			if(a[i]==r2[j]) b=s2[j];
			if(i+1<a.size()){
			if(a[i+1]==r2[j]) c=s2[j];
			}
		}
		if(b<c){
			point+=c-b;
			i++;
		}else{
			point+=b;
		}
	}
	return point;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int c,d;
	string a,b;
	while(cin>>a>>b){
		c=romanToInt(a);
		d=romanToInt(b);
		c-=d;
		if(c<0) c*=-1;
		b=intToRoman(c);
		cout<<b<<'\n';
	}
	return 0; 
}
//實作地獄
