#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> regs, bacs;

void predeal(){
	for(string& reg: regs){
		if(reg.find("<int>")!=-1)
			reg = regex_replace(reg, regex("<int>"), "(\\d+)");
		if(reg.find("<str>")!=-1)
			reg = regex_replace(reg, regex("<str>"), "([^/]+)");
		if(reg.find("<path>")!=-1)
			reg = regex_replace(reg, regex("<path>"), "(.+)");
	}
}

void match(string& url){
	for(int i=0; i<regs.size(); ++i){
		smatch rs;
		if(regex_match(url, rs, regex(regs[i]))){
			cout<< bacs[i];
			for(int j=1; j<rs.size(); ++j){
				cout<< " ";
				string s = rs[j].str();
				if(isdigit(s[0])){
					int c = 0;
					for(int k = 0; k<regs[i].length(); ++k){
						if(regs[i][k]=='(')
							c++;
						if(c==j){
							int l = k+1;
							while(regs[i][l]!=')') ++l;
							if(regs[i].substr(k, l-k+1)=="(\\d+)")
								cout<< stoi(s);
							else cout<< s;
							break;
						}
					}
				}else cout<< s;
			}
			cout<<endl;
			return;
		}
	}
	cout<< "404"<< endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	while(n--){
		string reg, bac;
		cin>> reg>> bac;
		regs.push_back(reg);
		bacs.push_back(bac);
	}
	predeal();
	while(m--){
		string url;
		cin>> url;
		match(url);
	}
	return 0;
} 



/*


5 4
/articles/2003/ special_case_2003
/articles/<str>/ year_archive
/articles/<int>/<int>/ month_archive
/articles/<int>/<int>/<str>/ article_detail
/static/<path> static_serve
/articles/2004/
/articles/1985/09/aloha/
/articles/hello/
/static/js/jquery.js





*/
