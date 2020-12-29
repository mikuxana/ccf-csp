#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

typedef long long ll;

const ll MOD = 2009731336725594113;


ll u[5] = {314882150829468584, 
			427197303358170108,
			1022292690726729920,
			1698479428772363217,
			2006101093849356424};
ll f(ll x){
	return x%MOD%2019;
}

ll n, q, s, l, r, t;
vector<ll> a(MAXN);
int main(){
	ios::sync_with_stdio(false);
	cin>> n>> q;

	iota(a.begin(), a.begin()+n+1, 0);
	while(q--){
		cin>> l>> r;
		s = 0;
		for(ll i=l; i<=r; ++i)
			s += f(a[i]);
		cout<< s<< endl;
		t = s%5;
		for(ll i=l; i<=r; ++i)
			a[i]*=u[t];
	}
	return 0;
}
