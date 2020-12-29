#include <bits/stdc++.h>
using namespace std;

bool flag(int i){
	if(i%7==0)
		return true;
	for(; i>0; i/=10)
		if(i%10==7)
			return true;
	return false;
}


int n(0), i, num=0, ans[4]{0}; // 第i人跳过从的次数 
int main(){
	ios::sync_with_stdio(false);
	cin>> n;
	for(i=1; true; i++){
		if(flag(i)){
			ans[(i-1)%4]++;
			continue;
		}
		if(++num>=n)
			break;
	}
	
	for(i=0; i<4; i++)
		cout<< ans[i]<< endl;
	return 0;
}
