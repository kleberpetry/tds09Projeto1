#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

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

