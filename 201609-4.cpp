#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v,cost;
};

int n, m, ans = 0;
vector<Edge> adj[10005];

bool vis[10005];//当前顶点是否已访问过
int dist[10005],cost[10005];

void dij(){
	fill(dist+2, dist+n+1, INT_MAX);
	for(int i=1; i<=n; ++i){
		int u = -1, tmp = INT_MAX;
		for(int j=1; j<=n; ++j)
			if(!vis[j] and dist[j]<tmp){
				tmp = dist[j];
				u = j;
			}
		vis[u] = 1;
		for(Edge vex: adj[u]){
			int v = vex.v, c = vex.cost;
			if(!vis[v]){
				if(dist[v]>dist[u]+c){
					dist[v] = dist[u]+c;
					cost[v] = c;
				}else if(dist[v]==dist[u]+c)
					cost[v] = min(cost[v], c);
			}
		}
	}
	for(int i=2; i<=n; ++i)
		ans += cost[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	while(m--){
		int a, b, c;
		cin>> a>> b>> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dij();
	cout<< ans<< endl;
	return 0;
}

