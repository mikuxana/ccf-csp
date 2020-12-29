#include <bits/stdc++.h>
using namespace std;

vector<string> marks;
string ans = "";

void convert(){
	for(int i=0; i<marks.size(); ++i){
		string& line = marks[i];
		if(line[0]=='\n') continue;
		smatch rs;
		if(line[0]=='#'){
			regex_search(line, rs, regex("^(#+)\\s+(.*)"));
			string g = to_string(rs.str(1).size());
			line = "<h"+g+">"+rs.str(2)+"</h"+g+">\n";
		}else if(line[0]=='*'){
			int j = i+1;
			while(j<marks.size() and marks[j][0]=='*') line += marks[j++];
			line = regex_replace(line, regex("\\*\\s*([^\\\n]*)"), "<li>$1</li>");
			line = "<ul>\n"+line+"</ul>\n";
			i = j-1;
		}
		else {
			int j = i+1;
			while(j<marks.size() and marks[j][0]!='\n') line += marks[j++];
			line.pop_back();
			line = "<p>"+line+"</p>\n";
			i = j-1;
		}
		
		if(line.find('_')!=-1) line = regex_replace(line, regex("_(.*)_"), "<em>$1</em>");
		if(line.find('[')!=-1)
			line = regex_replace(line, regex("\\[(.*)\\]\\((.*)\\)"), "<a href=\"$2\">$1</a>");
		ans += line;
	}
		
}

int main(){
	string line;
	while(getline(cin, line))
		marks.push_back(line+"\n");
	convert();
	ans.pop_back();
	cout<< ans;
	return 0;
}
