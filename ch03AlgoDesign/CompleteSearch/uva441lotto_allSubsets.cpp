#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

void allSubsets(int N){
	vector<int> v(N,0);
	for(int i=0; i<N; i++) v[i]=i;
	for(int k=0; k<(1<<N); k++){
		for(int i=0; i<N; i++) 
			if(k & (1<<i))
				cout<<v[i]<<" ";
			cout<<endl;
	}
}

void allSubsets(vector<int>&v){
	int count=0;
	bool set=false;
	int N = v.size();
	for(int k=0; k<(1<<N); k++){
		set=false;
		for(int i=0; i<N; i++){
			if(k & (1<<i)){
				set = true;
				cout<<v[i]<<" ";				
			}
		}
		cout<<endl;	
		if(set)count++;		
	}
	cout<<"subsets nb : count = "<<count<<endl;
}

/* Function to get no of set bits */
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int countSetBits1(int n)
{
	bitset<32> bs(n);
	return bs.count();
}

void lotto(vector<int>&v, int c){
	int count=0;
	bool set;
	int N = v.size();
	for(int k=0; k<(1<<N); k++){
		set = false;
		if(countSetBits(k) == c){
			for(int i=0; i<N; i++){
				if(k & (1<<i)){
					cout<<v[i]<<" ";
					set = true;
				}
			}
			cout<<endl;
			if(set)count++;				
		}
	}
	cout<<"subsets nb "<<count<<endl;
}

void lotto1(vector<int>&v, int c) {
	int N = v.size();
	for (int k = 0; k<(1 << N); k++) {
		bitset<32> bs(k);
		if (bs.count() == c) {
			for (int i = 0; i<N; i++) {
				if (k & (1 << i)) {
					cout << v[i] << " ";
				}
			}
			cout << endl;
		}
	}
}

void lotto2(vector<int>&v) {
	int N = v.size();
	for (int a = 0; a < N - 5; a++) // six nested loops!
		for (int b = a + 1; b < N - 4; b++)
			for (int c = b + 1; c < N - 3; c++)
				for (int d = c + 1; d < N - 2; d++)
					for (int e = d + 1; e < N - 1; e++)
						for (int f = e + 1; f < N; f++)
							cout << v[a] << " " << v[b] << " " << v[c] << " " << v[d] << " " << v[e] << " " << v[f] << endl;
}

int main(){
	int c=6 ;
	int S[] = {1,2,3,4,5,6,7}; 
	int n = sizeof(S)/sizeof(int);
	vector<int> v(S,S+n);
	allSubsets(v);
	cout<<"---"<<endl;
	cout<<"c="<<c<<"---"<<endl;
	lotto(v,c);
	cout << "---" << endl;
	lotto1(v, c);
	cout << "---" << endl;
	lotto2(v);

	return 0;
}