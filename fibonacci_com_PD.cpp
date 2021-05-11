#include <iostream>
//#define rep(i,n) for(int i = 0; i < n; i++) // 0 <- n-1
using namespace std;

int memo[100000000];

int fib(int n){
	//Verifica se o fibonacci ja esta tabelado
	if(memo[n]) 
		return memo[n];
	
	if(n <=2) return 1;
	
	else{
		int f = fib(n-1)+fib(n-2);
		//se o problema nao foi reslvido
		//antes, resolve e tabela.
		memo[n] = f;
			 
		return f;
	}
}

int main(){

	int a ; cin>> a;
    cout << fib(a) << endl;

    return 0;
}
