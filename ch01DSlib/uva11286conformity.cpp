//UVa 11286 Conformity
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<vector>
#include<algorithm>

int main(){
	int n;//nb of students
	int N=5;//nb of courses
	int max, nb;//nb: nb of winners
	vector<int> v;
	map<vector<int>,int> mp;
	ifstream fin;
	fin.open("Solutions/ch01DSlib/in_uva11286.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	fin>>n;
	while(n!=0){
		for(int i=0; i<n; i++){
			v.assign(N,0);
			for(int j=0; j<N; j++)
				fin>>v[j];
			sort(v.begin(),v.end());
			mp[v]++;
			v.clear();
		}
		max=-1;
		for(map<vector<int>,int>::iterator it=mp.begin();it!=mp.end();it++){
			if(it->second>max){
				max = it->second;
				v = it->first;
			}
		}
		/*
		cout<<"max: "<<max<<endl;
		for(auto x: v){
			cout<<x<<" ";
		}
		cout<<endl;
		*/

		nb=0;
		for(map<vector<int>,int>::iterator it = mp.begin(); it!=mp.end(); it++){
			if(it->second==max)
				nb+=it->second;
		}
		cout<<"total winners: "<<nb<<endl;

		mp.clear();
		fin>>n;
	}
	return 0;
}