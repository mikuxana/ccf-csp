#include <bits/stdc++.h>
using namespace std;

int n, k, s, l;
int m, len;

vector<string> ans;			// 硬盘内容 
vector<vector<int>> tans;		// 条带编号分布 

void init(){				// 初始化 
	int r = 1, val = 0;
	for(int j=0; j<k; ++j){
		r = (r-1)%n+1;
		int c = 0, flag=true;
		for(int i=n-r; c<n; ++c, ++i){
			if(flag) {
				tans[i][j] = -1;
				flag = false;
			}
			else tans[i%n][j] = val++;
		}
		r++;
	}
}

void query(int& b){
	int rin = b/s, pos_i = -1, pos_j = -1;
	if(rin>n*k-k-1) {
		cout<< "-"<< endl;
		return;
	}
	
	for(int i=0; i<n; ++i)
		for(int j = 0; j<k; ++j)
			if(rin==tans[i][j]){
				pos_i = i;
				pos_j = j;
				break;
			}
	if(not ans[pos_i].empty())
		cout<< ans[pos_i].substr(pos_j*8*s+b%s*8, 8)<< endl;
	else{
		int sum = 0, flag = true;
		for(int i=0; i<n; ++i)
			if(i!=pos_i){
				if(ans[i].empty()){
					cout<< "-"<< endl;
					return;
				}
				string r = ans[i].substr(pos_j*8*s+b%s*8, 8);
				if(flag) {
					sscanf(r.c_str(), "%08X", &sum);
					flag = false;
				}
				else {
					int a;
					sscanf(r.c_str(), "%08X", &a);
					sum ^= a;
				}
			}
		printf("%8X\n", sum);
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> s>> l;
	ans.assign(n, "");
	while(l--){
		int i;
		cin>> i;
		cin>> ans[i];
		len = ans[i].size();
	}
	k = len/(s*8);
	
	tans.assign(n, vector<int>(k, 0));
	init();
	
	cin>> m;
	while(m--){
		int bid;
		cin>> bid;
		query(bid);
	}
	return 0;
} 



/*
//case 1:

2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
2
0
1

// case 2:

3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
2
2
5



*/


















