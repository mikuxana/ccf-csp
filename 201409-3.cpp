#include <bits/stdc++.h>
using namespace std;

string str, line;
bool flag;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin>> str>> flag>> n;
	while(n--){
		cin>> line;
		if(flag and line.find(str)!=string::npos)
			cout<< line<< endl;
		else if(not flag and regex_search(line, regex(str, regex::icase)))
			cout<< line<< endl;
	}
}
