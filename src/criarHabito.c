#include <stdio.h>			//bibliotecas importadas.
#include <string.h>			//
#include <stdlib.h>			//
#include <unistd.h>			//
#include <locale.h>			//
#include <time.h>			//
#include "main.h"			//
#include "verHabito.h"		//
#include "historico.h"		//
#include "criarHabito.h"	////
#define maxHistorico 50

struct habito{				//declaração da struct de Habitos.
  char nomeCategoria[30];	//
  char nomehabito[30];		//
  int duracao;				//
  char descricao[500];		//
  int marcacaoDiaria;		//
  int faltaDias;			//
  float concluindo;			//
};							/////

struct habito Habitos[10];		//nomeando a struct e declarando o limite de Habitos a serem criados.

struct historico{			//declaração da struct de historico já existente.
    char nomeCategoria[30];	//
    char nomeHabito[30];	//
    int duracao;			//
    char descricao[500];	//
    int marcacaoDiaria;		//
    int faltaDias;			//
    float concluindo;		//
};							//
							//
struct historico Hist[maxHistorico];	///////

void habitoGeral();		//declaração das funções usadas nesse arquivo.

void criarHabito(){
	int escolha;

  setlocale(LC_ALL, "portuguese");	//server para mudar a linguagem para português e reconhecer acentuação.

  do{					//loop para garantir q o usuário digite as opções validas.
    system("cls");		//limpa tela.
    printf("\n Escolha uma Categoria: \n-------------------------------------------\n 1 - Exercicios     4 - Entretenimento\n\n 2 - Saude          5 - Trabalho\n\n 3 - Estudos        6 - Personalizar\n\n                    7 - Voltar\n-------------------------------------------\n >> ");
    scanf("%d", &escolha);		//^ presentação das opções iniciais.
    fflush(stdin);		//controla o buffer do teclado/estouro de pilha.

    switch(escolha){		
      case(1):				//opção para criar um hábito de Exercicios.
        system("cls");		//limpa tela.
        strcpy(Habitos[x].nomeCategoria, "Exercicios");	//atribuindo uma nova string a variavel de nome da Categoria da struct.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(2):				//opção para criar um hábito de Saúde.
        system("cls");		//limpa tela.
        strcpy(Habitos[x].nomeCategoria, "Saude");	//atribuindo uma nova string a variavel de nome da Categoria da struct.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(3):				//opção para criar um hábito de Estudos.
        system("cls");		//limpa tela.
        strcpy(Habitos[x].nomeCategoria, "Estudo");	//atribuindo uma nova string a variavel de nome da Categoria da struct.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(4):				//opção para criar um hábito de Entretenimento.
        system("cls");		//limpa tela.
        strcpy(Habitos[x].nomeCategoria, "Entretenimento");	//atribuindo uma nova string a variavel de nome da Categoria da struct.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(5):				//opção para criar um hábito de Trabalho.
        system("cls");		//limpa tela.
        strcpy(Habitos[x].nomeCategoria, "Trabalho");	//atribuindo uma nova string a variavel de nome da Categoria da struct.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(6):				//opção para criar um hábito Personalizado.
        system("cls");		//limpa tela.
        printf("\n Criando Habito...\n-------------------------------------------\n Nome da Categoria: ");
        scanf("%30[^\n]s", Habitos[x].nomeCategoria);
        fflush(stdin);		//controla o buffer do teclado/estouro de pilha.
        habitoGeral();		//função base para criar todos os hábitos.
      break;

      case(7):				//opção para voltar ao menu principal.
        system("cls");		//limpa tela.
        menuPrincipal();	//função de menu Principal
      break;

      default:				//opção caso o usuário digite uma opção invalida.
        system("cls");		//limpa tela.
        printf("\n ERRO! Valor invalido (%d).", escolha);	//mensagem de erro.
        sleep(3);			//pausa o programa por alguns segundos.
    }
  }while(escolha != 1, 2, 3, 4, 5, 6, 7);
}

void habitoGeral(){			//lógica p0r traz da função de criar hábitos.
	system("cls");
	printf("\n Criando Habito...\n-------------------------------------------\n Categoria: %s\n\n", Habitos[x].nomeCategoria);
	printf(" Nome do Habito: ");
	scanf("%30[^\n]s", &Habitos[x].nomehabito);		//registro da string de Nome do Habito na struct.
	fflush(stdin);									//controla o buffer do teclado/estouro de pilha.
	printf("\n Duracao (em dias): ");
	scanf("%d", &Habitos[x].duracao);				//registro do número int de duração na struct.
	fflush(stdin);									//controla o buffer do teclado/estouro de pilha.
	printf("\n Descricao: ");
	scanf("%500[^\n]s", &Habitos[x].descricao);		//registro da string de descrição na struct.
	fflush(stdin);									//controla o buffer do teclado/estouro de pilha.
	Habitos[x].faltaDias = Habitos[x].duracao;
	
	if(histCont < maxHistorico){										//lógica para add os hábitos no histórico.
		strcpy(Hist[histCont].nomeCategoria, Habitos[x].nomeCategoria);	//
		strcpy(Hist[histCont].nomeHabito, Habitos[x].nomehabito);		//
		Hist[histCont].duracao = Habitos[x].duracao;					//
		strcpy(Hist[histCont].descricao, Habitos[x].descricao);			//
		Hist[histCont].faltaDias = Habitos[x].duracao;					//
	}																	//
	histCont++;															//////
	
	system("cls");																					//Apresentação final do Habito Criado.
	printf("\n Habito Criado com Sucesso!\n-------------------------------------------\n");			//
	printf(" Categoria: %s\n\n", Habitos[x].nomeCategoria);											//
	printf(" Nome do Habito: %s\n\n", Habitos[x].nomehabito);										//
	printf(" Duracao: %d\n\n", Habitos[x].duracao);													//
	printf(" Descricao: %s\n-------------------------------------------\n", Habitos[x].descricao);	//////
	x++;				//logica para sempre criar um novo hábito na próxima vez.
	habitoCont++;
	sleep(3);				//pausa o programa por alguns segundos.
	system(" pause");		//pausa o programa até que o usuário digite qualquer tecla.
	menuPrincipal();		//função de menu Principal.
}