#include <bits/stdc++.h>
using namespace std;

struct Vex{
	int r, c, t;
};

int n, m, t;
bool inque[105][105][305];
queue<Vex> que;
int f[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int deal(){
	que.push({1, 1, 0});
	inque[1][1][0] = true;
	while(!que.empty()){
		Vex vex = que.front();
		if(vex.r==n and vex.c==m) return vex.t;
		que.pop();
		for(int i=0; i<4; ++i){
			int r = vex.r+f[i][0], c = vex.c+f[i][1], t = vex.t+1;
			if(r>=1 and r<=n and c>=1 and c<=m and !inque[r][c][t]){
				que.push({r, c, t});
				inque[r][c][t] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m>> t;
	while(t--){
		int r, c, a, b;
		cin>> r>> c>> a>> b;
		for(int i=a; i<=b; ++i)
			inque[r][c][i] = true;
	}
	cout<< deal();
}
