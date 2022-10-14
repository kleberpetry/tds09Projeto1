#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
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
	
}
void venda(){
	
}

void menu(){
	printf("\nSistema de gerenciamento");
	printf("\n1-Cadastro de produtos");
	printf("\n2-Listar produtos");
	printf("\n3-Realizar venda");
	printf("\n0-Sair\n");
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	do{
		system("cls");
		menu();
		scanf("%d",&opcao);
		
	}while(opcao!=0);
	printf("\nAplicação encerrada\n");
	
	return 0;
}

