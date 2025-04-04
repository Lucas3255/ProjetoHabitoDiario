#include <stdio.h>			//bibliotecas importadas
#include <string.h>			//
#include <stdlib.h>			//
#include <unistd.h>			//
#include <locale.h>			//
#include <time.h>			//
#include "criarHabito.h"	//
#include "verHabito.h"		//
#include "historico.h"		//
#include "configuracao.h"	//
#include "telaInicial.h"	////

void menuPrincipal();		// declaração das Funções utilizadas nesse arquivo

void telaInicial(){
	int i;

  setlocale(LC_ALL, "portuguese");	//server para mudar a linguagem para português e reconhecer acentuação	
  
  	printf("    ____________\n   | Bem Vindo  |\n   |     ao     |\n   | Habito App |\n    ------------\n\n");
  	for(i = 0; i <= 5; i++){	//tela de carregamento(MERAMENTE ILUSTRATIVA 0_0)
    	printf(" o");
    	sleep(1);
  	}
  	system("cls");
 	 menuPrincipal();				// Função Menu Principal
}

void menuPrincipal(){			//Código da Função do Menu Principal
  int opcaoInicial, i;			

  do{
    system("cls");				
    printf("\n Selecione uma opcao...\n-------------------------------------------\n 1 - Criar Novo Habito\n\n 2 - Ver Seus Habitos\n\n 3 - Historico\n\n 4 - Configuracoes\n\n 5 - Sair.\n\n >> ");
    scanf("%d", &opcaoInicial);     // ^ Menu Inicial
    fflush(stdin);			//controla o buffer/estouro de pilha.

    switch(opcaoInicial){			// Opções de funcionalidades
      	case(1):					// Opção de Criar Hábito
        	system("cls");
        	criarHabito();			// Função de Criar Hábito
      	break;

      	case(2):					// Opção de Editar Hábito
        	system("cls");
        	verHabito();			// Função de histórico
      	break;
      	
      	case(3):
      		system("cls");
      		historico();	//função de histórico.
      	break;
	  
	  	case(4):				//Opção de Configurações
        	system("cls");
        	configuracao();		// Função de Configurações
	  	break;

      	case(5):				// Opção de Fechar o Programa.
        	system("cls");
    		printf("\n Saindo do App...\n\n");
        	for(i = 0; i <= 2; i++){	//tela de carregamento(MERAMENTE ILUSTRATIVA 0_0)
          		printf("o ");			//
          		sleep(1);				////
        	}
            exit(0);			//finaliza o programa.
    	break;

      	default:				//Opção caso o usuário digite número invalido.
            system("cls");
        	printf("\n ERRO! Numero %d eh invalido, selecione outro.\n-------------------------------------------\n", opcaoInicial);
        	sleep(3);
    }
  }while(opcaoInicial != 1, 2, 3, 4, 5);
}
