/**
* Compute Fibonacci numbers recursively
*/
long fib( int n )
{
	if( n <= 1 )
		return 1;
	else
		return fib( n - 1 ) + fib( n - 2 );
}

int Fib(int n, int* Values) {
	// Assume Values has at least n elements, 
	// initialized to 0
	if (n <= 1) return 1; 
	if (Values[n] != 0) return Values[n];
	Values[n] = Fib(n-1, Values) + Fib(n-2, Values);
	return Values[n];
}

long long fib(int n) {
	long long past, prev, curr;
	past = prev = curr = 1; 
	for (int i=2; i<=n; i++) { // Compute next value		
		curr = prev + past; //Fib(i) = Fib(i-1)+Fib(i-2)
		past = prev; 
		prev = curr; 
	}
	return curr;
}

int fib(int n)
{
	int *f = new int[n+1];
	int i;
	f[0] = 0; f[1] = 1;
	for (i = 2; i <= n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}