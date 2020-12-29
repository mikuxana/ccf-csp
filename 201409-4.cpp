//#include <bits/stdc++.h>
//using namespace std;
//
//struct Point{
//	int x, y;
//	int cost;
//	Point(int& xx, int& yy, int cc): x(xx), y(yy), cost(cc) {}
//};
//
//struct Ep{
//	int x, y;
//	int val;
//	int cost = INT_MAX;
//	Ep(int& xx, int& yy, int& vv): x(xx), y(yy), val(vv){
//	}
//	void deal(int len){
//		if(cost>len*val)
//			cost = len*val;
//	}
//};
//
//vector<Point> sp;
//vector<Ep> ep;
//unordered_map<int, vector<int>> h;
//int n, m, k, d, ans = 0;
//
//
////bool inque[1005][1005];
//
//int ret[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
//
//void bfs(Point& start, vector<vector<bool>> inque){
//	queue<Point> que;
//	que.push(start);
//	inque[start.x][start.y] = 1;
//	int c = 0;
//	while(!que.empty()){
//		Point& top = que.front();
//		int ind = 100000*top.x+top.y;
//		if(!h[ind].empty()) {
//			for(int& i: h[ind]){
//				ep[i].deal(top.cost);
//				c++;
//			}
//			if(c==ep.size()) return;
//		}
//		que.pop();
//		for(int i=0; i<4; ++i){
//			int x = top.x+ret[i][0], y = top.y+ret[i][1];
//			int cost = top.cost+1;
//			if(x>0 and x<=n and y>0 and y<=n and !inque[x][y]){
//				que.push(Point(x, y, cost));
//				inque[x][y] = 1;
//			}
//		}
//	}
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin>> n>> m>> k>> d;
//	vector<vector<bool>> inque(n+1, vector<bool>(n+1));
//	int x, y, i = 0;
//	while(m--){
//		cin>> x>> y;
//		sp.push_back(Point(x, y, 0));
//	}
//	while(k--){
//		int t;
//		cin>> x>> y>> t;
//		ep.push_back(Ep(x, y, t));
//		h[x*100000+y].push_back(i++);
//	}
//	while(d--){
//		cin>> x>> y;
//		inque[x][y] = 1;
//	}
//	
//	for(auto& start: sp)
//		bfs(start, inque);
//		
//	for(auto& end: ep)
//		ans += end.cost;
//	cout<< ans<< endl;
//	return 0;
//}



#include<bits/stdc++.h>
using namespace std;

struct anix{
	int x, y;
	int cost;
	anix(int& xx, int& yy, int c): x(xx), y(yy), cost(c){}
};

int n, m, k, d, ans = 0;
unordered_map<int, unordered_map<int, bool>> rs;
unordered_map<int, unordered_map<int, int>> ts;

int r[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<anix> sp;

int bfs(int& x, int& y, vector<vector<bool>> inque){
	if(ts[x][y]) return ts[x][y];
	queue<anix> que;
	que.push(anix(x, y, 0));
	inque[x][y] = 1;
	while(!que.empty()){
		anix& top = que.front();
		if(rs[top.x][top.y]) {
			ts[x][y] = top.cost;
			return ts[x][y];
		};
		que.pop();
		for(int i=0; i<4; ++i){
			int x = top.x+r[i][0], y = top.y+r[i][1];
			int c = top.cost+1;
			if(x>0 and x<=n and y>0 and y<=n and !inque[x][y]){
				que.push(anix(x, y, c));
				inque[x][y] = 1;
			}
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m>> k>> d;
	vector<vector<bool>> inque(n+1, vector<bool>(n+1));
	int a, b, c;
	while(m--){
		cin>> a>> b;
		rs[a][b] = 1;
	}
	while(k--){
		cin>> a>> b>> c;
		sp.push_back(anix(a, b, c));
	}
	while(d--){
		cin>> a>> b;
		inque[a][b] = 1;
	}
	for(auto& an: sp)
		ans += an.cost*bfs(an.x, an.y, inque);
	cout<< ans<< endl;
	return 0;
}
