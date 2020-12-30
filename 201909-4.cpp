// 推荐系统
#include <bits/stdc++.h>
#define Mod (long long)1e9
using namespace std;
typedef long long LL;

LL n, m, op;

struct Item{
	LL id;
	LL score;
	Item(): id(0), score(0){}
	Item(const LL& type, const LL& comdy, const LL& score){
		this->id = type*Mod+comdy;
		this->score = score;
	}
	bool operator <(const Item& r) const{
		if(score==r.score)
			return id<r.id;
		return score>r.score;
	}
};


set<Item> Items;
unordered_map< LL, set<Item>:: iterator> addr;

void add(const LL& type, const LL& comdy, const& score){
	addr[type*Mod+comdy] = Items.insert(Item(type, comdy, score)).first;
}

void del(const LL& type, const LL& comdy){
	auto& it = addr[type*Mod+comdy];
	Items.erase(it);
	addr.erase(type*Mod+comdy);
}

void query(LL& k, vector<LL>& Vm){
	vector<vector<LL> > sel(m, vector<LL>());
	for(auto& item: Items){
		if(k==0)
			break;
		LL type = item.id/Mod, comdy = item.id%Mod;
		if(sel[type].size()<Vm[type]){
			sel[type].push_back(comdy);
			k--;
		}
	}
	
	for(auto& ty: sel)
		if(!ty.empty()){
			for(LL& co: ty)
				cout<< co<< " ";
			cout<< endl;
		}
		else
			cout<< "-1\n";
	
}

int main(){
	ios::sync_with_stdio(false);
	cin>> m>> n;
	while(n--){
		LL comdy, score;
		cin>> comdy>> score;
		for(LL i=0; i<m; ++i)
			add(i, comdy, score);
	}
	cin>> op;
	while(op--){
		LL opType, type, comdy, score;
		cin>> opType;
		switch(opType){
			case 1:
				cin>> type>> comdy>> score;
				add(type, comdy, score);
				break;
			case 2:
				cin>> type>> comdy;
				del(type, comdy);
				break;
			case 3:
				LL k;
				vector<LL> Vm(m);
				cin>> k;
				for(LL i=0; i<m; ++i)
					cin>> Vm[i];
				query(k, Vm);
		}
	}
	
	
	return 0;
}
