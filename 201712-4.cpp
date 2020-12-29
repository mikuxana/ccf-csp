#include <bits/stdc++.h> 
using namespace std;

typedef long long LL;

const LL N = 505;
const LL la  = INT_MAX;
LL n, m;
vector<vector<LL> > graph;

void dij(){
	LL dis[n+1]{0}, vis[n+1]{false}, xl[n+1]{0}, i ,j;
	for(i=2; i<=n; ++i)			// init...
		if(graph[1][i]<0){
			dis[i] = graph[1][i]*graph[1][i];
			xl[i] = graph[1][i];
		}
		else if(graph[1][i]<la)
			dis[i] = graph[1][i];
		else dis[i] = la;
		
	dis[1] = 0, vis[1] = 1;
	
	for(i=1; i<n; ++i){
		LL u=-1, tmp = la;
		for(j=1; j<=n; ++j)
			if(!vis[j]&&tmp>dis[j]){
				tmp = dis[j];
				u = j;
			}
		vis[u] = 1;
		for(j=1; j<=n; ++j)
			if(!vis[j]&&graph[u][j]<la){
				if(graph[u][j]>0&&dis[j]>dis[u]+graph[u][j]){ 
					dis[j] = dis[u]+graph[u][j];
					xl[j] = 0;
				}
				if(graph[u][j]<0){
					if(xl[u]){ 
						LL len = xl[u]+graph[u][j];
						if(dis[j]>len*len){
							dis[j] = len*len;
							xl[j] = xl[u]+graph[u][j];
						}
					}
					else if(dis[j]>dis[u]+graph[u][j]*graph[u][j]){
						dis[j] = dis[u]+graph[u][j]*graph[u][j]; 
						xl[j] = 0;
					}
				}
			}
			
	}
	cout<< dis[n]<< endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	graph.assign(n+1, vector<LL>(n+1, la));
	while(m--){
		LL id, a, b, c;
		cin>> id>> a>> b>> c;
		if(id)
			c *= -1; // 负权为小道 
		graph[a][b] = graph[b][a] = c;
	}
	
	dij();

	return 0;
}
