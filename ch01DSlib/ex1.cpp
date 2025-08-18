#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<functional>
using namespace std;

void display(vector<int>&);
void displayReverse(vector<int>&);
bool comparison(int a, int b){
	return a>b;
}
int main(){
	int n=12, x;
	//srand(time(0));
	//cout<<"Input n: "; cin>>n;

	vector<int> v; //v(n), v(n,value), v(begin,end)//end: after the end	
	//v.assign(n,value);

	for(int i=0; i<n; i++){
		x = rand()%191+10;
		v.push_back(x);//v[i]
	}
	cout<<"Size: "<<v.size()<<endl;

	cout<<"Vector contents: "<<endl;
	display(v);
	displayReverse(v);
	reverse(v.begin(),v.end());
	display(v);

	vector<int>::iterator it;
	it=find(v.begin(),v.end(),120);
	if(it==v.end()) cout<<"Not found"<<endl;
	else cout<<"Found"<<endl;

	cout<<"max: "<<*max_element(v.begin(),v.end())<<endl;
	cout<<"min: "<<*min_element(v.begin(),v.end())<<endl;

	sort(v.begin(),v.end());
	display(v);
	if(binary_search(v.begin(),v.end(),126)) cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
	it=find(v.begin(),v.end(),72);
	if(it==v.end()) cout<<"Not found"<<endl;
	else v.erase(it);
	display(v);

	/*
	//better complexity with lower_bound function
	it = lower_bound(v.begin(), v.end(), 72);
	if (it != v.end() && *it == 72) {
		v.erase(it);
		cout << "Erased" << endl;
		display(v);
	}
	else
		cout << "Not found" << endl;
	*/	
	/*
	for (vector<int>::iterator it = v.begin(); it != v.end(); ) {
		if (*it == 10){
			it = v.erase(it);
			continue;
			//break;
		}
		it++;
	}
	*/
	
	random_shuffle(v.begin(),v.end());
	sort(v.begin(),v.end(),comparison);
	//sort(v.begin(),v.end(),greater<int>());
	display(v);

	random_shuffle(v.begin(),v.end());
	nth_element(v.begin(),v.begin()+3, v.end());
	cout<<*(v.begin()+3)<<endl;//cout<<v[3];
	display(v);
	nth_element(v.begin(),v.begin()+v.size()/2, v.end());
	cout<<*(v.begin()+v.size()/2)<<endl;//cout<<v[v.size()/2];

	sort(v.begin(),v.end());

	int left=40, right=141;
	vector<int>::iterator l, r;
	l=lower_bound(v.begin(),v.end(),left);
	r=upper_bound(v.begin(),v.end(),right);
	cout<<*l<<" "<<*r<<endl;
	//[left,right], right included here
	for(vector<int>::iterator it = l; it!=r;it++)
		cout<<*it<<" ";
	cout<<endl;
	//to not include right, it!=r-1; or (it!=r && *it!=right)
	return 0;
}

void displayReverse(vector<int>& v){
	for(vector<int>::reverse_iterator it = v.rbegin(); it!=v.rend();it++)
		cout<<*it<<" ";
	cout<<endl;
}

void display(vector<int>& v){
	for(vector<int>::iterator it = v.begin(); it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;
/*
	for(auto x: v)
		cout<<x<<" ";
	cout<<endl;

	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl
*/
}