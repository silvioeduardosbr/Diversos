#include<iostream>

using namespace std;

int main(){

	int n,i,q,m;	

	unsigned int fib[61];

	fib[0] = 0;
	fib[1] = 1;

	for(i = 2; i < 61; i++){

		fib[i] = fib[i-1] + fib[i-2];
	}

	cin >> q;

	while(q--){
		
		cin >> m;

		cout << "Fib(" << m << ") = " << fib[m] << endl;
		m = 0;
	}

	return 0;
}
