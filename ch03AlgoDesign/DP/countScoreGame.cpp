// A C++ program to count number of 
// possible ways to a given score 
// can be reached in a game where a 
// move can earn 3 or 5 or 10 
#include <iostream> 
using namespace std;
#include<vector>

void display(vector<int> v);
// Returns number of ways 
// to reach score n 
int count(int n)
{
	// table[i] will store count 
	// of solutions for value i. 
	vector<int> table(n+1, 0);//init to 0

	// Base case (If given value is 0) 
	table[0] = 1;

	// One by one consider given 3 moves 
	// and update the table[] values after 
	// the index greater than or equal to 
	// the value of the picked move 
	for (int i = 3; i <= n; i++)
		table[i] += table[i - 3];

	for (int i = 5; i <= n; i++)
		table[i] += table[i - 5];

	for (int i = 10; i <= n; i++)
		table[i] += table[i - 10];

	display(table);
	return table[n];
}



// Driver Code 
int main(void)
{
	int n = 20;

	cout << "Count for " << n
		<< " is " << count(n) << endl;
	
	n = 13;
	cout << "Count for " << n << " is "
		<< count(n) << endl;
	return 0;
}

void display(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		cout << i << "\t";
	cout << endl;
	for (auto x : v) {
		cout << x << "\t";
	}
	cout << endl;
}
// This code is contributed 
// by Shivi_Aggarwal 
