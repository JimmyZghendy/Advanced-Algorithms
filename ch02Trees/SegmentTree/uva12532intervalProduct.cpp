#include <iostream>
#include <vector>
#include <cmath>
#include<ctime>
#include<fstream>
using namespace std;

typedef vector<int> vi;

class segmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n; //nb of elements in A
  int left (int p) { return 2*p;}//p << 1; }     // same as binary heap operations
  int right(int p) { return 2*p+1;}//(p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R){ st[p] = A[L]; return;} // as L == R, either one is fine,store the index
			                         
	// recursively compute the values
    build(left(p) , L, (L+R)/2);
    build(right(p), (L+R)/2+1, R);
    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = p1*p2;
  }

 int rpq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -100000; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the min position in the left and right part of the interval
    int p1 = rpq(left(p) , L, (L+R)/2, i, j);
    int p2 = rpq(right(p), (L+R)/2+1, R, i, j);

    if (p1 == -100000) return p2;   // if we try to access segment outside query
    if (p2 == -100000) return p1;                               // same as above
    return p1*p2;           // as in build routine
}
  
void point_update(int p,int L,int R,int i, int val){
	if(i>R || i<L) return;
	if(L == i && R == i && L==R) {A[i]=val; st[p]=A[L]; return ;}//st[p]=L; necessary for the insert function

	point_update(left(p),L,(L+R)/2,i,val);
	point_update(right(p),(L+R)/2+1,R,i,val);
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = p1*p2;
}  
  



public:
	segmentTree(const vi &_A) {
		A = _A; n = (int)A.size();              // copy content for local usage
		st.assign(4 * n, 0);            // create large enough vector of zeroes
		build(1, 0, n - 1);                                  // recursive build
  }

  int rpq(int i, int j) { return rpq(1, 0, n - 1, i, j); }   // overloading


  void point_update(int i, int val){
	  point_update(1,0,n-1,i,val);
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

};
  //----------------------//



int main() {
	ifstream fin;
	int N, K, x, I, J, V;
	vector<int> v;
	char c;
	fin.open("in_uva12532.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}

	while(fin>>N>>K){		
		for(int i=0; i<N; i++){
			fin>>x;
			v.push_back(x);
		}
		segmentTree st(v);
		for(int i=0; i<K; i++){
			fin>>c;
			if(c == 'C') {
				fin>>I>>V; 
				I--;
				st.point_update(I,V);
			}//array start from index 0
			else {
				fin>>I>>J; 
				I--; J--;
				if(st.rpq(I,J)<0){
					cout<<"-";
				}else if(st.rpq(I,J)>0)
					cout<<"+";
				else
					cout<<"0";
			}
		}
		cout<<endl;
		v.clear();
	}


  return 0;
}