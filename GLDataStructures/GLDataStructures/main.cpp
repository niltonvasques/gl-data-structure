#include <iostream>
#include <conio.h>
#include <time.h>
#include "main_control.h"

using namespace std;

void menu();
void help();

int main(int argc, const char* argv[]){
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
		ch = _getch();
		switch(ch){
			case '1':
				stackStartControl();
				break;
			case '2':
				queueStartControl();
				break;
			case '3':
				help();
				break;
			case '4':
				exit(0);
				break;
			default:
				break;
		}
	}while(ch != '4' && ch != '3' && ch != '2' && ch != '1');


}

void help(){
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
	system("CLS");
#endif
	printf("------- AJUDA --------\n\n");
	printf(" Para inserir um novo elemento na estrutura pressione ( 1 ) \n");
	printf(" Para remover um elemento da estrutura pressione ( 2 ) \n");
	printf(" Para encerrar a simulacao pressione ( ESC ) \n");
	_getch();
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
	system("CLS");
#endif
	menu();
}