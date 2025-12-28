#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int RSQ(vector<int> & a){
	int Max = a[0];
	int sum = a[0];
	for(int i=1; i<a.size();i++){
		if(sum > 0)//sum + a[i] > a[i]
			sum += a[i];
		else sum = a[i];
		Max = max(Max,sum);//if(sum>Max)Max=sum
	}
	return Max;
}
//try to find what are the indices of this largest sum.


int RSQv2(vector<int> & a){
	//this method works if at least there is a value >=0;
	//if all values negative, it does not work
  int running_sum = 0, ans = 0;
  for (int i = 0; i < a.size(); i++)                         // O(n)
   // the overall running sum is still +ve    
    if (running_sum + a[i] >= 0){
	running_sum += a[i];
       ans = max(ans, running_sum); // keep the largest RSQ overall
    }
    else// the overall running sum is -ve, we greedily restart here
      running_sum = 0;// because starting from 0 is better for future iterations than starting from -ve running sum
  return ans;

}

int main(){
	int A[] = {1,-2,6,3,2,-12,-6,7,1};
	int n = sizeof(A)/sizeof(int);
	vector<int> a(A,A+n);
	cout<<RSQ(a)<<endl;
	return 0;
}