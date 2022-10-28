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
	int codigo;
	bool concluida=false;
	do{
		system("cls");
		printf("\nDigite o código do produto: ");
		scanf("%d",&codigo);
		if(codigo!=0){
			if(buscar(codigo)==true){
				printf("\nDigite a quantidade do produto: ");
				int qtde;
				scanf("%d",&qtde);
				if(verificaEstoque(codigo,qtde)==true){
					double total;
					total=qtde*produtos[codigo-1].preco;
					produtos[codigo-1].estoque-=qtde;
					printf("\nvalor total: %.2lf",total);
					printf("\nEstoque restante: %d"
					,produtos[codigo-1].estoque);
					printf("\ndeseja continuar 1-sim 2-não");
					int continuar;
					scanf("%d",&continuar);
					if(continuar==2){
						concluida=true;
					}
				}else{
					printf("\nQuantidade solicitada acima do estoque");
					system("pause");
				}
			}else{
				printf("\nProduto não existe, digite outro\n");
				system("pause");
			}
		}else{
			concluida=true;
		}
		
	}while(concluida==false);
		
	system("pause");
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
				venda();
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
			case 5:
				printf("\nDigite o código do produto: ");
				scanf("%d",&codigo);
				printf("\nDigite a quantidade de estoque desejada: ");
				int qtde;
				scanf("%d",&qtde);
				if(buscar(codigo)==true && verificaEstoque(codigo,qtde)==true){
					printf("\ntem em estoque, quantidade: %d\n"
					,produtos[codigo-1].estoque);
				}else{
					printf("\nNão tem estoque, quantidade: %d\n"
					,produtos[codigo-1].estoque);
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

