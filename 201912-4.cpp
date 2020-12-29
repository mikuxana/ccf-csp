#include <bits/stdc++.h>
using namespace std;

int n, m, ux, vx, t, k;

// 操作优先级 接收-产生-查询
map<int, unordered_map<int, array<vector<int>, 2> > > ans; // 保存操作 时刻-顶点-（0接受链,生成的块）
vector<vector<int> > graph(502); // 图的邻接表
vector<vector<int> > lis(502, {0}); // current vertex's list

bool canAccept(vector<int>& Old, vector<int>& New){
	return Old.size()==New.size()? Old.back()>New.back(): Old.size()<New.size();
}

// 顶点v辐射
void cast(int v, int time){ // v辐射时刻time的状态
	for(int u: graph[v]){
		auto& chain = ans[time][u][0];
		if((chain.empty()&&canAccept(lis[u], lis[v]))||(!chain.empty()&&canAccept(chain, lis[v])))
			chain = lis[v];
	}
}


void query(int a, int b){ // 时刻a顶点b的主链
	for(auto& e: ans){
		int currTime = e.first;
		if(currTime>b)
			break;
		for(auto& vertex: e.second){
			int v = vertex.first; // 顶点 v
			auto& chain = vertex.second[0], &block = vertex.second[1];
			bool flag = canAccept(lis[v], chain)|| !block.empty()? true: false;   //v是否辐射
			if(canAccept(lis[v], chain))
				lis[v] = chain;
			for(int& u: block)
				lis[v].push_back(u);
			if(flag)
				cast(v, currTime+t);
			}
	}
	ans.erase(ans.begin(), ans.upper_bound(b));

	cout<< lis[a].size();
	for(int& e: lis[a])
		cout<< " "<< e;
	cout<< endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	while(m--){
		cin>> ux>> vx;
		graph[ux].push_back(vx);
		graph[vx].push_back(ux);
	}

	cin>> t>> k;
	while(k--){
		int a, b;

		if(cin.get()=='\n' || cin.eof())
			query(a, b);
		else{
			int c;
			cin>> c;
			ans[b][a][1].push_back(c);
		}

	}
	return 0;
}








/*  int

 
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
1 27
1 1 1
2 1 2
3 1 3
4 1 4
5 1 5
1 1
2 1
3 1
4 1
5 1
1 2
2 2
3 2
4 2
5 2
1 10 10
2 11 9
1 11
2 11
3 11
4 11
5 11
1 12
2 12
3 12
4 12
5 12


/*	out
2 0 1
2 0 2
2 0 3
2 0 4
2 0 5
2 0 1
2 0 1
2 0 1
2 0 1
2 0 1
3 0 1 10
4 0 1 10 9
3 0 1 10
3 0 1 10
3 0 1 10
4 0 1 10 9
4 0 1 10 9
4 0 1 10 9
4 0 1 10 9
4 0 1 10 9

// in

15 13
1 2
2 3
3 4
4 5
1 6
6 7
7 8
8 9
1 10
10 11
11 12
12 13
14 15
6 28
1 1 1
1 2 2
1 6
2 7
13 7
9 7
5 7
3 14
8 14
5 14
11 14
9 25
5 25
13 25
9 28 3
5 29 4
13 29 5
1 53
2 59 6
2 59
1 1000
3 1000
8 1000
9 1000
10 1000
13 1000
14 1000
15 1000



// out

3 0 1 2
2 0 1
1 0
1 0
1 0
3 0 1 2
1 0
1 0
3 0 1 2
2 0 1
2 0 1
2 0 1
4 0 1 2 3
5 0 1 2 3 6
5 0 1 2 3 6
5 0 1 2 3 6
5 0 1 2 3 6
5 0 1 2 3 6
5 0 1 2 3 6
5 0 1 2 3 6
1 0
1 0



#include <bits/stdc++.h>
using namespace std;

int n, m, t, k;
map<int, unordered_map<int, array<vector<int>, 2>>> rs;

vector<vector<int>> graph;
vector<vector<int>> curlist;

bool canAccept(vector<int>& Old, vector<int>& New){
	return Old.size()==New.size()? Old.back()>New.back(): Old.size()<New.size();
}

void cast(int v, int time) { 
    for (int i : graph[v]) {
        auto& chain = rs[time][i][1];
        if (canAccept(chain, curlist[v]))
            chain = curlist[v];
    }
}
void query(int a, int b){
	for(auto& it: rs){
		int curTime = it.first;
		if(curTime>b) 
			break;
		for(auto& ver: it.second){
			int v = ver.first;
			auto &accept = ver.second[1], &inc = ver.second[0];
			bool flag = canAccept(curlist[v], accept) or !inc.empty();
			if(canAccept(curlist[v], accept))
				curlist[v] = accept;
			for(auto& e: inc)
				curlist[v].push_back(e);
			if(flag)
				cast(v, curTime+t);
		}
	}
	rs.erase(rs.begin(), rs.upper_bound(b));
	cout<< curlist[a].size();
	for(auto& e: curlist[a])
		cout<< " "<< e;
	cout<< endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	graph.assign(n+1, {});
	curlist.assign(n+1, {0});
	while(m--){
		int u, v;
		cin>> u>> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin>> t>> k;
	cin.get();
	while(k--){
		int a, b, c = -1;
		string op;
		getline(cin, op);
		sscanf(op.c_str(), "%d %d %d", &a, &b, &c);
		if(c==-1)
			query(a, b);
		else rs[b][a][0].push_back(c);
	}
	return 0;
}
