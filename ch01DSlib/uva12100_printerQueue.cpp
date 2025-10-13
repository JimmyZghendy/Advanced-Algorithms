#include<iostream>
using namespace std;
#include<queue>
#include<functional>
#include<fstream>
#include<vector>

typedef pair<int,bool> ib;

int main(){
	//int n=1, m=0; int p[]={5};	
	//int n=4, m=2; int p[]={1,2,3,4};
	//int n=6, m=0; int p[]={1,1,9,1,1,1};
	int c, n, m;
	vector<ib> p;
	/*
	3
	1 0
	5
	4 2
	1 2 3 4
	6 0
	1 1 9 1 1 1

	*/
	ifstream fin; 
	fin.open("Solutions/ch01DSlib/in_uva12100.txt");
	if(!fin){cout<<"Error"<<endl; return 1;}
	fin>>c;
	for(int k=0; k<c; k++){
		fin>>n>>m;	
		p.assign(n,ib(0,0));
		for(int i=0; i<n; i++){
			fin>>p[i].first;
			if(i == m)
				p[i].second = true;
			else
				p[i].second = false;
		}

		int t=0; 
		queue<ib> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++)
		{
			q.push(p[i]);
			pq.push(p[i].first);
		}
		while(!q.empty()){
			if(q.front().first < pq.top()){
				q.push(q.front());
				q.pop();				
			}else{//q.front().first == pq.top()
				t++;
				if (q.front().second)
					break;
				q.pop();
				pq.pop();
			}
		}
		cout<<"time: "<<t<<endl;
		p.clear();
		while (!q.empty()) { q.pop(); }
		while (!pq.empty()) { pq.pop(); }
	}
	return 0;
}

