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
	if key �����ڱ��� 
		 ���������
		 return
		 
	if(key ���� key �������� value ��string)
		���������
		 return	 
	if (key ���� �� key �����յ�)
		ƥ��value
		��� stirng or object 
		return 
	
	key����key�������յ� value��object, �ҳ�object�ķ�Χ '{', '}' 
	
	�ݹ�
	regress(json, key����һ��, '{'������, '}'������ ) ; 
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
	
	cout<<"ת��һ��"<< endl;
	cout<< strs<< endl;
	cout<< "ȥ�����п��ַ�"<< endl;
	cout<< (strs = regex_replace(strs, regex("\\s+"), ""))<< endl; 
	
	cout<< endl;
	cout<< "����address.city"<< endl;
	
	
	
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
