#include <iostream>
/*
equipe: Silvio E. Sales
		Luana Helena
		Diego da Silva
*/
using namespace std;
//prototipo das funcoes usadas
void ganha(char jogo[3][3],char &id, bool &ganhador);
void jogada(int a, int &c, int &k);
void inicio(char jogo[3][3]);
void matriz(char jogo[3][3]);
void oJogada(int c, int k, int &cont, char jogo[3][3]);
void xJogada(int c, int k, int &cont, char jogo[3][3]);

int main(){
	char jogo[3][3], id = 'v'; //matriz do jogo e um identificador de vencedor
	int a,cont=0,c,k;//auxiliares
	bool passa = true,fim = false, ganhador = false;//variaveis de controle
	
	system("clear");
	
    inicio(jogo);//chama a funcao de atribuiçao direta dos valores na matriz
	matriz(jogo);//mostra o tabuleiro da velha, apos a atribuição
    
    while(fim == false){//loop do fim de jogo
        if(passa == true){//loop para controle das jogadas (X e O)
            cout << "JOGADA X: ";
            cin >> a;
            jogada(a,c,k);//chama a funcao que computa a jogada X, e guarda as variaveis c e k

            while(a<1 or a>9 or jogo[c][k] == 'X' or jogo[c][k] == 'O'){//CASO NAO ENTRA; verificaçao
            	cout << "JOGADA invalida!! Escolha outro numero. " << endl;
            	cin >> a;
            	jogada(a,c,k);
            }
            system("clear");
            matriz(jogo);//mostra a nova matriz
            system("clear");
           	xJogada(c,k,cont,jogo);//se a jogada for valida, atribui o x e incrementa o cont
            ganha(jogo,id,ganhador);//verifica se há ganhador
           	
            if(ganhador){// se ha ganhador, fim = T
            	passa = false;
            	fim = true;
            	if(id == 'x')//se o identficador for 'x', o x ganhou; se for 'o', o ganhou
            		cout << "JOGADOR X GANHOU!"<< endl;
            	else if(id == 'o')
            		cout << "JOGADOR O GANHOU!" << endl;
            	 	
            }
            else if(cont == 9){//se deu velha(cont = 9; todas as jogadas esgotadas)
		        passa = false;
		       	fim = true;
		       	cout << "VELHA!" << endl;
            }
           
        	if(passa == true){//se nao houve ganhador, entao pode passar
		        cout << "JOGADA O: ";//faz tudo de novo igual para a jogada "O"
		        cin >> a;
		        jogada(a,c,k);

		        while(a<1 or a>9 or jogo[c][k] == 'X' or jogo[c][k] == 'O'){//CASO NAO ENTRA
		        	cout << "JOGADA invalida!! Escolha outro numero. " << endl;
		        	cin >> a;
		        	jogada(a,c,k);
		        }
		        system("clear");
            	  
		        matriz(jogo);
		        system("clear");
		       	oJogada(c,k,cont,jogo);		   
		       	ganha(jogo,id,ganhador);	
		       
				if(ganhador){
		 			passa = false;
				   	fim = true;
				   	if(id == 'x')
				   		cout << "JOGADOR X GANHOU!"<< endl;
				   	else if(id == 'o')
				   		cout << "JOGADOR O GANHOU!" << endl; 	 	
			    }
	       		else if(cont == 9){
	       			cout << "VELHA!" << endl;
	        		passa = false;
	        		fim = true;
		       
	        	}
		    }
    	}
   	}       
    return 0;
}
//-------------------------------------------------funcoes-----------------------------------------

void oJogada(int c, int k, int &cont, char jogo[3][3]){//computa a jogada 'o'; alterando o cont e a matriz jogo
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
	    	if(i == c && j==k){
				jogo[i][j] = 'O';
			   	cont++;
		  	}
			cout << jogo[i][j] << " ";
		}
	cout << endl;
	}
}
void xJogada(int c, int k, int &cont, char jogo[3][3]){//computa x
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
	    	if(i == c && j==k){
				jogo[i][j] = 'X';
			   	cont++;
		  	}
			cout << jogo[i][j] << " ";
		}
	cout << endl;
	}
}
void matriz(char jogo[3][3]){//exibe a matriz
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << jogo[i][j] << ' ';
		}
		cout << endl;
	}
}
void inicio(char jogo[3][3]){//atribui os valores iniciais da matriz
	jogo[0][0] = '1';
    jogo[0][1] = '2';
    jogo[0][2] = '3';
    jogo[1][0] = '4';
    jogo[1][1] = '5';
    jogo[1][2] = '6';
    jogo[2][0] = '7';
    jogo[2][1] = '8';
    jogo[2][2] = '9';
}
void jogada(int a, int &c, int &k){//altera os valores de controle da matriz pra verificaçao depois de acordo com o a
		
	if(a==1){ c=0;k=0;}
    if(a==2){ c=0;k=1;}
    if(a==3){ c=0;k=2;}
    if(a==4){ c=1;k=0;}
    if(a==5){ c=1;k=1;}
    if(a==6){ c=1;k=2;}
    if(a==7){ c=2;k=0;}
    if(a==8){ c=2;k=1;}
    if(a==9){ c=2;k=2;}
}

void ganha(char jogo[3][3],char &id, bool &ganhador){//verifica caso a caso se há ganhador
	if(jogo[0][0] == 'X'){	
	  	if(jogo[0][0] == jogo[0][1] and jogo[0][1]==jogo[0][2]){
       		ganhador = true;
      		id = 'x';
       	}
       	if(jogo[0][0] == jogo[1][0] and jogo[1][0]==jogo[2][0]){
       		ganhador = true;
       		id = 'x';        
       	}
       	if(jogo[0][0] == jogo[1][1] and jogo[1][1]==jogo[2][2]){
       		ganhador = true;
       		id = 'x';
   		}      	
	}
    if(jogo[1][0] == 'X'){
            
      	if(jogo[1][0] == jogo[1][1] and jogo[1][1] == jogo[1][2]){
       		ganhador = true;
       		id = 'x';
       	}
	}
	if(jogo[2][0] == 'X'){
       	if(jogo[2][0]==jogo[2][1] and jogo[2][1]==jogo[2][2]){
       		ganhador = true;
       		id = 'x';
       	}
       	if(jogo[2][0] == jogo[1][1] and jogo[1][1]==jogo[0][2]){
       		ganhador = true;
       		id = 'x';
       	}
	}
    if(jogo[0][1] == 'X'){
       	if(jogo[0][1]==jogo[1][1] and jogo[1][1]==jogo[2][1]){
       		ganhador = true;
       		id = 'x';
       	}
    }	
    if(jogo[0][2] == 'X'){
       	if(jogo[0][2]==jogo[1][2] and jogo[1][2]==jogo[2][2]){
       		ganhador = true;
       		id = 'x';
      	}
    }
           
    if(jogo[0][0] == 'O'){	
       	if(jogo[0][0] == jogo[0][1] and jogo[0][1]==jogo[0][2]){
       	ganhador = true;
       	id = 'o';
       }		
            
		if(jogo[0][0] == jogo[1][0] and jogo[1][0]==jogo[2][0]){
       		ganhador = true;
       		id = 'o';        
       	}
       	if(jogo[0][0] == jogo[1][1] and jogo[1][1]==jogo[2][2]){
       		ganhador = true;
       		id = 'o';
    	}      	
	}
    if(jogo[1][0] == 'O'){
            
      	if(jogo[1][0] == jogo[1][1] and jogo[1][1] == jogo[1][2]){
       		ganhador = true;
       		id = 'o';
       	}
	}
	if(jogo[2][0] == 'O'){
       	if(jogo[2][0]==jogo[2][1] and jogo[2][1]==jogo[2][2]){
       		ganhador = true;
       		id = 'o';
    	}
    	if(jogo[2][0] == jogo[1][1] and jogo[1][1]==jogo[0][2]){
    		ganhador = true;
     		id = 'o';
       	}
          
    }
    if(jogo[0][1] == 'O'){
      	if(jogo[0][1]==jogo[1][1] and jogo[1][1]==jogo[2][1]){
       		ganhador = true;
       		id = 'o';
       	}
    }	
    if(jogo[0][2] == 'O'){
     	if(jogo[0][2]==jogo[1][2] and jogo[1][2]==jogo[2][2]){
       		ganhador = true;
       		id = 'o';
      	}
    }
}
