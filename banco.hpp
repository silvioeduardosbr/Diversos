#include<iostream>
#include<string>
//funcoes modularizadas das operaçoes bancarias
using namespace std;

struct data{
	int dia;
	int mes;
	int ano;
};

struct client{
	string nome;
	string cpf;
	data born;//strc
};

struct conta{
	client cliente;//strc
	double saldo;
	string num;
};

double verSaldo(conta &c){
	return c.saldo;
}
void transferencia(conta &saida,conta &entrada,int valor){
	saida.saldo-=valor;
	entrada.saldo+=valor;
}
void saque(conta &c, double valor){
	c.saldo -= valor;
}
void deposito(conta &c, double valor){
	c.saldo += valor;
}
void cadastrar(conta &c){
	c.saldo = 0;
	cout << "Numero da conta: ";
	cin >> c.num;
	cout << "Nome: ";
	cin.ignore();
	getline(cin,c.cliente.nome);
	cout<< "CPF: ";	
	cin >> c.cliente.cpf;
	while(c.cliente.cpf.size() != 11){
		cout << "CPF inválido" << endl;
		cout << "CPF: ";
		cin >> c.cliente.cpf;
	}
	cout << "data de nascimento(dd/mm/aaa)" << endl;
	cout << "Dia: "; cin >> c.cliente.born.dia;
	while(c.cliente.born.dia > 31 || c.cliente.born.dia <= 0){
		cout << "Insira um dia valido!" << endl;
		cin >> c.cliente.born.dia;
	}
	cout << "Mes: "; cin >> c.cliente.born.mes; 
	while(c.cliente.born.mes > 12 || c.cliente.born.mes <= 0){
		cout << "Insira um mes valido!" << endl;
		cin >> c.cliente.born.mes;
	}
	cout << "Ano: "; cin >> c.cliente.born.ano;
	while(c.cliente.born.ano > 2019 || c.cliente.born.ano < 1900){
		cout << "Insira um ano valido!" << endl;
		cin >> c.cliente.born.ano;
	}
	cout <<"---------------------------------------" << endl;
	system("clear");
}	
