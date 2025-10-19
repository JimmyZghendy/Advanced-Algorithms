#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;


class SegmentTreeSum {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // 2*p same as binary heap operations
  int right(int p) { return (p << 1) + 1; }// 2*p+1

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = A[L];                       // store the value of index L 
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int v1 = st[left(p)], v2 = st[right(p)];
      st[p] = v1 + v2;
  } }

  int rsq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range

     // compute the sum value in the left and right part of the interval
    int v1 = rsq(left(p) , L              , (L+R) / 2, i, j);
    int v2 = rsq(right(p), (L+R) / 2 + 1, R          , i, j);

    if (v1 == -1) return v2;   // if we try to access segment outside query
    if (v2 == -1) return v1;                               // same as above
    return v1+v2; }          // as in build routine

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
      return st[p] = A[L]; // this index
    }

    // compute the minimum pition in the 
    // left and right part of the interval
    int v1, v2;
    v1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
    v2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

    // return the pition where the overall minimum is
    return st[p] = v1+v2;
  }

public:
  SegmentTreeSum(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }   // overloading

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};
  


int main() {
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
  vi A(arr, arr + 7);                      // copy the contents to a vector
  SegmentTreeSum st(A);

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("              A is {18,17,13,19,15, 11,20}\n");
  printf("RSQ(1, 3) = %d\n", st.rsq(1, 3));             // answer = 49
  printf("RSQ(4, 6) = %d\n", st.rsq(4, 6));             // answer = 46
  printf("RSQ(3, 4) = %d\n", st.rsq(3, 4));             // answer = 34

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("Now, modify A into {18,17,13,19,15,100,20}\n");
  st.update_point(5, 100);                    // update A[5] from 11 to 100
  printf("These values change\n");
  printf("RSQ(0, 6) = %d\n", st.rsq(0, 6));            // 
  printf("RSQ(4, 6) = %d\n", st.rsq(4, 6));            // 
  printf("RSQ(4, 5) = %d\n", st.rsq(4, 5));           // 
 
  return 0;
}
