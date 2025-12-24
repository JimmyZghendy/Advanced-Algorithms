// A Dynamic Programming based solution for 0-1 Knapsack problem
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//Iterative bottom-up
int subsetsum(int W, vector<int>& wt, vector<vector<int>>&opt);
int knapsack(int W, vector<int>& wt, vector<int>& val, vector<vector<int>>&opt);

void display(vector<vector<int>>& opt);
void driverIter();

//Recursive complete search
int subsetsum(int i, int w, vector<int>& wt);//1
int subsetsum(int i, int w, int W, vector<int>& wt);//2
int knapsack(int i, int w, vector<int>& wt, vector<int>& val);

//Recursive DP top-down
int subsetsum(int i, int w, vector<int>& wt, vector<vector<int>>&opt);
int knapsack(int i, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>&opt);
void driverRec();
void display1(vector<vector<int>>& opt);

void displayItems1(vector<vector<int>>&opt, vector<int> &wt);
void displayItems2(int i, int w, vector<vector<int>>&opt, vector<int> &wt);

int main(){
	driverIter();
	driverRec();

	return 0;
}

void displayItems1(vector<vector<int>>&opt, vector<int> &wt) {//opt from iterative bottom-up
	int n = opt.size();
	int W = opt[0].size()-1;
	vector <bool> selected(n, false);
	int i = n-1, w = W;  
	while(i>0 && w>0){
		if (opt[i][w] != opt[i-1][w]) {//we used wt[i], so w becomes w-wt[i]
			selected[i] = true;
			w = w - wt[i];
		}
		else {//we didn't use wt[i], so w remains the same.
			selected[i] = false;
		}
		i--;
	}
	cout << "Items weight selected: ";
	for (int i = 0; i < n; i++)
		if (selected[i])
			cout << wt[i] << " ";
	cout << endl;

}



void driverIter() {
	vector<int> wt = { 0, 3, 4, 7, 8 ,9 };//{ 0, 1, 2, 5, 6 ,7 };//
	vector<int> val = { 0, 4, 5, 10, 11, 13 };//{ 0, 1, 6, 18, 22, 28 };//
	int W =  17; //11;
	int n = wt.size();
	vector<vector<int>> opt(n, vector<int>(W + 1, 0));
	//DP bottom-up
	cout << "SubSetSum DP bottom-up: " << subsetsum(W, wt,opt) << endl;
	display(opt);
	displayItems1(opt,wt);
	opt.clear();
	opt.assign(n, vector<int>(W + 1, 0));
	cout << "knapSack DP bottom-up: " << knapsack(W, wt, val,opt) << endl;
	display(opt);
}

int subsetsum(int W, vector<int>& wt, vector<vector<int>>&opt) {
	int n = wt.size();

	// Build table opt[][] in bottom up manner
	for (int i = 1; i < n; i++) {
		for (int w = 1; w <= W; w++) {
			if (wt[i] > w)
				opt[i][w] = opt[i - 1][w];
			else
				opt[i][w] = max(wt[i] + opt[i - 1][w - wt[i]], opt[i - 1][w]);
		}
	}
	return opt[n-1][W];
}


// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<int>& wt, vector<int>& val, vector<vector<int>>&opt) {
	int n = wt.size();

	// Build table opt[][] in bottom up manner
	for (int i = 1; i < n; i++) {
		for (int w = 1; w <= W; w++) {
			if (wt[i] > w)
				opt[i][w] = opt[i - 1][w];
			else
				opt[i][w] = max(val[i] + opt[i - 1][w - wt[i]], opt[i - 1][w]);
		}
	}
	return opt[n-1][W];
}

void display(vector<vector<int>>& opt) {
	for (int i = 0; i < opt.size(); i++) {
		for (int w = 0; w <opt[i].size(); w++) {
			cout << opt[i][w] << " ";
		}
		cout << endl;
	}
}

void driverRec() {
	vector<int> wt = { 0, 3, 4, 7, 8 ,9 };
	vector<int> val = { 0, 4, 5, 10, 11, 13 };
	int n;
	int W = 17;
	n = wt.size();
	vector<vector<int>> opt(n, vector<int>(W + 1,-1));
	//Complete Search
	cout<<"subsetsum Rec1: "<<subsetsum(1,W,W,wt)<<endl;
	cout << "subsetsum Rec2: " << subsetsum(1, W, wt) << endl;
	cout << "knapsack Rec: " << knapsack(1, W, wt, val) << endl;
	//DP top-down
	cout << "subsetsum Rec DP: " << subsetsum(1, W, wt, opt) << endl;
	display1(opt); 
	//cout << "Items are: "; displayItems2(1, W, opt, wt); cout << endl;
	opt.clear();
	opt.assign(n, vector<int>(W + 1, -1));
	cout << "knapsack Rec DP: " << knapsack(1, W, wt, val, opt) << endl;
}

int subsetsum(int i, int w, int W, vector<int>& wt) {
	if (i == wt.size() || w <= 0) return W - w;
	if (wt[i] > w)	return subsetsum(i + 1, w, W, wt);//leave it
	int l = subsetsum(i + 1, w, W, wt);//leave it
	int r = subsetsum(i + 1, w - wt[i], W, wt);//pick it
	return max(l, r);
}


int subsetsum(int i, int w, vector<int>& wt) {
	if (i == wt.size() || w <= 0) return 0;
	if (wt[i] > w)	return subsetsum(i + 1, w, wt);//leave it
	int l = subsetsum(i + 1, w, wt);//leave it
	int r = wt[i] + subsetsum(i + 1, w - wt[i], wt);//pick it
	return max(l, r);
}


int knapsack(int i, int w, vector<int>& wt, vector<int>& val) {
	if (i == wt.size() || w <= 0) return 0;
	if (wt[i] > w)	return knapsack(i + 1, w, wt, val);
	int l = knapsack(i + 1, w, wt,val);
	int r = val[i] + knapsack(i + 1, w - wt[i], wt, val);
	return max(l, r);
}

int subsetsum(int i, int w, vector<int>& wt, vector<vector<int>>&opt) {
	if (i == wt.size() || w <= 0) return 0;
	if (opt[i][w] != -1) return opt[i][w];
	if (wt[i] > w)	return opt[i][w] = subsetsum(i + 1, w, wt, opt);
	int l = subsetsum(i + 1, w, wt, opt);
	int r = wt[i] + subsetsum(i + 1, w - wt[i], wt, opt);
	return opt[i][w] = max(l, r);
}


int knapsack(int i, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>&opt) {
	if (i == wt.size() || w <= 0) return 0;
	if (opt[i][w] != -1) return opt[i][w];
	if (wt[i] > w)	return opt[i][w] = knapsack(i + 1, w, wt, val, opt);
	int l = knapsack(i + 1, w, wt, val, opt);
	int r = val[i] + knapsack(i + 1, w - wt[i], wt, val, opt);
	return opt[i][w] = max(l, r);
}


void display1(vector<vector<int>>& opt) {
	for (int i = 0; i < opt.size(); i++) {
		for (int w = 0; w <opt[i].size(); w++) {
			if(opt[i][w]!=-1)
				cout << opt[i][w] << " ";
		}
		cout << endl;
	}
}
