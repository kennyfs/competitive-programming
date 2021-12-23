#include <iostream>
#include <stack>
#include <sstream>
#define toyz stoi
using namespace std;
const int N=15,M=1.6e3+10,ANS=5e3;
int n,m,intot,outtot=0;
struct shi{
	int type;//0:scalar,1:not,2:and,3:or
	int num;
	shi *lc=NULL,*rc=NULL;
}in[M],out[ANS];
ostream& operator<<(ostream& s,shi &a){
	switch(a.type){
		case 0:
			s<<a.num<<' ';
			outtot++;
			break;
		case 1:
			s<<"not ( "<<*a.lc<<") ";
			outtot+=3;
			break;
		case 2:
            s<<"not ( ( not ( "<<*a.lc<<") ) or ( not ( "<<*a.rc<<") ) ) ";
			outtot+=14;
		    break;
		case 3:
			s<<"( "<<*a.lc<<") or ( "<<*a.rc<<") ";
			outtot+=5;
		    break;
	}
	return s;
}
int tot=0,res;
int input(){
    tot++;
    string op;
    cin>>op;
    if(op=="not")return 1;
    else if(op=="and")return 2;
    else if(op=="or")return 3;
    else if(op=="(")return 4;
    else if(op==")")return 5;
    else{res=toyz(op);return 0;}
}
stack<shi*> stk;
shi* recur(){//input doesn't start with (, but should eat )
    int t=input();
    shi* now;
    if(t==0){
        input();//)
        now=&in[intot++];
        now->type=0;
        now->num=res;
    }else if(t==1){
        //input"not ( ... ) )"
        input();//(
        shi* tmp=recur();
        input();//)
        //tmp=now->lc
        if(tmp->type==1){return tmp->lc;}
        now=&in[intot++];
        now->type=1;
        now->lc=tmp;
    }else if(t==4){
        //input "(...) and/or (...))"
        shi *rc,*lc;
        lc=recur();
        t=input();
        input();//(
        rc=recur();
        input();//)
        now=&in[intot++];
        now->type=t;
        now->rc=rc;
        now->lc=lc;
    }
    return now;
}
int main(){
	cin>>n>>m;
	shi *root;
	int t;
	t=input();
	if(t==0){
        root=&in[intot++];
        root->type=0;
        root->num=res;
	}
	else if(t==1){
        input();
        root=&in[intot++];
        shi* tmp=recur();
        if(tmp->type==1){root=tmp->lc;goto end;}
        root->type=1;
        root->lc=tmp;
	}else if(t==4){
        root=&in[intot++];
        shi *rc,*lc;
        input();//(
        lc=recur();
        root->type=input();
        input();//(
        rc=recur();
        input();//)
        root->rc=rc;
        root->lc=lc;
	}
	end:
    stringstream test;
    test<<*root;
    cout<<outtot<<'\n';
    cout<<test.str()<<'\n';
}
