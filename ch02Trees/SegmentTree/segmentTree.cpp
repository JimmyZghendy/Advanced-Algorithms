#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

typedef vector<int> vi;

//we can do it template: insert type T data in vector
class segmentTree{
private:
	vi st, a;
	int n;
	int left(int p){ return 2*p; }
	int right(int p){ return 2*p+1; }
	void build(int p, int L, int R){
		if(L==R) {st[p] = L; return ;}
		build(left(p),L,(L+R)/2);
		build(right(p),(L+R)/2+1, R);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (a[p1]<=a[p2])?p1:p2;
	}

	int rmq(int p, int L, int R, int i, int j){
		if(i>R || j<L) return -1;
		if(L>=i && R<=j) return st[p];

		int p1 = rmq(left(p),L,(L+R)/2,i,j);
		int p2 = rmq(right(p),(L+R)/2+1,R,i,j);
		if (p1==-1) return p2;
		if (p2==-1) return p1;
		return (a[p1]<=a[p2])?p1:p2;
	}


	void point_update(int p,int L,int R,int i, int val){
		if(i>R || i<L) return;
		if(L == i && R == i && L==R) {a[i]=val; return ;}

		point_update(left(p),L,(L+R)/2,i,val);
		point_update(right(p),(L+R)/2+1,R,i,val);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = a[p1]<a[p2]?p1:p2;
	}

	void range_update(int p,int L,int R,int i, int j, int val){
		if(i>R || j<L) return;
		if(L >= i && R <= j && L==R) {a[L]=val; return ;}

		range_update(left(p),L,(L+R)/2,i,j,val);
		range_update(right(p),(L+R)/2+1,R,i,j,val);
		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = a[p1]<a[p2]?p1:p2;
	}

public:
	segmentTree(vi A){
		a = A; n = A.size();
		st.assign(4*n,0);		
		build(1,0,n-1);
	}
	int rmq(int i, int j){
		return rmq(1,0,n-1,i,j);
	}

	void point_update(int i, int val){
		//a[i] = val;
		point_update(1,0,n-1,i,val);
	}

	void range_update(int i, int j, int val){
		range_update(1,0,n-1,i,j,val);
	}

	void display(){
		for(auto x: st)
			cout<<x<<" ";
		cout<<endl;
		for(auto x: a)
			cout<<x<<" ";
		cout<<endl;
	}

	void removeElement(int idx){
		vi::iterator it = find(a.begin(),a.end(),a[idx]);
		a.erase(it);
		build(1,0,a.size()-1);
	}

	void insertElement(int val){
		a.push_back(val);
		build(1,0,a.size()-1);
	}
};



int main(){
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
 // int n = sizeof(arr)/sizeof(int);
  vi A(arr, arr + 7);                      // copy the contents to a vector
  segmentTree st(A);

  cout<<"              idx    0, 1, 2, 3, 4,  5, 6\n";
  cout<<"              A is {18,17,13,19,15, 11,20}\n";
  cout<<"RMQ(1, 3) = "<<st.rmq(1, 3)<<endl;             // answer = index 2
  cout<<"RMQ(4, 6) = "<<st.rmq(4, 6)<<endl;             // answer = index 5
  cout<<"RMQ(3, 4) = "<<st.rmq(3, 4)<<endl;             // answer = index 4
  cout<<"RMQ(0, 0) = "<<st.rmq(0, 0)<<endl;             // answer = index 0
  cout<<"RMQ(0, 1) = "<<st.rmq(0, 1)<<endl;             // answer = index 1
  cout<<"RMQ(0, 6) = "<<st.rmq(0, 6)<<endl;             // answer = index 5
  st.display();
  cout<<"              idx    0, 1, 2, 3, 4,  5, 6\n";
  cout<<"Now, modify A into {18,17,13,19,15,100,20}\n";
  st.point_update(5, 100);                    // update A[5] from 11 to 100
  st.display();
  cout<<"These values do not change\n";
  cout<<"RMQ(1, 3) = "<<st.rmq(1, 3)<<endl;                            // 2
  cout<<"RMQ(3, 4) = "<<st.rmq(3, 4)<<endl;                            // 4
  cout<<"RMQ(0, 0) = "<<st.rmq(0, 0)<<endl;                            // 0
  cout<<"RMQ(0, 1) = "<<st.rmq(0, 1)<<endl;                            // 1
  cout<<"These values change\n";
  cout<<"RMQ(0, 6) = "<<st.rmq(0, 6)<<endl;                         // 5->2
  cout<<"RMQ(4, 6) = "<<st.rmq(4, 6)<<endl;                         // 5->4
  cout<<"RMQ(4, 5) = "<<st.rmq(4, 5)<<endl;                         // 5->4
  //cout<<"Now, modify A into {18,17,100,100,100,100,20}\n";
  //st.range_update(2,5, 100); 
  cout<<"Now, modify A into {18,17,13,100,100,100,20}\n";
  st.range_update(3,5, 100); 
  st.display();
  cout<<"RMQ(1, 3) = "<<st.rmq(1, 3)<<endl;                            
  cout<<"RMQ(3, 4) = "<<st.rmq(3, 4)<<endl;                            
  cout<<"RMQ(0, 0) = "<<st.rmq(0, 0)<<endl;                            
  cout<<"RMQ(0, 1) = "<<st.rmq(0, 1)<<endl;                            
  cout<<"RMQ(0, 6) = "<<st.rmq(0, 6)<<endl;                         // 
  cout<<"RMQ(4, 6) = "<<st.rmq(4, 6)<<endl;                         // 
  cout<<"RMQ(4, 5) = "<<st.rmq(4, 5)<<endl;                         // 


	/*
	int n=10, val;
	vi A;
	for(int i=0; i<n; i++){
		val = rand()%100;
		cout<<val<<" ";
		A.push_back(val);
	}
	cout<<endl;
	segmentTree st(A);
	st.display();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;
	*/
	/*
	st.point_update(3,100);
	st.display();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;
	*/
  /*
	st.range_update(3,5,10);
	st.display();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;
	*/
	return 0;
}