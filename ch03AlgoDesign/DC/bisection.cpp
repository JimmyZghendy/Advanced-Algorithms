#include<iostream>
using namespace std;
#include<vector>

#define EPS 1e-2

float calc(float v, int m, float r, float d);
float bisectionSearch(float v, int m, float r);
float formula(float v, int m, float r);

int main() {
//rate: (annual) rate of interest ; 
//r: (monthly) rate of interest (at the end of the month) (compounded)
//	float v = 1000, r = 0.1; 
//	int m = 2;
//	float v = 100000, rate = 0.1792, r = rate/12;
//	int m = 3*12;
	float v = 90000, rate = 0.105, r = rate / 12;
	int m = 10 * 12;
	float d;

	//cout<<calc(v,m,rate,d)<<endl;
	d = bisectionSearch(v,m,r);
	cout << "d = " << d << endl;
	cout << "Total interest : " << m*d - v << endl;
	cout << "d = "<<formula(v, m, r) << endl;
	return 0;
}

float bisectionSearch(float v, int m, float rate) {
	float lo, hi, mid;//maxIter, 
	float status;
	lo = 0.01; hi = v*(1+rate);
	while(fabs(hi-lo) > EPS){
		mid = (lo + hi) / 2.0;
		status = calc(v, m, rate, mid);
		cout << lo << " " << hi << " " << mid << " " << status << " " << fabs(hi - lo) << endl;
		if (status>0)
			lo = mid;
		else 
			hi = mid;
	}
	return mid;
}

float calc(float v, int m, float r, float d) {
	for (int i = 0; i < m; i++) {
		v = v*(1.0 + r) - d;
	}
	return v;
}

float formula(float v, int m, float r) {
	float d;
	d = v*r*pow((1 + r), m) / (pow((1 + r), m) - 1);
	return d;
}