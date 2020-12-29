#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;

vector<int> adj[10005];
bool vis[10005][10005];


void dfs(int& a, int& i, vector<bool>& vist){
	vist[a] = true;
	vis[i][a] = 1;
	for(int& b: adj[a])
		if(!vist[b]){
			vis[a][b] = 1;
			dfs(b, i, vist);
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	while(m--){
		int a, b;
		cin>> a>> b;
		adj[a].push_back(b);
	}
	for(int i=1; i<=n; ++i){
		vector<bool> vist(n+1, 0);
		dfs(i, i, vist);
	}
	
	for(int i=1; i<n; i++)
		for(int j=i+1; j<=n; ++j){
			if(vis[i][j] and vis[j][i])
				ans++;
		}
	cout<< ans<< endl;
	return 0;
} 
