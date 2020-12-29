#include <bits/stdc++.h>
using namespace std;
string res = "";
unordered_map<string, string> h;

void deal(){
	for(auto& p: h)
		res = regex_replace(res, regex("\\{\\{ "+p.first+" \\}\\}"), p.second);
	res = regex_replace(res, regex("\\{\\{.*\\}\\}"), "");
}

int main(){
	ios::sync_with_stdio(false);
	int m, n;
	cin>> m>> n;
	cin.get();
	string line;
	while(m--){
		getline(cin, line);
		res += line+"\n";
	}
	string key, val;
	while(n--){
		cin>> key;
		cin.get();
		getline(cin, val);
		h[key] = val.substr(1, val.size()-2);
	}
	deal();
	cout<< res;
	return 0;
} 
