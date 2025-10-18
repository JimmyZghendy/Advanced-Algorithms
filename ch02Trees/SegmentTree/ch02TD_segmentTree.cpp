#include <iostream>
#include <vector>
#include <cmath>
#include<ctime>
using namespace std;

typedef vector<int> vi;

class segmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n; //nb of elements in A

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R){ st[p] = L; return;} // as L == R, either one is fine,store the index
			                         
	// recursively compute the values
    build(2*p , L, (L+R)/2);
    build(2*p+1, (L+R)/2+1, R);
    int p1 = st[2 * p], p2 = st[2 * p + 1];
    st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }

 int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rmq(2 * p, L, (L+R)/2, i, j);
    int p2 = rmq(2 * p + 1, (L+R)/2+1, R, i, j);

    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return (A[p1] <= A[p2]) ? p1 : p2;           // as in build routine
}
 /*
  int update_point(int p, int L, int R, int idx, int new_value) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx, j = idx;

    // if the current interval does not intersect 
    // the update interval, return this st node value!
    if (i > R || j < L)
      return st[p];

    // if the current interval is included in the update range,
    // update that st[node]
    if (L == i && R == j) {
      A[i] = new_value; // update the underlying array
      return st[p] = L; // this index
    }

    // compute the minimum position in the 
    // left and right part of the interval
    int p1, p2;
    p1 = update_point(2*p , L              , (L + R) / 2, idx, new_value);
    p2 = update_point(2*p+1, (L + R) / 2 + 1, R          , idx, new_value);

    // return the position where the overall minimum is
    return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
  }
 */
  
void point_update(int p,int L,int R,int i, int val){
	if(i>R || i<L) return;
	if(L == i && R == i && L==R) {A[i]=val; st[p]=L; return ;}//st[p]=L; necessary for the insert function

	point_update(2 * p,L,(L+R)/2,i,val);
	point_update(2 * p + 1,(L+R)/2+1,R,i,val);
	int p1 = st[2 * p], p2 = st[2 * p + 1];
	st[p] = (A[p1]<A[p2])?p1:p2;
}  
  
void range_update(int p, int L, int R, int i, int j, int val){
	if(i>R || j<L) return;
	if(L>=i && R<=j && L==R){ A[L]=val; st[p]=L;return;}

	range_update(2 * p,L,(L+R)/2,i,j,val);
	range_update(2 * p + 1,(L+R)/2+1,R,i,j,val);
	int p1 = st[2 * p], p2=st[2 * p + 1];
	st[p]=(A[p1]<A[p2])?p1:p2;
}


public:
	segmentTree(const vi &_A) {
		A = _A; n = (int)A.size();              // copy content for local usage
		st.assign(4 * n, 0);            // create large enough vector of zeroes
		build(1, 0, n - 1);                                  // recursive build
  }

  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

 /*
 int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
	*/
  void point_update(int i, int val){
	  //A[i]=val;
	  point_update(1,0,n-1,i,val);
  }
  void range_update(int i, int j, int val){
	  range_update(1,0,n-1,i,j,val);
  }

  void remove(int idx){
	  A.erase(A.begin()+idx);
	  n = A.size();
	  build(1, 0, n - 1);
	 // point_update(1,0,n-1,idx,9999);//INF=9999; //to verify
  }

void insert(int val){
	A.push_back(val);
	n = A.size();
	build(1,0,n-1);
	//point_update(1,0,n-1,n-1,val);//may not work for all cases?! to verify
}

  void display(){
	 cout<<"Array A"<<endl;
	 for(int i=0; i<A.size();i++){
		 cout<<i<<"\t";
	 }
	 cout<<endl;
	 for(int i=0; i<A.size();i++){
		 cout<<A[i]<<"\t";
	 }
	 cout<<endl;
	 cout<<"Segment tree"<<endl;
	 for(auto x: st){
		 cout<<x<<" ";
	 }
	 cout<<endl;

  }
  vi Array(){
	  return A;
  }
};
  //----------------------//


void driver1();
void driver2();
void driver3();
int main() {
	//driver1();
	//driver2();
	driver3();

  return 0;
}

void driver1(){
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
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
}

void driver2(){
	int n=10, val;
	vi A;
	//srand(time(0));
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
	/*
	st.point_update(3,100);
	st.display();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;
	*/
	cout<<"range_update(3,5,10)"<<endl;
	st.range_update(3,5,10);
	st.display();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;

}

void driver3(){

	int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
	vi A(arr, arr + 7);                      // copy the contents to a vector
	segmentTree st(A);
	int n;
	st.display();
	cout<<"st.insert(0)"<<endl;
	A.push_back(0);
	st.insert(0);
	st.display();
	n = A.size();
	cout<<"st.rmq(0,n-1)"<<endl;
	cout<<st.rmq(0,n-1)<<endl;
	A=st.Array();
	n = A.size();
	st.remove(n-1);
	st.display();
	cout<<"st.rmq(0,n-1)"<<endl;
	cout<<st.rmq(0,n-1)<<endl;
	/*
	int n=10, val;
	vi A;
	srand(time(0));
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
	cout<<"st.rmq(n-2,n-1): "<<st.rmq(n-2,n-1)<<endl;
	cout<<"st.insert(0)"<<endl;
	A.push_back(0);
	st.insert(0);
	st.display();
	n = A.size();
	cout<<"st.rmq(0,n-1): "<<st.rmq(0,n-1)<<endl;
	cout<<"st.rmq(2,7): "<<st.rmq(2,7)<<endl;
	cout<<"st.rmq(n-2,n-1): "<<st.rmq(n-2,n-1)<<endl;
	*/
}