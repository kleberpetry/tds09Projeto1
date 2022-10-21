#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
struct produto{
	int codigo;
	char nome[30];
	double preco;
	int estoque;
};
struct produto produtos[200];
int sequencia=0;

void cadastro(){
	system("cls");
	produtos[sequencia].codigo=sequencia+1;
	printf("\nDigitie o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o preço: ");
	scanf("%lf",&produtos[sequencia].preco);
	printf("\nDigite o estoque inicial: ");
	scanf("%d",&produtos[sequencia].estoque);
	sequencia++;
}
void listar(){
	system("cls");
	int x;
	for(x=0;x<sequencia;x++){
		printf("\nCodigo: %d",produtos[x].codigo);
		printf("\nNome: %s",produtos[x].nome);
		printf("\nPreço: %.2lf",produtos[x].preco);
		printf("\nEstoque: %d",produtos[x].estoque);
		printf("\n____________________________\n");
	}
	system("pause");
}
bool buscar(int codigo){
	bool tem;
	if(produtos[codigo-1].codigo==codigo){
		tem=true;
	}else{
		tem=false;
	}
	return tem;
}
bool verificaEstoque(int codigo,int quantidade){
	bool tem=false;
	if(buscar(codigo)==true){
		if(produtos[codigo-1].estoque>=quantidade){
			tem=true;
		}else{
			tem=false;
		}
	}else{
		
	}
	return tem;
}

void venda(){
	
}

void menu(){
	printf("\nSistema de gerenciamento");
	printf("\n1-Cadastro de produtos");
	printf("\n2-Listar produtos");
	printf("\n3-Realizar venda");
	printf("\n4-busca produto");
	printf("\n0-Sair\n");
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao,codigo;
	do{
		system("cls");
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				cadastro();
			break;
			case 2:
				listar();
			break;
			case 3:
				printf("ok3");
				system("pause");
			break;
			case 4:
				printf("\nDigite o código do produto: ");
				scanf("%d",&codigo);
				if(buscar(codigo)==true){
					printf("\nproduto existe");
				}else{
					printf("\nproduto não existe");
				}
				system("pause");
			break;
			case 0:
				printf("ok0");
				system("pause");
			break;
			default:
				printf("\nOpção inválida!\n");
		}
	}while(opcao!=0);
	printf("\nAplicação encerrada\n");
	
	return 0;
}

