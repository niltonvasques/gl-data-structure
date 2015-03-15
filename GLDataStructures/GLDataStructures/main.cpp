/*-----------------------------------------------------------------------------
  Universidade Católica do Salvador - UCSAL
  Disciplina - Organização de Arquivos
  Aluno - Nilton Vasques Carvalho Junior
Autor: Nilton Vasques
Data do ínicio da implementação: 20/04/2011
Data da última modificação: 16/05/2011

Implementação das representações gráfica das estruturas de dados para facilitar
a didática na aprendizagem das mesmas.
-----------------------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "main_control.h"
#include "keycodes.h"

using namespace std;

void menu();
void help();

int _argc;
char ** _argv;

int main(int argc, char** argv){
  _argc = argc;
  _argv =  argv;
  menu();
  return 0;
}


void menu(){
  printf(">>BEM VINDO AO PROGRAMA GL_DATA_STRUCTURES<<\n");
  printf("\n");
  printf("--    MENU    --\n\n\n");
  printf("1 - Stacks (Pilhas)\n\n");
  printf("2 - Queues (Filas)\n\n");
  printf("3 - Ajuda \n\n");
  printf("4 - Sair\n");
  char ch;
  do{
    ch = getchar();
    switch(ch){
      case KEY_KEY_1:
        stackStartControl();
        break;
      case '2':
        queueStartControl();
        break;
      case '3':
        help();
        break;
      case KEY_ESCAPE:
      case KEY_KEY_4:
        return;
      default:
        break;
    }
  }while(ch != KEY_KEY_4 && ch != KEY_KEY_3 && ch != KEY_KEY_2 && ch != KEY_KEY_1 && ch != KEY_ESCAPE);
  initGlut(_argc, _argv);
}

void help(){
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
  system("CLS");
#endif
  printf("------- AJUDA --------\n\n");
  printf(" Para inserir um novo elemento na estrutura pressione ( 1 ). \n\n");
  printf(" Para remover um elemento da estrutura pressione ( 2 ). \n\n");
  printf(" Para alternar entre os tipos de estruturas pressione ( TAB ). \n\n");
  printf(" Para pausar ou executar a exibição pressione a tecla ( P ). \n\n");
  printf(" Para encerrar a simulacao pressione ( ESC ). \n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf(" Pressione qualquer tecla para voltar ao menu principal... \n\n");
  getchar();
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
  system("CLS");
#endif
  menu();
}
