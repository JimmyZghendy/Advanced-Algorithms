#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<functional>
//#include<fstream>
using namespace std;


int firstFit(vector<float>&, vector<stack<float>>&);
int offlineFirstFit(vector<float>&, vector<stack<float>>&);

void display(vector<stack<float>>&);
int main(){
	float a[]={0.2, 0.5, 0.4, 0.7, 0.1, 0.3, 0.8};
	int n = sizeof(a)/sizeof(float);
	vector<float> v(a,a+n);
	int N; //nb of bins used
	vector<stack<float>> s;
	N = firstFit(v,s);
	//N = offlineFirstFit(v,s);
	cout<<"N = "<<N<<endl;
	display(s);
	return 0;
}

int firstFit(vector<float> &v, vector<stack<float>>&s) {
	int c = 0;//nb of bin used
	s.assign(v.size(), stack<float>());
	float size;//remainder size
	for (int j = 0; j < s.size(); j++)
		s[j].push(1.0);//top contains remaining size of each stack

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[j].top()>v[i]) {
				size = s[j].top() - v[i];
				s[j].pop();
				s[j].push(v[i]);
				s[j].push(size);
				break;
			}
		}
	}
	for (int j = 0; j < s.size(); j++)
		if (s[j].size()>1)
			c++;

	return c;
}

int offlineFirstFit(vector<float>& v, vector<stack<float>>& s) {
	int N;
	sort(v.begin(), v.end(), greater<float>());
	N = firstFit(v, s);
	return N;
}

void display(vector<stack<float>>& s) {
	cout << "Bin content, each starting with sum: " << endl;
	for (int k = 0; k<s.size(); k++) {
		if (s[k].empty()) break;
		cout << "bin #" << k << ": ";
		cout << s[k].top() << " - ";//print sum
		s[k].pop();
		while (!s[k].empty()) {
			cout << s[k].top() << " ";
			s[k].pop();
		}
		cout << endl;
	}
}

/*
int firstFit(vector<float> &v, vector<stack<float>>& s){
    int k=0, count=0;
    float sum;
    s.assign(v.size(),stack<float>());
    for(int i=0; i<v.size(); i++){
        for(int k=0; k<v.size(); k++){
            if(s[k].empty()){
                s[k].push(v[i]);
                s[k].push(v[i]);
                count++;
                break;
		    }else{
                sum = s[k].top();
                if(sum + v[i] <= 1){
                    s[k].pop();
                    s[k].push(v[i]);
                    s[k].push(sum+v[i]);
                    break;
				}
		    }
		}
	}


    return count;
}
*/



/*
float total(stack<float> s){
	float sum=0;
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	return sum;
}
*/