#include <iostream>
using namespace std;int main(){ios_base::sync_with_stdio(0);cin.tie(0);int i,j;int matrix[101][101];while(cin>>i>>j){for(int x=0;x<i;x++){for(int y=0;y<j;y++){cin>>matrix[x][y];}}for(int x=0;x<j;x++){for(int y=0;y<i;y++){cout<<matrix[y][x]<<' ';}cout<<'\n';}}return 0;}
//水題
