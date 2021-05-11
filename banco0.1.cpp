#include<iostream>
#include<string>
#include<time.h>
#include "banco.hpp"

using namespace std;


int main(){
	bool saldo = false;
	conta contas[5];//vetor de contas, max 5.
	conta csaida, centrada;//auxiliares(guarda conta de saida, '' '' de entrada)
	string n,saida,entrada;//auxiliares(auxiliar n, uma auxiliar para guardar o numero da conta de saida e entrada)
	string nome1,nome2, numero1,numero2; // variaveis auxiliares para a transferencia
	int ncontas = 0;//aux
	double valor=0;
	int op;//opcao menu
	//system("clear");
	time_t a;
	time(&a);
	//struct e funcao da data e hora
	struct tm *timeinfo;
	timeinfo = localtime(&a);
	
	do{//exibiçao do menu inicial das operaçoes
		cout << "============BANCO============="<<endl;
		cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << 
		"/" << 1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << 
		":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl<<endl;
		
		cout << "1 - Cadastrar uma conta" << endl;
		cout << "2 - Ver saldo"<< endl;
		cout << "3 - Transferencia" << endl;
		cout << "4 - Saque" << endl;
		cout << "5 - Deposito" << endl;
		cout << "6- Terminar operacoes" << endl;
		cout << endl;
		cout << "Digite uma opcao:"; 
		cin >> op;//leitura da opcao
		cout << endl;
		//system("clear");
		
		switch(op){
			
			case 1://====================cadastro====================
				//system("clear");
				if(ncontas < 5){//se nao passou do maximo de contas, é possivel cadastrar
					for(int i=0;i<5;i++){//de 0 a 4 (5 contas)
						if(ncontas == i){//-Se o meu numero de contas cadastradas é igual ao indice, significa que...
							cadastrar(contas[i]);//eu posso cadastrar uma conta nessa posição atual, pois se eu tenho...
							//1 conta, o meu ncontas esta em 1, portanto, eu tenho essa uma conta cadastrada na posiçao...
							//0, entao, na posicao[ncontas] (que é i), eu nao tenho nada ainda-.
							ncontas++;//passa para outra conta, incrementa
							cout << "Conta Cadastrada!" << endl;
							timeinfo = localtime(&a);//mostra a data e hora
							cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << "/" << 
							1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << ":" << 
							timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl;
							cout <<"------------------------------------------"<<endl;
							break;
						}
					}
				}else{
					cout << "Ja tem 5 contas!!" << endl;//se nao puder, envia mensagem
					break;
				}
					break;
			//======================================================	
			case 2://========ver saldo=======================
				//system("clear");
				cout << "Qual o numero da sua conta?" << endl;//informa o numero da conta e mostra o saldo da struct
				cin >> n;//auxiliar n que recebe o numero da conta
				for(int i=0;i<ncontas;i++){//percorre as contas ja cadastradas (ncontas)
					if(contas[i].num == n){//se achar a conta, mostra o numero, saldo e o nome
						cout <<"--------------------------------"<<endl;
						cout << "Numero da conta: "<<contas[i].num << endl;
						cout << "Nome: "<<contas[i].cliente.nome << endl;
						cout << "SALDO: R$ " << verSaldo(contas[i]) << endl;
					}
				}
				timeinfo = localtime(&a);//data e hora
				cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << 
				"/" << 1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << 
				":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl;
				cout <<"--------------------------------"<<endl;
				break;
			case 3:	//============transferencia===================
				//system("clear");
				
				cout << "Qual o numero da sua conta?" << endl;
				cin >> saida; //aux do conta de saida 
				cout << "Digite o valor que voce quer transferir:" <<endl;
				cin >> valor;//auxiliar que recebe o valor da tranferencia para trabalhar com ele
				for(int i=0;i<ncontas;i++){
					if(contas[i].num == saida){
						if(contas[i].saldo < valor){ // verifico se o saldo vai ficar negativo
							cout << "Saldo insuficiente!" << endl;//mostra msg d aviso
							cout << "--------------------------------"<<endl;
							saldo = false;
							break;
						}else
							//cout << "Ok!" << endl;
							csaida = contas[i];//se o saldo nao ficar negativo
							nome1 = contas[i].cliente.nome;
							numero1 = contas[i].num;
							saldo = true;
							break;
					}
				}
				if(saldo){
					cout << "Qual o numero da conta para transferencia? " << endl;
					cin >> entrada;//computa os dados do receptor da transferencia, analogo ao emissor
					for(int i=0; i<ncontas;i++){
						if(contas[i].num == entrada){
							centrada = contas[i];
							nome2 = contas[i].cliente.nome;
							numero2 = contas[i].num;					 
							//cout << "Ok!" << endl;
						}
					}
					transferencia(csaida,centrada,valor);//chama a funcao que altera o saldo das auxiliares com base na transf
					cout <<"--------------------------------"<<endl;
					cout <<"A CONTA: " << numero1 <<endl;
					cout << nome1 << endl;
					cout<< "TRANSFERIU R$ " << valor << " PARA:" <<endl;
					cout <<  numero2 <<endl;
					cout << nome2 << endl;
					timeinfo = localtime(&a); // função para dar o horario 
					cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << 
					"/" << 1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << 
					":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl;
					cout <<"--------------------------------"<<endl;
					
					
					for(int i=0;i<ncontas;i++){//devolve, apos o processamento nas aux, os valores as contas do vetor de fato
						if(contas[i].num == centrada.num){
							contas[i] = centrada;
						}
						if(contas[i].num == csaida.num){
							contas[i] = csaida;
						}
					}
					valor = 0;
				}
				break;
				//=====================================================
			case 4://===========saque==================================
				cout << "Numero da conta para saque: " << endl;
				cin >> n;//altera simplesmente o saldo da struct
				for(int i=0;i<ncontas;i++){
					if(contas[i].num == n){
						cout <<"--------------------------------"<<endl;
						cout << "VALOR DO SAQUE:";
						cin >> valor;
						if(contas[i].saldo < valor){
							cout << "Saldo insuficiente!" << endl;
							cout << "-----------------------------------" << endl;
							break;
						}else{
							saque(contas[i],valor);
							cout << contas[i].num << endl;
							cout << contas[i].cliente.nome << endl;
							timeinfo = localtime(&a); // função para dar o horario 
							cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << 
							"/" << 1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << 
							":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl;
							cout <<"--------------------------------"<<endl;
							break;
						}
					}
				}
				valor = 0;
				break;
				//====================================================
				
			case 5://================deposito=======================
				cout << "Numero da sua conta: " << endl;//analogo ao saque, so que incrementa o saldo
				cin >> n;
				for(int i=0;i<ncontas;i++){
					if(contas[i].num == n){
						cout << "VALOR DO DEPOSITO:";
						cin >> valor;
						deposito(contas[i],valor);
						cout << contas[i].num << endl;
						cout << contas[i].cliente.nome << endl;
						timeinfo = localtime(&a); // função para dar o horario 
						cout<< timeinfo->tm_mday << "/" << 1 +  timeinfo->tm_mon << 
						"/" << 1900 + timeinfo->tm_year << " [" << timeinfo->tm_hour << 
						":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << "]"  <<endl;
						cout <<"--------------------------------"<<endl;
						break;
					}
				}
				valor = 0;
				break;
			
			default:
				cout << "Opcao invalida" << endl;
				break;
			}
			
	}while(op != 6);		

	return 0;
}
