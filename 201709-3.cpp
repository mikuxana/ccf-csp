#include <bits/stdc++.h>
using namespace std;
string json;

void query(string key, string json){
	int index = key.find('.');
	smatch rs;
	if(index==string::npos){
		string reg = "\""+key+"\"\\s*:\\s*";
		if(regex_search(json, rs, regex(reg+"\"(.*?)\""))){
			string s = rs.str(1);
			if(s.find(' ')!=string::npos)
				s = regex_replace(s, regex("\\s"), "\"");
			if(s.find(R"(\\)")!=string::npos)
				s = regex_replace(s, regex("\\\\{2}"), "\\");
			cout<< "STRING "<< s<< endl;;
		}
		else if(regex_search(json, regex(reg+"\\{(.*?)\\}")))
			cout<< "OBJECT"<< endl;
		else cout<< "NOTEXIST"<< endl;
		return;
	}
	string pre = key.substr(0, index);
	if(regex_search(json, rs, regex("\""+pre+"\"\\s*:\\s*\\{(.*?)\\}")))
		query(key.substr(index+1, key.size()-index), rs[1].str());
	else cout<< "NOTEXIST"<< endl;
}

void predeal(string& line, bool flag){

	if(flag){
		if(line.find("\\\"")!=-1)
			line = regex_replace(line, regex("\\\\\""), " ");
		}
	else {
		if(line.find('\\')!=-1)
			line = regex_replace(line, regex("\\\\"), "\\\\{2}");
		if(line.find('\"')!=-1)
			line = regex_replace(line, regex("\""), " ");
		}
}




inline void regress(string& json, string& key, int left, int right){
	if key 不存在本层 
		 输出不存在
		 return
		 
	if(key 存在 key 不是最终 value 是string)
		输出不存在
		 return	 
	if (key 存在 且 key 是最终的)
		匹配value
		输出 stirng or object 
		return 
	
	key存在key不是最终的 value是object, 找出object的范围 '{', '}' 
	
	递归
	regress(json, key的下一级, '{'的索引, '}'的索引 ) ; 
}



int main(){
	string strs;
	int n, m;
	ios::sync_with_stdio(false);
	cin>> n>> m;
	cin.get();
	while(n--){
		string line;
		getline(cin, line);
		predeal(line, 1);
		json += line;
		strs += line;
	}
	
	cout<<"转成一行"<< endl;
	cout<< strs<< endl;
	cout<< "去掉所有空字符"<< endl;
	cout<< (strs = regex_replace(strs, regex("\\s+"), ""))<< endl; 
	
	cout<< endl;
	cout<< "搜索address.city"<< endl;
	
	
	
	cout<<"====================================================================="<< endl;
	cout<< endl;
	
	
	while(m--){
		string key;
		cin>> key;
		predeal(key, 0);
		query(key, json);
	}
	return 0;
}


/*

10 5
{
"firstName": "John",
"lastName": "Smith",
"address": {
"streetAddress": "2ndStreet",
"city": "NewYork",
"state": "NY"
},
"esc\\aped": "\"hello\""
}
firstName
address
address.city
address.postal
esc\aped


*/
