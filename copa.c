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
	printf("\n1-Cadastrar Time");
	printf("\n2-Lançar Jogos");
	printf("\n3-Classificação\n");
}
cadastrarTime(){
	int x;
	for(x=0;x<4;x++){
		times[x].codigoTime=codigo;
		printf("\nDigite o nome do time %d: ",codigo);
		fflush(stdin);
		gets(times[x].nomeTime);
		codigo++;
			
	}
		
}
lancarJogos(){
	int time,desafiante,golT,golD;
	for(time=0;time<4;time++){
		for(desafiante=time;desafiante<4;desafiante++){
			if(time!=desafiante){
				printf("\nDigite quantidade de gols time %s partida %s X %s: ",times[time].nomeTime,times[time].nomeTime,times[desafiante].nomeTime);
				scanf("%d",&golT);
				printf("\nDigite quantidade de gols desafiante %s: ",times[desafiante].nomeTime);
				scanf("%d",&golD);
				times[time].saldoGol+=golT;
				times[desafiante].saldoGol+=golD;
				if(golT>golD){
					times[time].pontuacao+=3;
				}else if(golD>golT){
					times[desafiante].pontuacao+=3;
				}else{
					times[time].pontuacao+=1;
					times[desafiante].pontuacao+=1;
				}
			}
			
		}
	}
}
listar(){
	int x;
	for(x=0;x<4;x++){
		printf("\ncodigo: %d",times[x].codigoTime);
		printf("\nnome: %s",times[x].nomeTime);
		printf("\npontuação: %d",times[x].pontuacao);
		printf("\nsaldo de gol: %d",times[x].saldoGol);
		printf("\nclassificação: %d",times[x].classificacao);
	}
	system("pause");
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1:
				cadastrarTime();
			break;
			case 2:
				lancarJogos();
			break;
			case 3:
				listar();
			break;
		}
	}while(op!=0);
	
	
	
	return 0;
}





