#include<iostream>
#include<string>
using namespace std;
/*
Silvio E. - UECE
*/

struct funcionario{
	string nome;
	double salario;
	double imposto;
	double aliq;

};
	
int main(){
	int cont=0;
	double soma=0;
	
	funcionario funcs[10];//vetor de funcionarios do tipo funcionario.
	
	string nome;

			for(int i=0;i<10;i++){ //cadastro
				cout << "------------------------------------------------------" <<endl;
				cout << "Diga o nome do funcionario  "  << "["<<  i+1 << "]:"  << endl;
				cin.ignore();
				getline(cin, funcs[i].nome);
				printf("\n");
				cout << "Diga o salario do funcionario  " << "["<<  i+1 << "]:" << endl;
				cin >> funcs[i].salario;
				printf("\n");
				while (funcs[i].salario < 788.00 ){//enquanto for menor que o minimo, nao pode
					printf("O valor digitado e menor que o salario minimo (R$ 788.00 < %.2lf)",funcs[i].salario);
					printf("\n\n");
					cout << "Diga o salario do funcionario  " << "["<<  i+1 << "]:" << endl;
					cin >> funcs[i].salario;
					printf("\n");
				}
				cout << "------------------------------------------------------" << endl;
				//sequencia de if's baseado nas condicoes dos salarios
				if(funcs[i].salario >= 788.00 && funcs[i].salario <= 1903.98){//isento
					cout <<"Funcionario "<<funcs[i].nome << " esta insento" << endl;
					funcs[i].imposto = 0;//se esta isento, o campo imposto é 0
					funcs[i].aliq = 0;
					cout << "\nAliquota: " << funcs[i].aliq*100 << "%" << endl;
					cont++;//incrementa o cont (dividendo da media)
					soma+=0;//incrementa a soma com 0 (divisor da media)
					printf("\nDeve pagar R$ %.2lf de impostos\n",funcs[i].imposto);
					printf("\n");
					funcs[i].salario = (funcs[i].salario) - (funcs[i].imposto);//salario liquido, descontados os impostos
					printf("Salario apos a Deducao do imposto : R$ %.2lf  \n\n", funcs[i].salario);
					printf("Media do imposto na empresa: R$ %.2lf\n\n",soma/cont);//calcula a media
					
				}else if(funcs[i].salario >= 1903.99 &&  funcs[i].salario <=2826.65){//7.5%
					funcs[i].aliq = 0.075;//aliquota recebe 7.5/100 para facilitar a multiplicação
					
					cout << "\nAliquota: " << funcs[i].aliq*100 << "%" << endl;
					
					funcs[i].imposto = funcs[i].salario * funcs[i].aliq;//calculo do imposto
					cont++;//dividendo++
					soma+=funcs[i].imposto;//incrementa o divisor com o imposto
					
					printf("\nDeve pagar R$ %.2lf de impostos\n",funcs[i].imposto);
					printf("\n");
					funcs[i].salario = (funcs[i].salario) - (funcs[i].imposto);//salario liquido
					printf("Salario apos a Deducao do imposto : R$ %.2lf  \n\n", funcs[i].salario);
					printf("Media do imposto na empresa: R$ %.2lf\n\n",soma/cont);//media ate agora
					
					//todas as outras interacoes sao analogas a essa, mudando somente os limites do salario
				}else if(funcs[i].salario >= 2826.66 && funcs[i].salario <=3751.05){
					funcs[i].aliq = 0.15;
					cout << "\nAliquota: " << funcs[i].aliq*100 << "%" << endl;
					funcs[i].imposto = funcs[i].salario * funcs[i].aliq;
					cont++;
					soma+=funcs[i].imposto;
					printf("\nDeve pagar R$ %.2lf de impostos\n",funcs[i].imposto);
					printf("\n");
					funcs[i].salario = (funcs[i].salario) - (funcs[i].imposto);
					printf("Salario apos a Deducao do imposto : R$ %.2lf  \n\n", funcs[i].salario);
					printf("Media do imposto na empresa: R$ %.2lf\n\n",soma/cont);
					
				}else if(funcs[i].salario >= 3751.06 && funcs[i].salario <= 4664.08){
					funcs[i].aliq = 0.225;
					cout << "\nAliquota: " << funcs[i].aliq*100 << "%" << endl;
					funcs[i].imposto = funcs[i].salario * funcs[i].aliq;
					cont++;
					soma+=funcs[i].imposto;
					printf("\nDeve pagar R$ %.2lf de impostos\n",funcs[i].imposto);
					printf("\n");
					funcs[i].salario = (funcs[i].salario) - (funcs[i].imposto);
					printf("Salario apos a Deducao do imposto : R$ %.2lf  \n\n ", funcs[i].salario);
					printf("Media do imposto na empresa: R$ %.2lf\n\n",soma/cont);

				}else if(funcs[i].salario >= 4664.08){
					funcs[i].aliq = 0.227;
					cout << "\nAliquota: " << funcs[i].aliq*100 << "%" << endl;
					funcs[i].imposto = funcs[i].salario* funcs[i].aliq;
					cont++;
					soma+=funcs[i].imposto; 
					printf("\nDeve pagar R$ %.2lf de impostos\n",funcs[i].imposto);
					printf("\n");
					funcs[i].salario = (funcs[i].salario) - (funcs[i].imposto);
					printf("Salario apos a Deducao do imposto : R$ %.2lf  \n\n", funcs[i].salario);
					printf("Media do imposto na empresa: R$ %.2lf\n\n",soma/cont);
			}
	
		}
	return 0;
} 
