#include <bits/stdc++.h>
using namespace std;

struct Node{
	int to;
	int t;
	Node(const int& to = 0, const int& t = 0): to(to), t(t){}
};

vector<vector<Node> > graph;
vector<int> val;
int n, m, k;
int ans = INT_MAX;


int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m>> k;
	graph.assign(n+1, vector<Node>());
	val.assign(m, 0);
	while(m--)
		cin>> val[m];
	
	for(int i=0; i<n-1; ++i){
		int a, b, c;
		cin>> a>> b>> c;
		graph[a].push_back(Node(b, c));
		graph[b].push_back(Node(a, c));
		if(c<ans)
			ans = c;
	}
	cout<< ans<< endl;
	return 0;
} 
