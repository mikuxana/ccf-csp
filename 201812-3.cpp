#include <bits/stdc++.h> 
using namespace std;

struct prefix{
	string ip;   // 32λbit
	int len;
	prefix(string& i, int& l): ip(i), len(l){}
	void to_preIp(){
		string preIp = "";
		for(int i=0; i<4; ++i){
			int t = 0;
			for(int j=i*8, c=0; c<8; ++c, ++j)
				t = t*2+ip[j]-'0';
			preIp += to_string(t)+".";
		}
		preIp.pop_back();
		cout<< preIp<< "/"<< len<< endl;
	}
};

list<prefix> prefixs; 

prefix predeal(string& preIp){
	string ip = "";
	int len = -1, line = preIp.find('/');
	int i = 0;
	while(true){
		int ind = preIp.find('.', i);
		if(ind!=-1){
			ip += bitset<8>(stoi(preIp.substr(i, ind-i))).to_string();
			i = ind+1;
		}else {
			ind = line;
			if(ind!=-1) {
				ip += bitset<8>(stoi(preIp.substr(i, ind-i))).to_string();
				i = ind+1;
				len = stoi(preIp.substr(i));
			}else 
				ip += bitset<8>(stoi(preIp.substr(i))).to_string();
			break;
		}
	}
	if(len==-1) len = ip.size();
	while(ip.size()<32) ip+="0";
	return prefix(ip, len);
}

bool canCombine1(prefix& a, prefix& b){
	if(a.len>b.len) return false;
	for(int i=0; i<a.len; ++i)
		if(a.ip[i]!=b.ip[i])
			return false;
	return true;
}
bool canCombine2(prefix& a, prefix& b){
	if(a.len!=b.len) return false;
	int i;
	for(i=0; i<a.len-1; ++i)
		if(a.ip[i]!=b.ip[i])
			return false;
	return a.ip[i]!=b.ip[i];
}

void merge1(){
	auto i = prefixs.begin(), j = i;
	for(++j; j!=prefixs.end();){
		if(canCombine1(*i, *j))
			j = prefixs.erase(j);
		else {
			++i;
			++j;
		}
	}	
}
void merge2(){
	auto i = prefixs.begin(), j = i, k = i;
	for(++j; j!=prefixs.end();)
		if(canCombine2(*i, *j)){
			i->ip[i->len-1] = '0';
			i->len--;
			j = prefixs.erase(j);
			if(i!=prefixs.begin()) {
				j = i;
				i = k;
				--k;
			}
		}else{
			k = i;
			++i;
			++j;
		}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>> n;
	string preIp;
	while(n--){
		cin>> preIp;
		prefixs.push_back(predeal(preIp));
	}
	prefixs.sort([&](prefix& a, prefix& b)->bool{
		if(a.ip==b.ip)
			return a.len<b.len;
		return a.ip<b.ip;
	});
	merge1();
	merge2();
	for(auto& p: prefixs)
		p.to_preIp();
	return 0;
}


/*
//	in
2
1
2
//	out
1.0.0.0/8
2.0.0.0/8

//	in
2
10/9
10.128/9
//	out
10.0.0.0/8

//	in
2
0/1
128/1

// out
0.0.0.0/0


*/


























