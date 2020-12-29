#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> keybox;
struct Use{
	int key;
	int start, end;
	Use(int& k, int& s, int& t): key(k),start(s), end(s+t){}
	bool operator< (Use& r){
		if(end==r.end)
			return key<r.key;
		return end<r.end;
	}
};

vector<Use> vec;
void deal(){
	for(int i=0; i<vec.size(); ++i){
		int j;
		for(int j=i; j<vec.size(); ++j)
			if(vec[j].start<vec[i].end){
				for(int k=0; k<keybox.size(); ++k)
					if(keybox[k]==vec[j].key){
						keybox[k] = -1;
						break;
					}
			}
		for(j = 0; j<keybox.size(); ++j)
			if(keybox[j]==-1)
				break;
		keybox[j] = vec[i].key;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin>> N>> K;
	for(int i=0; i<N; ++i)
		keybox.push_back(i+1);
	while(K--){
		int k, s, t;
		cin>> k>> s>> t;
		vec.push_back(Use(k, s, t));
	}
	sort(vec.begin(), vec.end());
	deal();
	for(int& e: keybox)
		cout<< e<< " ";
	cout<< endl;
	return 0;
}



/*



5 2
4 3 3
2 2 7




5 7
1 1 14
3 3 12
1 15 12
2 7 20
3 18 12
4 21 19
5 30 9










*/
