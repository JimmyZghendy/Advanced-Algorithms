#include<iostream>
using namespace std;
#include<queue>
#include<functional>
#include<fstream>
#include<string>

typedef pair<int,string> is;

//typedef pair<string,int> is;
/*
class compare{
public:
	bool operator()(is& a, is& b){
		return a.second > b.second;
	}
};
*/
int main(){
	priority_queue<is,vector<is>,greater<is>> pq;
	//priority_queue<is,vector<is>,compare> pq;
	int key;
	string str;
	//is p;

	ifstream fin;

	fin.open("ch01DSlib/in_ex2.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}

	while(fin>>key>>str){
		pq.push(make_pair(key,str));
		//pq.push(make_pair(str,key));
	}

	while(!pq.empty()){
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
	}

	return 0;
}