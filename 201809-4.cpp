
#include <bits/stdc++.h>
using namespace std;
int a[305] {};
int n;

bool inq[305] {};
int dist[305] {};

struct edge{
	int b;
	int c;
	edge(int bb, int cc):
		b(bb), c(cc){
		}
};
vector<edge> graph[305];

void spfa(){
	queue<int> que;
	
	for(int i=0; i<=n; ++i){
		que.push(i);
		inq[i] = true;
	}
	while(!que.empty()){
		
		int a = que.front();
		cout<< a<< endl; 
		que.pop();
		inq[a] = false;
		for(auto& e: graph[a]){
			int b = e.b, c = e.c;
			if(dist[b]<dist[a]+c){
				dist[b] = dist[a]+c;
				if(!inq[b]){
					que.push(b);
					inq[b] = true;
				}
			}
		}
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin>> n;
	for(int i=1; i<=n; ++i){
		cin>> a[i];
		graph[i-1].push_back(edge(i, 1));
		if(i==1) {
			graph[0].push_back(edge(2, 2*a[1]));
			graph[2].push_back(edge(0, -2*a[1]-1));
		}else if(i==n){
			graph[n-2].push_back(edge(n, 2*a[n]));
			graph[n].push_back(edge(n-2, -2*a[n]-1));
		}else {
			graph[i-2].push_back(edge(i+1, 3*a[i]));
			graph[i+1].push_back(edge(i-2, -3*a[i]-2));
		}
	}
	spfa();
	
	cout<< dist[1]<< " ";
	for(int i=2; i<=n; ++i)
		cout<< dist[i]-dist[i-1]<< " ";
	cout<< endl;
	return 0;
} 



//
//
////
////struct edge{
////	int b, c;
////	edge(int bb, int cc):
////		b(bb), c(cc){
////		}
////};
////int n, m;
////
////vector<edge> graph[305];
////
////
////
////bool inq[305] {};
////int dist[305];
////void spfa(int s){
////
////	queue<int> Q;
////	fill(dist, dist+300, INT_MIN);
////	Q.push(s);
////	inq[s] = true;
////	dist[s] = 0;
////	while(!Q.empty()){
////		int a = Q.front();
////		cout<< a<< endl;
////		Q.pop();
////		inq[a] = false;
////		for(auto& e: graph[a]){
////			int b = e.b, c = e.c;
////			if(dist[b]<dist[a]+c)
////				dist[b] = dist[a]+c;
////			if(!inq[b]){
////				Q.push(b);
////				inq[b] = true;
////			}
////		}
////	}
////	 
////}
////
////
////void BF(int s){
////	fill(dist, dist+300, INT_MAX);
////	dist[s] = 0;
////	for(int i=0; i<n-1; ++i){
////		for(int a=1; a<=n; ++a)
////		for(auto& e: graph[a]){
////			int b = e.b, c = e.c;
////			if(dist[b]>dist[a]+c)
////				dist[b] = dist[a]+c;
////		}
////	}
////}
////
////
////int main(){
////
////	cin>> n>> m;
////	for(int i=0; i<m; ++i){
////		int a, b, c;
////		cin>> a>> b>> c;
////		graph[a].push_back(edge(b, c));
////	}
////	spfa(1);
//////	BF(1);
////	
////	for(int i=1; i<=n; ++i)
////		cout<< dist[i]<< " ";
////	return 0;
////}
