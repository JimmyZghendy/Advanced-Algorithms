#include<iostream>
using namespace std;
#include <cmath>
#include <stack>


#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

void printSet(int vS) {                         // in binary representation
	cout<<"S = "<<vS<<" = ";
	stack<int> st;
	while (vS)
		st.push(vS % 2), vS /= 2;
	while (!st.empty())                         // to reverse the print order
		cout<<st.top()<<" ", st.pop();
	cout<<endl;
}

int main() {
	int S, T;

	cout<<"1. Representation (all indexing are 0-based and counted from right)"<<endl;
	S = 34; printSet(S);
	cout << endl;

	cout << "2. Multiply S by 2, then divide S by 4 (2x2), then by 2" << endl;
	S = 34; printSet(S);
	S = S << 1; printSet(S);
	S = S >> 2; printSet(S);
	S = S >> 1; printSet(S);
	cout << endl;

	cout<<"3. Set/turn on the 3-th item of the set"<<endl;
	S = 34; printSet(S);
	setBit(S, 3); printSet(S);
	cout << endl;

	cout<<"4. Check if the 3-th and then 2-nd item of the set is on?"<<endl;
	S = 42; printSet(S);
	T = isOn(S, 3); 
	cout << "T = " << (T ? "ON" : "OFF") << endl;
	T = isOn(S, 2); 
	cout << "T = " << (T ? "ON" : "OFF") << endl;

	cout<<"5. Clear/turn off the 1-st item of the set"<<endl;
	S = 42; printSet(S);
	clearBit(S, 1); printSet(S);
	cout << endl;

	cout<<"6. Toggle the 2-nd item and then 3-rd item of the set"<<endl;
	S = 40; printSet(S);
	toggleBit(S, 2); printSet(S);
	toggleBit(S, 3); printSet(S);
	cout << endl;

	printf("7. Check the first bit from right that is on\n");
	S = 40; printSet(S);
	T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
	S = 52; printSet(S);
	T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
	cout << endl;

	printf("8. Turn on all bits in a set of size n = 6\n");
	setAll(S, 6); printSet(S);
	cout << endl;

	cout<<"9. Other tricks "<<endl;
	cout << "8 % 4 = "<< modulo(8, 4) <<endl;
	cout << "7 % 4 = " << modulo(7, 4) << endl;
	cout << "6 % 4 = " << modulo(6, 4) << endl;
	cout << "5 % 4 = " << modulo(5, 4) << endl;

	cout << "is 9 power of two? "<< isPowerOfTwo(9) << endl;
	cout << "is 8 power of two? " << isPowerOfTwo(8) << endl;
	cout << "is 7 power of two? " << isPowerOfTwo(7) << endl;
	for (int i = 0; i <= 16; i++)
		cout << "Nearest power of two of "<<i<<" is " << nearestPowerOfTwo(i)<<endl;
	cout << "S = 40, turn off last bit in S, S = " << turnOffLastBit(40)<<endl;
	cout << "S = 41, turn on last zero in S, S = " << turnOnLastZero(41) << endl;
	cout << "S = 39, turn off last consectuve bits in S, S = " << turnOffLastConsecutiveBits(39) << endl;
	cout << "S = 36, turn on last consecutive zeroes in S, S = " << turnOnLastConsecutiveZeroes(36) << endl;

	return 0;
}
