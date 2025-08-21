#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
//#include<utility>//pair
using namespace std;

typedef pair<int,string> is;

void display(vector<is>&);
bool compareInt(is& p1, is& p2){
	return p1.first<p2.first;
}
bool compareStr(is& p1, is& p2){
	return p1.second<p2.second;
}

int main(){
	ifstream fin;
	int key;
	string str, familyName ;
	vector<is> v;

	fin.open("ch01DSlib/in_ex2.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}

	while(fin>>key>>str){
		v.push_back(make_pair(key,str));
	}
	display(v);

	sort(v.begin(),v.end());
	display(v);
	/*
	//2nd method
	sort(v.begin(),v.end(),compareInt);
	display(v);

	//sort according to the string
	sort(v.begin(),v.end(),compareStr);
	display(v);
	*/

	cout<<"Input family name of steven: ";
	getline(cin,familyName);//getline(cin,familyName,'\n');
	cout<<"length of familyName "<<familyName.length()<<endl;//.size()
	for(int i=0; i<v.size(); i++)
		if(v[i].second=="steven")
			v[i].second+=" "+familyName;
	display(v);

	/*
	//Another method
	for (vector<is>::iterator it = v.begin(); it != v.end(); it++) {
		if (it->second == "steven") {
			it->second += " "+familyName;
			break;
		}
	}
	*/

	key = 82;
	for(vector<is>::iterator it=v.begin(); it!=v.end(); it++)
		if(it->first == key){
			v.erase(it);
			break;
		}
	display(v);

	return 0;
}

void display(vector<is>& v){
	for(int i=0; i<v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<" "<<endl;
	cout<<"---"<<endl;
}