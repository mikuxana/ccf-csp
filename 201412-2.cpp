#include <bits/stdc++.h>
using namespace std;
int n;
void z_dfs(int**& m){
	int i = 0, j = 0, k = n*n;
	while(k--){
		cout<< *(*(m+i)+j)<< " ";
		if(n&1){
			if(i==0 and !(j&1) and j<n-1 or i==n-1 and j&1){
				++j;
				continue;
			}
			if(j==0 and i&1 or j==n-1 and !(i&1)){
				++i;
				continue;
			}
		}else{
			if((i==0 or i==n-1) and !(j&1)){
				++j;
				continue;
			}
			if((j==0 or j==n-1) and i&1){
				++i;
				continue;
			}
		}
		if((i+j)&1){
			++i;
			--j;
		}else{
			--i;
			++j;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>> n;
	int** matrix = new int*[n];
	for(int i=0; i<n; ++i){
		matrix[i] = new int[n];
		for(int j=0; j<n; ++j)
			cin>> *(*(matrix+i)+j);
	}
	z_dfs(matrix);
	return 0;
}


/*

8
0 1 5 6 14 15 27 28
2 4 7 13 16 26 29 42
3 8 12 17 25 30 41 43
9 11 18 24 31 40 44 53
10 19 23 32 39 45 52 54
20 22 33 38 46 51 55 60
21 34 37 47 50 56 59 61
35 36 48 49 57 58 62 63

*/
