#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<fstream>
#include<string>
#include<functional>

typedef pair<int,string> is;

void display(map<int,string>&m);
template<typename T> void display(T);

/*
class comp{
public: 	
	bool operator()(string &a, string&b){
		return a<b;
	}
};
*/
int main(){
	ifstream fin;
	int key;
	string str;
	map<int, string> m;
	set<int> s;
	set<int,greater<int>> s2;
	//map<int,string,greater<int>>m2;
	//map<int,string,comp>m2;

	fin.open("Solutions/ch01DSlib/in_ex2.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}

	while(fin>>key>>str){
		m.insert(make_pair(key,str));
	}
	display(m);

	cout<<m[77]<<endl;
	m[120]="hello";
	cout<<m[120]<<endl;
	cout<<m[119]<<endl;
	for(auto x: m){
		cout<<x.first<<" "<<x.second<<endl;
	}

	for(map<int,string>::iterator it=m.begin();it!=m.end();it++){
		s.insert(it->first);
		s2.insert(it->first);
	}
	display<set<int>>(s);
	display<set<int,greater<int>>>(s2);

	m.erase(77);//m.erase(it);
	s.erase(77);
	display(m);
	display<set<int>>(s);

	//modify the "value" of key 78
	m[78]="halim";//1st method

	//2nd method
	m.erase(78);
	m.insert(make_pair(78,"halim"));

	//3rd method
	map<int,string>::iterator it;
	it = m.find(78);
	if(it!=m.end())
		it->second = "halim";
	else
		cout<<"Not found"<<endl;

	//modify the key in set: erase then insert
	s.erase(78);
	s.insert(79);	

	display(m);
	display<set<int>>(s);

	m.erase(m.begin(),m.end());//m.clear();
	s.erase(s.begin(),s.end());//s.clear();
	display(m);
	display<set<int>>(s);
	return 0;
}

void display(map<int,string>&m){
	for(map<int,string>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<"---"<<endl;
}

template<typename T> void display(T s){
	for(T::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}
	cout<<"---"<<endl;
}
