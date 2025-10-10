#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<fstream>

typedef pair<int,int> ii;


int main(){
	ifstream fin;
	int type, val;
	queue<int> q;
	stack<int> s;
	priority_queue<int> pq;
	vector<ii> v;
	int n;
	bool queue, stack, priority;
	fin.open("Solutions/ch01DSlib/in_uva11995.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	while(fin>>n){
		for(int i=0; i<n; i++){
			fin>>type>>val;
			v.push_back(make_pair(type,val));
		}
		queue=true; stack=true; priority=true;
		for(int i=0; i<v.size();i++){
			if(v[i].first==1){
				q.push(v[i].second);
				s.push(v[i].second);
				pq.push(v[i].second);
			}else{
				if(v[i].second!=q.front())
					queue=false;				
				if(v[i].second!=s.top())
					stack = false;
				if(v[i].second!=pq.top())
					priority = false;
				q.pop();
				s.pop();
				pq.pop();
			}
		}
		if(queue && stack && priority || queue && stack 
			|| stack && priority || queue && priority)
			cout<<"Not sure"<<endl;
		else if(queue) cout<<"queue"<<endl;
		else if(stack) cout<<"stack"<<endl;
		else if(priority) cout<<"priority"<<endl;
		else
			cout<<"Impossible"<<endl;
		v.clear();
		while(!q.empty()){q.pop();}
		while(!s.empty()){s.pop();}
		while(!pq.empty()){pq.pop();}
	}//test

	return 0;
}
