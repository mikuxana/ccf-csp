//#include <bits/stdc++.h>
//using namespace std;
//int n, m;
//set<int> adj[10005];
//bool vis[10005][10005];
//
//void dfs(int a){
//	cout<< a<< " ";
//	for(int b: adj[a])
//		if(!vis[a][b]){
//			vis[a][b] = vis[b][a] = 1;
//			dfs(b);
//		}
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin>> n>> m;
//	while(m--){
//		int a, b;
//		cin>> a>> b;
//		adj[a].insert(b);
//		adj[b].insert(a);
//	}
//	int flag = 0;
//	for(int i=1; i<=n; ++i)
//		if(adj[i].size()%2!=0)
//			flag++; 
//	if(flag==0 or flag==2)
//		dfs(1);
//	else cout<< -1;
//	return 0;
//}




#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10005],path;//图、欧拉路径
int N,M;
bool visit[10005][10005];//表示边是否已被访问
bool f(vector<int>&v){//顶点v的度数是否为奇数
    return v.size()%2==1;
}
void DFS(int v){//深度优先遍历
    for(int i=0;i<graph[v].size();++i){//遍历该点能到达的结点
        int w=graph[v][i];
        if(!visit[v][w]){//该边没有被访问过
            visit[v][w]=visit[w][v]=true;//该边已被访问
            DFS(w);//递归遍历
        }
    }
    path.push_back(v);//加入欧拉路径中
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){//读取数据，注意所给图为无向图
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=N;++i)//排序
        sort(graph[i].begin(),graph[i].end());
    DFS(1);
    int k=count_if(graph+1,graph+N+1,f);//度数为奇数的顶点个数
    if(path.size()==M+1&&(k==0||(k==2&&f(graph[1]))))
        for(int i=path.size()-1;i>=0;--i)
            printf("%d ",path[i]);
    else
        printf("-1");
    return 0;
}
