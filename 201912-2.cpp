#include <bits/stdc++.h>
using namespace std;

int n(0), ans[5]{0};  // 得分i的垃圾点的个数为ans[i] 

typedef pair<int, int> anix;

set<anix> can; // 垃圾点坐标 i，can[i]; 

bool judge(anix& r){
	int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
	for(int i=0; i<4; i++)
		if(can.find(anix(r.first+dx[i], r.second+dy[i]))==can.end())
			return false;
	return true;		
}

void dscore(anix& r){
	int score=0;
	int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1};
	for(int i=0; i<4; ++i)
		if(can.find(anix(r.first+dx[i], r.second+dy[i]))!=can.end())
			score++;
	
	ans[score]++;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n;
	while(n--){
		int x, y;
		cin>> x>> y;
		can.insert(anix(x, y));
	}
	
	for(auto e: can)
		if(judge(e))
			dscore(e);
			
	for(int i=0; i<5; i++)
		cout<< ans[i]<< endl; 
	return 0;
} 
