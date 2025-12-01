#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<algorithm>

struct Node{
	int a, b, c;
};

int seatArrangement(int n, vector<Node> &v);

int main(){
	fstream fin;
	int n; //group size
	int m; //nb of constraints
	int c; //nb of seats distance
	int a, b; //persons
	vector<Node> v;

	fin.open("ch04algoDesign/in_uva11742.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	fin>>n>>m;
	while(n!=0 || m!=0){
		v.assign(m,Node());
		for(int i=0; i<m ; i++){
			fin>>a>>b>>c;
			v[i].a=a;v[i].b=b; v[i].c=c;
		}
		cout<<seatArrangement(n,v)<<endl;;
		fin>>n>>m;
	}
	return 0;
}

int seatArrangement(int n, vector<Node> &v){
	vector<int> g(n,0);
	vector<int>::iterator ita, itb;
	bool constraint;
	int count=0, a, b, c;
	for(int i=0; i<n; i++) g[i]=i;
	do{
		constraint = true;
		for(int i=0; i<v.size(); i++){
			a = v[i].a; b = v[i].b; c = v[i].c;
			ita = find(g.begin(),g.end(),a);
			itb = find(g.begin(),g.end(),b);
			if(c<0 && abs(itb-ita)<abs(c) || c>0 && abs(itb-ita)>abs(c)){ 
				constraint = false;
				break;
			}
		}
		if(constraint) count++;
	}while(next_permutation(g.begin(),g.end()));
	return count;
}

