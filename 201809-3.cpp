#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> file;
bool match(string& s, string& t){
	bool flag = t.find('#')==-1;
	if(flag)
		return regex_match(s, regex("\\.*"+t+"( #[\\w\\d]+)?", regex_constants::icase));
	return regex_match(s, regex("\\.*[\\w\\d]+ "+t));
}
void deal(string sel, int first, int last){
	int index = sel.find(' ');
	if(index==-1){
		vector<int> ans;
		
		for(int i=first; i<=last; ++i)
			if(match(file[i], sel))
				ans.push_back(i+1);
		cout<< ans.size();
		for(int& i: ans)
			cout<< " "<< i;
		cout<< endl;
	}else {
		string pre = sel.substr(0, index);
		for(int i=first; i<=last; ++i)
			if(match(file[i], pre)){
				int ind = file[i].rfind('.');
				string t = string(ind==-1? 2: ind+3, '.');
				int j = i+1;
				while(j<=last and file[j].find(t)!=-1) ++j;
				deal(sel.substr(index+1, sel.size()-index-1), i+1, j-1);
				i = j-1;
			}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>> n>> m;
	cin.get();
	while(n--){
		string line;
		getline(cin, line);
		file.push_back(line);
	}
	while(m--){
		string sel;
		getline(cin, sel);
		deal(sel, 0, file.size()-1);
	}
	return 0;
}



/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....DiV #main
......h2
......p #one
......div
........p #two
p
#subtitlE
h3
div p
diV dIv P



*/ 
