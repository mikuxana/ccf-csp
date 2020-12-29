#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1005];
bool know[1005][1005];

void dfs(int& a, int& i, vector<bool>& vis){
	know[i][a] = know[a][i] = 1;
	vis[a] = true;
	for(int& b: adj[a])
		if(!vis[b]) dfs(b, i, vis);
}

int main(){
	ios::sync_with_stdio(false);
	cin>> N>> M;
	while(M--){
		int a, b;
		cin>> a>> b;
		adj[a].push_back(b);
	}
	
	for(int i=1; i<=N; ++i){
		vector<bool> vis(N+1, 0);
		dfs(i, i, vis);
	}
	
	int res = 0;
	for(int i=1; i<=N; ++i){
		int c = 0;
		for(int j=1; j<=N; ++j)
			c += know[i][j];
		if(c==N) res++;
	}
	cout<< res<< endl;
	return 0;
}
