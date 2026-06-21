#include <stdio.h>			//bibliotecas importadas
#include <string.h>			//
#include <stdlib.h>			//
#include <unistd.h>			//
#include <locale.h>			//
#include <time.h>			//
#include "configuracao.h"	////

void configuracao(){		//função de configuração/personalização
  int mudarCor;

  setlocale(LC_ALL, "portuguese");	//server para mudar a linguagem para português e reconhecer acentuação

  do{
    system("cls");			//limpa tela
    printf("\n Configuracoes:\n-------------------------------------------\n 1 - Branco     4 - Vermelho\n\n 2 - Azul       5 - Matrix\n\n 3 - Roxo       6 - Amarelo\n\n                7 - Voltar\n-------------------------------------------\n >> ");
    scanf("%d", &mudarCor);			//^ opções apresentadas ao usuário
    fflush(stdin);			//controla o buffer/estouro de pilha.

    switch(mudarCor){			//opções de mudar a cor das letras
      case(1):
        system("cls");		//limpa tela
        system("color 07");	//opção de cor
      break;

      case(2):
        system("cls");		//limpa tela
        system("color 3");	//opção de cor
      break;

      case(3):
        system("cls");		//limpa tela
        system("color 5"); //opção de cor
      break;

      case(4):
        system("cls");		//limpa tela
        system("color 4");	//opção de cor
      break;

      case(5):
        system("cls");		//limpa tela
        system("color 2");	//opção de cor
      break;

      case(6):
        system("cls");		//limpa tela
        system("color 6");	//opção de cor
      break;

      case(7):				//opção para voltar para o menu principal
        system("cls");		//limpa tela
        menuPrincipal();	//função de menu principal
      break;

      default:				//opção caso o usuário não selecione uma opção existente
        system("cls");		//limpa tela
        printf("\n ERRO! %d eh invalido.\n-------------------------------------------\n", mudarCor);
        sleep(3);			//código de pausa temporaria
    }
  }while(mudarCor != 1, 2, 3, 4, 5, 6, 7);	//fim do loop
}