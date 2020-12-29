#include <bits/stdc++.h>
using namespace std;

bool matrix[19][10];
bool sub[4][4];
int row[4];
int n, i, j, k=4;

void print(){
	for(i=4; i<19; ++i){
		for(j=0; j<10; ++j)
			cout<< matrix[i][j]<< " ";
		cout<< endl;
	}
}

void deal(){
	for(i=0; i<4; ++i)
		for(j=0; j<4; ++j)
			matrix[i][j+n-k] = sub[i][j];
	int l = 19;
	for(i=0; i<4; ++i)
		if(row[i]!=-1){
			int x = row[i]+1, y = i+n-k;
			while(x<19 and matrix[x][y]!=1)
				x++;
			l = min(l, x-row[i]-1);
		}
		
	for(i=0; i<4; ++i)
		for(j=0; j<4; ++j)
			if(sub[i][j])
				matrix[i+l][j+n-k] = sub[i][j];
	print();
}

int main(){
	ios::sync_with_stdio(0);
	fill(row, row+4, -1);
	for(i=4; i<19; ++i)
		for(j=0; j<10; ++j)
			cin>> matrix[i][j];
			
	for(i=0; i<4; ++i)
		for(j=0; j<4; ++j){
			cin>> sub[i][j];
			if(sub[i][j]){
				k = min(k, j);
				row[j] = max(row[j], i);
			}
		}
	cin>> n;
	deal();
	return 0;
} 
