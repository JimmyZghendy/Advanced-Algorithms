#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
#include<functional>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> MinPQ;

void display(vector<int>& v);
void display(queue<int> q);
void display(stack<int> s);
void display(priority_queue<int> pq);
void display(MinPQ pq);

template<typename T>
void tdisplay(T ds);


int main(){
	int n=12, x;
	vector<int> v; 
	queue<int> q;
	stack<int> s;
	priority_queue<int> maxpq;
	MinPQ minpq;

	srand(time(0));

	for(int i=0; i<n; i++){
		x = rand() % (200 - 10 + 1) + 10;
		v.push_back(x);
	}
	cout << "vector: " << endl;
	display(v);

	while (!v.empty()) {
		x = v.back();
		v.pop_back();
		q.push(x);
	}
	cout << "queue: " << endl;
	display(q);
/*
	for(int i=0; i<n; i++) q.push(v[i]);
	v.clear(); //v.erase(v.begin(),v.end());
	//OR
	vector<int>::iterator it=v.begin();
	while(it!=v.end()){it=v.erase(it);}
	//OR
	for(vector<int>::iterator it=v.begin(); it!=v.end(); )
		it=v.erase(it);
	*/
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		s.push(x);
	}
	cout << "stack: " << endl;
	//display(s);
	tdisplay(s);//tdisplay<stack<int>>(s);
	
	while(!s.empty()){
		x = s.top();
		s.pop();
		if(x%2==0)
			maxpq.push(x);
		else
			minpq.push(x);
	}

	cout<<"max pq even: "<<endl;
	//display(maxpq);
	tdisplay(maxpq);//tdisplay<priority_queue<int>>(maxpq);

	cout<<"min pq even: "<<endl;
	//display(minpq);
	tdisplay(minpq);//tdisplay<priority_queue<int,vector<int>,greater<int>>>(minpq);

	return 0;
}

template<typename T>
void tdisplay(T ds){
	while(!ds.empty()){
		cout<<ds.top()<<" ";
		ds.pop();
	}
	cout<<endl;
	cout<<"----"<<endl;

}

void display(vector<int>& v) {
	//for(auto x: v)
	//cout<<x<<" ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "----" << endl;
}
void display(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	cout << "----" << endl;
}
void display(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << "----" << endl;
}

void display(priority_queue<int> pq) {
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	cout << "----" << endl;
}

void display(MinPQ pq) {
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	cout << "----" << endl;
}