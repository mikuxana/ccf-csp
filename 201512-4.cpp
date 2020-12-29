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
vector<int>graph[10005],path;//ͼ��ŷ��·��
int N,M;
bool visit[10005][10005];//��ʾ���Ƿ��ѱ�����
bool f(vector<int>&v){//����v�Ķ����Ƿ�Ϊ����
    return v.size()%2==1;
}
void DFS(int v){//������ȱ���
    for(int i=0;i<graph[v].size();++i){//�����õ��ܵ���Ľ��
        int w=graph[v][i];
        if(!visit[v][w]){//�ñ�û�б����ʹ�
            visit[v][w]=visit[w][v]=true;//�ñ��ѱ�����
            DFS(w);//�ݹ����
        }
    }
    path.push_back(v);//����ŷ��·����
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){//��ȡ���ݣ�ע������ͼΪ����ͼ
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=N;++i)//����
        sort(graph[i].begin(),graph[i].end());
    DFS(1);
    int k=count_if(graph+1,graph+N+1,f);//����Ϊ�����Ķ������
    if(path.size()==M+1&&(k==0||(k==2&&f(graph[1]))))
        for(int i=path.size()-1;i>=0;--i)
            printf("%d ",path[i]);
    else
        printf("-1");
    return 0;
}
