#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> h;

void deal(string& sub, int l, int r, int c){
	int new_c = 0;
	for(; l<=r and isdigit(sub[l]); ++l) 
		new_c = new_c*10+sub[l]-'0'; 
	if(new_c!=0) c *= new_c;
	for(int i=l; i<=r; ++i){
		int k = i+1, j = i, back_c = 0, f = 1;
		if(sub[i]=='('){
			do{
				++j;
				if(sub[j]=='(') f++;
				if(sub[j]==')') f--;
			}while(f);
		}
		else if(k<=r and islower(sub[k])) {++k; ++f;}
		else if(sub[i]=='+' or sub[i]=='='){
			if(sub[i]=='+') deal(sub, i+1, r, c>0? 1: -1);
			else if(sub[i]=='=') deal(sub, i+1, r, -1);
			break;
		}
		for(k=f? i+f: j+1; k<=r and isdigit(sub[k]); ++k) 
			back_c = back_c*10+sub[k]-'0';
		back_c = back_c? back_c: 1;
		if(f)
			h[sub.substr(i, f)] += c*back_c;
		else deal(sub, i+1, j-1, c*back_c);
		i = k-1;
	}
}
int main(){
//	ios::sync_with_stdio(false);
	int t;
	string formula;
	cin>> t;
	while(t--){
		cin>> formula;
		deal(formula, 0, formula.size()-1, 1);
		bool flag = true;
		for(auto& p: h)
			if(p.second){
				flag = false;
				break;
			}
		cout<< (flag? "Y": "N")<< endl;
		h.clear();
	}
	return 0;
} 

//Ca2CO3+H2Cl2=CaCl2+H2O+CO2; 
/*
 
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au

