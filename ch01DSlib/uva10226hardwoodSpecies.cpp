#include<iostream>
using namespace std;
#include<map>
#include<fstream>;
#include<string>

int main(){
	map<string,int> mp;
	ifstream fin;
	string str;
	int c=0;
	fin.open("Solutions/ch01DSlib/in_uva10226.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	while(getline(fin,str)){
		mp[str]++;
		c++;
	}
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<" "<<100.0*(it->second)/c<<endl;
	}
	return 0;
}