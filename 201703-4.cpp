#include <bits/stdc++.h>   // 20·Ö 
using namespace std;
struct edge{
	int a, b; 
	int t;
	edge(const int& u, const int& v, const int& w): a(u), b(v), t(w){}
	bool operator <( const edge& r) const{
		return t > r.t;
	}
}; 

priority_queue<edge> edges;
int n, m, ans = 0;

int father[100003];

int find(int x){
	if(x==father[x])
		return x;
		
	int t = find(father[x]);
	father[x] = t;
	return t;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	iota(father, father+n+1, 0);
	while(m--){
		int a, b, t;
		cin>> a>> b>> t;
		edges.push(edge(a, b, t));
	}
	
	while(find(1)!=find(n)){
		edge edg = edges.top();
		edges.pop();
		int fa = find(edg.a), fb = find(edg.b);
		if(fa!=fb){
			father[fb] = fa;
			ans = edg.t;
		}
		
	}
	cout<< ans<< endl;
	return 0;
}
