#include <stdio.h>			//bibliotecas importadas.
#include <string.h>			//
#include <stdlib.h>			//
#include <unistd.h>			//
#include <locale.h>			//
#include <time.h>			//
#include "main.h"			//
#include "criarHabito.h"	////
#define maxHistorico 50

struct historico{						//declaração da struct de historico já existente.
    char nomeCategoria[30];				//
    char nomeHabito[30];				//
    int duracao;						//
    char descricao[500];				//
    int marcacaoDiaria;					//
    int faltaDias;						//
    float concluindo;					//
};										//
										//
struct historico Hist[maxHistorico];	///////

struct habito{				//declaração da struct de Habitos já existente.
  char nomeCategoria[30];	//
  char nomehabito[30];		//
  int duracao;				//
  char descricao[500];		//
  int marcacaoDiaria;		//
  int faltaDias;			//
  float concluindo;			//
};							//
							//
struct habito Habitos[10];	//////

void marcacaoDiaria();	//Declaração das funções usadas nesse arquivo.
void excluirHabito();	//

void verHabito(){	//função principal de ver Habito.
	int escolha;
	
	if(habitoCont == 0){
		do{
			printf("\n Seus Habitos...\n-------------------------------------------\n");
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
		do{	//loop para garantir q o usuário digite uma opção valida.
			printf("\n Seus Habitos...\n-------------------------------------------\n");
			for(y = 0; y < x; y++){		//v lógica para apresentar todos os hábitos existentes dentro do parametro da struct de Habitos.
				if(strcmp(Habitos[y].nomeCategoria, "") != 0 || strcmp(Habitos[y].nomehabito, "") != 0 || Habitos[y].duracao != 0){
					printf(" Categoria: %s\n", Habitos[y].nomeCategoria);
					printf(" Habito: %s		%2.1f o/o Concluido\n", Habitos[y].nomehabito, Habitos[y].concluindo);
					printf(" Duracao(em dias): %d		Falta: %d\n", Habitos[y].duracao, Habitos[y].faltaDias);
					printf(" Descricao: %s\n\n", Habitos[y].descricao);
				}
			}				//v apresentação das funcionalidade possivéis nessa tela.
			printf("-------------------------------------------\n 1 - Marcacao Diaria\n\n 2 - Excluir Habito\n\n 3 - Voltar\n\n >> ");
			scanf("%d", &escolha); //registro da escolha do usuario.
			fflush(stdin);		//controla o buffer do teclado/estouro de pilha.
	
			switch(escolha){	//comando para saber qual funcionalidade o usuário escolheu.
				case(1):				//opção caso o usuário queira fazer a marcação diária de um hábito.
					system("cls");		//limpa tela.
					marcacaoDiaria();	//função de Marcação Diária.
				break;
			
				case(2):			//opção caso o usuário queira excluir algum hábito.
					system("cls");		//limpa tela.
					excluirHabito();	//função de excluir hábito.
				break;
			
				case(3):			//opção caso o usuário queira voltar para a tela/menu principal.
					system("cls");		//limpa tela.
					menuPrincipal();	//função de menu Principal.
				break;
			
				default:		//opção caso o usuário digite um número invalido.
					system("cls");	//limpa tela.
					printf("\n ERRO! opcao invalida (%d).", escolha);
					sleep(3);	//pausa temporária do programa.
			}
		}while(escolha != 1, 2, 3);		//fim do loop.
	}
}

void marcacaoDiaria() {	//função de Marcação Diária.
    int escolha, i;

    do{		//inicio do loop para garantir que o usuário digite uma opção valida.
        system("cls");
        printf("\n Qual voce deseja fazer a marcacao?\n-------------------------------------------\n");
        for (y = 0; y < x; y++){		//v lógica para apresentar todos os hábitos existentes dentro do parametro da struct de Habitos.
            if (strcmp(Habitos[y].nomeCategoria, "") != 0 || strcmp(Habitos[y].nomehabito, "") != 0 || Habitos[y].duracao != 0){
                printf("%d - Categoria: %s\n", y + 1, Habitos[y].nomeCategoria);
                printf("    Habito: %s		%2.1f o/o Concluido\n", Habitos[y].nomehabito, Habitos[y].concluindo);
                printf("    Duracao(em dias): %d		Falta: %d\n", Habitos[y].duracao, Habitos[y].faltaDias);
                printf("    Descricao: %s\n\n", Habitos[y].descricao);
            }
        }			//v apresentação das funcionalidade possivéis nessa tela.
        printf("0 - Voltar\n-------------------------------------------\n >> ");
        scanf("%d", &escolha);		//registro da escolha do usuario.
        fflush(stdin);			//controla o buffer do teclado/estouro de pilha.

        if (escolha >= 1 && escolha <= x){	//logica para reconhecer qual habito foi selecionado.
            int numHabito = escolha - 1;	//
            int numHistorico = numHabito;
            
            system("cls");	//limpa tela.
            printf("\n Marcacao em Processamento...\n\n");
            for (i = 0; i <= 5; i++){		//tela de carregamento(MERAMENTE ILUSTRATIVO 0_0).
                printf(" o");				//
                sleep(1);					//
            }								//////
                
            Habitos[numHabito].marcacaoDiaria++;	//variavel que vai registrar as marcações diárias do hábito.
            Habitos[numHabito].faltaDias--;
            Habitos[numHabito].concluindo = Habitos[numHabito].concluindo + ((1.0 / Habitos[numHabito].duracao) * 100);

            if (Habitos[numHabito].marcacaoDiaria == Habitos[numHabito].duracao){		//logica para caso o hábito tenha sido concluido.
                for (i = numHabito; i < x - 1; i++){									//
                    strcpy(Habitos[i].nomeCategoria, Habitos[i + 1].nomeCategoria);		//
                    strcpy(Habitos[i].nomehabito, Habitos[i + 1].nomehabito);			//
                    Habitos[i].duracao = Habitos[i + 1].duracao;						//
                    strcpy(Habitos[i].descricao, Habitos[i + 1].descricao);				//
                    Habitos[i].marcacaoDiaria = Habitos[i + 1].marcacaoDiaria;			//
                    Habitos[i].faltaDias = Habitos[i + 1].faltaDias;					//
                    Habitos[i].concluindo = Habitos[i + 1].concluindo;					//
                }																		//
                x--;																	//
                Hist[numHistorico].faltaDias = 0;			//
				Hist[numHistorico].concluindo = 0.0;			//
																						//
                system("cls");		//limpa tela.										//
                printf("\n Parabens! Voce concluiu o seu habito.\n\n");					//
                system("pause");	//pausa o programa até o usuário digitar qualquer tecla.		
                system("cls");		//limpa tela.										//
                verHabito();	//função de ver hábito.									//////
            } else {
        
                Hist[numHistorico].faltaDias = Habitos[numHabito].faltaDias;
				Hist[numHistorico].concluindo = Habitos[numHabito].concluindo;
				system("cls");		//limpa tela.
                printf("\n Marcacao Diaria realizada com sucesso.\n\n");
                system("pause");	//pausa o programa até o usuário digitar qualquer tecla.
                system("cls");		//limpa tela.
                verHabito();	//função de ver Habitos.
            }

        } else {

            if (escolha == 0){	//opção caso o usuário queira voltar para a tela de ver Habitos.
                system("cls");	//limpa tela.
                verHabito();	//função de ver Habitos.

            } else {

                if (escolha != 0){	//opção caso o usuárioo digite um número errado.
                    system("cls");	//limpa tela.
                    printf("\n ERRO! Opcao Invalida (%d).", escolha);
                    sleep(3);	//pausa temporária do programa.
                }
            }
        }
    } while (escolha != 0);		//fim do loop.
}

void excluirHabito(){	//função de excluir hábito.
	int escolha, i;
	
	do{		//inicio do loop para garantir que o usuário digite uma opção valida.
		system("cls");	//limpa tela.
        printf("\n Qual Habito voce deseja excluir?\n-------------------------------------------\n");
        for (y = 0; y < x; y++){	//v lógica para apresentar todos os hábitos existentes dentro do parametro da struct de Habitos.
            if (strcmp(Habitos[y].nomeCategoria, "") != 0 || strcmp(Habitos[y].nomehabito, "") != 0 || Habitos[y].duracao != 0) {
                printf("%d - Categoria: %s\n", y + 1, Habitos[y].nomeCategoria);
                printf("    Habito: %s		%2.1f o/o Concluido\n", Habitos[y].nomehabito, Habitos[y].concluindo);
                printf("    Duracao(em dias): %d		Falta: %d\n", Habitos[y].duracao, Habitos[y].faltaDias);
                printf("    Descricao: %s\n\n", Habitos[y].descricao);
            }
        }				//v apresentação das funcionalidade possivéis nessa tela.
        printf("0 - Voltar\n-------------------------------------------\n >> ");
        scanf("%d", &escolha);		//registro da escolha do usuario.
        fflush(stdin);				//controla o buffer do teclado/estouro de pilha.
        
        if(escolha >= 1 && escolha <= x){
        	int numHabito = escolha - 1;
        	
        	system("cls");
        	printf("\n Excluindo Habito...\n\n");
        	for(i = 0; i <= 5; i++){	//tela de carregamento(MERAMENTE ILUSTRATIVO 0_0).
        		printf(" o");			//
        		sleep(1);				//
			}							//
			
			for(i = numHabito; i < x - 1; i++){									//lógica para excluir o hábito.
				strcpy(Habitos[i].nomeCategoria, Habitos[i + 1].nomeCategoria);	//
				strcpy(Habitos[i].nomehabito, Habitos[i + 1].nomehabito);		//
				Habitos[i].duracao = Habitos[i + 1].duracao;					//
				strcpy(Habitos[i].descricao, Habitos[i + 1].descricao);			//
				Habitos[i].marcacaoDiaria = Habitos[i + 1].marcacaoDiaria;		//
				Habitos[i].faltaDias = Habitos[i + 1].faltaDias;				//
                Habitos[i].concluindo = Habitos[i + 1].concluindo;				//
			}																	//
			x--;																///////
																		
			system("cls");	//limpa tela.
			printf("\n Habito excluido com sucesso!\n\n");
			system("pause");	//pausa o programa até que o usuário digite alguma tecla.
			system("cls");	//limpa tela.
			verHabito();	//função de ver Habito.
			
		}else{
			
			if(escolha == 0){	//opção caso o usuário queiro voltar para a tela de ver Habito.
				system("cls");	//limpa tela.
				verHabito();	//função de ver Habito.
				
			}else{
				
				if(escolha != 0){	//opção caso o usuário digite algum número errado.
					system("cls");	//limpa tela.
					printf("\n ERRO! Opcao Invalida (%d).", escolha);
					sleep(3);		//pausa temporária do programa.
				}
			}
		}
	}while(escolha != 0);	//fim do loop.
}
