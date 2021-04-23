#include <iostream>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N=120;
int n;
ll dp[N][N];//dp[i][j] stands for max in [i,j]
int main(){
