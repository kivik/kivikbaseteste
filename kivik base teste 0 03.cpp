#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h> 

void exibirCabecalho(){
	printf ("kivik base teste versao 1.0 - MySQL\n");
	printf ("Desenvolvido por: Alam Maia da Silva Vianna\n");
	printf ("Colaboradores: antoniomquadrosfilho\n");
	printf ("Colaboradores: IRC, servidor RIZON, canal #gold_code\n\n\n");
}

	void cls();

main (void) {
	
	struct col{
    char nome[50];
    char tipo;
    int nucolna;
    col *prox;
}*listaDeColunas;

	char tabela[50];
	int qtdColunas=0;
	int cont;
	int i, quant_dados;
	char addcol[50];
    char *tipo;
    char addtipo;
  //  int i, cont; /*retirado na retirada das fun��es*/
    col *aux, *novo;
	
	srand(time(NULL));

	exibirCabecalho();
	
	printf ("Nome da tabela: ");
	scanf ("%s", &tabela);
	
// cria lista vazia
    listaDeColunas = NULL;
    printf ("\nColunas prontas para serem inseridas");

	printf ("\n\nInserir numero de colunas: ");
	scanf ("%d", &qtdColunas);
	
	printf ("\nPrimeira coluna eh primary key, number e randomica.\n\n"); 
	
	for (cont=0; cont<qtdColunas; cont++){
    //col *aux, *novo;

	printf ("Digite o nome da coluna: ");
	scanf ("%s", &addcol);
	printf ("insira alguma variavel do tipo char: ");
//        fflush(stdio);
	scanf ("%s", &tipo);

	novo = (col*)malloc(sizeof(col));
	memcpy(novo->nome, addcol, 50);
	novo->tipo = getchar();

	novo -> prox = NULL;
	if(listaDeColunas == NULL){
		listaDeColunas = novo;
	} else {
		aux = listaDeColunas;
		while (aux -> prox != NULL) aux = aux->prox;
		aux -> prox = novo;
	} 
	
	}
	
		cls();
	
	exibirCabecalho();
	
	printf ("\ncreate table %s (", tabela);
	
	//col *aux; 
	aux = listaDeColunas;
	while (aux != NULL){
		printf ("\n %s varchar2,", aux -> nome);
		aux = aux -> prox;
	}
	
	fprintf(stdout, "\nPRIMARY KEY (%s)\n);\n\n", listaDeColunas->nome);
	
	printf ("//insira quantidade de dados a serem criados: ");
	scanf ("%d", &quant_dados);
	
	for (i=quant_dados; i>=1; i--)
	{
	
	printf ("\ninsert into %s (", tabela);
	
//	col *aux; 
	aux = listaDeColunas;

		while (aux != NULL){
			if(aux -> prox == NULL){
				printf ("%s) VALUES ( %d, ", aux -> nome, i );
			}else{
				printf ("%s,", aux -> nome );      
			}
			aux = aux -> prox;
		}
	}
	
	 getch();
	return 0;
}


void cls() 
{ 
 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 
 CONSOLE_SCREEN_BUFFER_INFO info; 
 GetConsoleScreenBufferInfo( hCon, &info ); 
 
 COORD home = { 0, 0 }; 
 DWORD nchars = (DWORD)info.dwSize.X * info.dwSize.Y; 
 DWORD nwritten; 
 
 // Fill the entire screen with blanks. 
 
 FillConsoleOutputCharacter( hCon, ' ', nchars, home, &nwritten ); 
 FillConsoleOutputAttribute( hCon, info.wAttributes, nchars, home, &nwritten); 
 
 SetConsoleCursorPosition( hCon, home ); 
} 
