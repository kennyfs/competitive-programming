/*           OJDL TestCase Generater             */
/*  Made by FHVirus with patience for cin/cout   */
/*
How this works:
1.  Generate a file (testcase#.in)
2.  Read that file as input and solve,
    output to another file(testcase#.out)

How to use it:
0.  Put this program into a folder where
    you want to store the testcases.
1.  Input number of subtasks
2.  For each subtask, input the number of
    desired testcase for the subtask, then
    the arguments for generate().
3.  Done!
*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "jngen.h"
using namespace std;
// For generate(), you can add additional arguments
// for generating a testcase.
// But for solve(), just write a normal solution
// like that in main() for most of the time.
void generate(ofstream &cout,int op=3){
	int n,sz;
	if(op==4)sz=1e2;
	else sz=(int)2.5e4;
	n=rnd.next((int)(sz*0.7),sz);
	if(op!=2){
		auto g=Graph::random(n,n-1).connected();
		auto gg=g.g().shuffle();
		auto tree=gg.edges();
		int a[n+1],k;
		if(op==3){
			k=rnd.next(100,200);
			for(int i=1;i<=n;++i)a[i]=k;
			int add=rnd.next(1,n);
			int more=rnd.next(500,(1000-a[add]));
			a[add]=k+more;
			int ind=n;
			while(more){
				ind=rnd.next(1,n);
				if(a[ind]!=k)continue;
				if(ind==add)continue;
				int minus=rnd.next(1,min(5,a[ind]-10));
				minus=min(minus,more);
				a[ind]-=minus;
				more-=minus;
			}
		}else if(op!=4){//op 1,5
			k=0;
			for(int i=1;i<=n;++i)a[i]=rnd.next(20,1000),k+=a[i];
			int more=k%n;
			k/=n;
			int ind=n;
			while(more){
				int minus=rnd.next(5,min(5,a[ind]-10));
				minus=min(minus,more);
				a[ind--]-=minus;
				more-=minus;
			}
		}
		if(op==1){
			for(int i=0;i<rnd.next(5,20);++i){
				int ind=rnd.next(1,n);
				a[ind]+=rnd.next(1,max(2,900-a[ind]));
			}
		}
		cout<<n<<' '<<k<<'\n';
		for(int i=1;i<=n;++i)cout<<a[i]<<' ';
		cout<<a[n]<<'\n';
		for(auto [i,j]:tree)cout<<i+1<<' '<<j+1<<' '<<rnd.next(1,(int)1e3)<<'\n';
	}else{//op==2
		int link[n+1],link2[n];
		for(int i=1;i<=n;++i)link[i]=link2[i]=i;
		for(int i=0;i<3*n;++i){
			swap(link[rnd.next(1,n)],link[rnd.next(1,n)]);
			swap(link2[rnd.next(1,n-1)],link2[rnd.next(1,n-1)]);
		}
		int a[n+1],k;
		k=0;
		for(int i=1;i<n;++i)a[i]=rnd.next(20,1000),k+=a[i];
		int more=k%n;
		k/=n;
		int ind=n;
		while(more){
			int minus=rnd.next(5,min(5,a[ind]-10));
			minus=min(minus,more);
			a[ind--]-=minus;
			more-=minus;
		}
		cout<<n<<' '<<k<<'\n';
		for(int i=1;i<n;++i)cout<<a[i]<<' ';
		cout<<a[n]<<'\n';
		for(int i=1;i<n;++i){
			cout<<link[link2[i]]<<' '<<link[link2[i]+1]<<' '<<rnd.next(10,(int)1e3)<<'\n';
		}
	}
}
int main(){
    int st,ed,op;
    cin>>op;
    cin>>st>>ed;
	for(int i=st;i<=ed;++i){
		string in = to_string(i) + ".in";
		{
			cout<<i<<':';
			ofstream tsezi;
			tsezi.open(in);
			generate(tsezi,op);
			tsezi.close();
			cout<<endl;
		}
    }
    return 0;
}
