#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct time{
	int codigoTime;
	char nomeTime[20];
	int pontuacao;
	int saldoGol;
	int classificacao;
};
struct time times[4];
int codigo=1;
menu(){
	system("cls");
	printf("1-Cadastrar Time");
	printf("2-Lançar Jogos");
	printf("3-Classificação");
}
cadastrarTime(){
	int x;
	for(x=0;x<4;x++){
		times[x].codigoTime=codigo;
		printf("\nDigite o nome do time %d",codigo);
		fflush(stdin);
		gets(times[x].nomeTime);
		codigo++;
			
	}
		
}

main(){
	setlocale(LC_ALL, "Portuguese");
	menu();
	return 0;
}





