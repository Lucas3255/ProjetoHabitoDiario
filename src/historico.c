#include <stdio.h>			//bibliotecas importadas
#include <string.h>			//
#include <stdlib.h>			//
#include <unistd.h>			//
#include <locale.h>			//
#include <time.h>			//
#include "criarHabito.h"	//
#include "verHabito.h"		//
#include "main.h"			//
#include "configuracao.h"	//
#include "telaInicial.h"	////
#define maxHistorico 50

struct historico{						//declaração da struct de histórico.
    char nomeCategoria[30];				//
    char nomeHabito[30];				//
    int duracao;						//
    char descricao[500];				//
    int marcacaoDiaria;					//
    int faltaDias;						//
    float concluindo;					//
};										//
										//
struct historico Hist[maxHistorico];	//////

void historico(){
	int escolha, i;
	
	if(histCont == 0){
		
		do{
			system("cls");
			printf("\n Historico...\n-------------------------------------------\n");
			printf(" Vazio\n\n 1 - Voltar\n-------------------------------------------\n >> ");
			scanf("%d", &escolha);
			fflush(stdin);
			
			switch(escolha){
				case(1):
					system("cls");
					menuPrincipal();
				break;
				
				default:
					system("cls");
					printf("\n ERRO! Opcao Invalida (%d).", escolha);
					sleep(3);
			}
		}while(escolha != 1);
	
	}else{
		
		do{
			system("cls");
			printf("\n Historico...\n-------------------------------------------\n");
			for(i = 0; i < histCont; i++){
				printf(" Categoria: %s\n", Hist[i].nomeCategoria);
				printf(" Habito: %s		%2.1f o/o Concluido\n", Hist[i].nomeHabito, Hist[i].concluindo);
				printf(" Duracao(em dias): %d		Falta: %d\n", Hist[i].duracao, Hist[i].faltaDias);
				printf(" Descricao: %s\n\n", Hist[i].descricao);
			}
			printf(" 1 - Voltar\n-------------------------------------------\n >> ");
			scanf("%d", &escolha);
			fflush(stdin);
			
			switch(escolha){
				case(1):
					system("cls");
					menuPrincipal();
				break;
				
				default:
					system("cls");
					printf("\n ERRO! Opcao Invalida (%d).", escolha);
					sleep(3);
			}
		}while(escolha != 1);
		
	}
}