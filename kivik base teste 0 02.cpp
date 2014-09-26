#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
     
struct col{
    char nome[50];
    char tipo;
    int nucolna;
    col *prox;
}*listaDeColunas;
 
void criarListaDeColunas() { // cria lista vazia
    listaDeColunas = NULL;
    printf ("\nColunas prontas para serem inseridas");
    getch();
}

/*
	Insere coluna no final da lista dinâmica
*/
void inserirColuna() {
    char addcol[50];
    char *tipo;
    char addtipo;
    int i, cont;
    col *aux, *novo;

    printf ("\nPrimeira coluna eh primary key, number e randomica.\n\n");   

	printf ("Digite o nome da coluna: ");
	scanf ("%s", &addcol);
	printf ("Digite V para continuar.");
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
    
void primarykey(void){
    fprintf(stdout, "\nPRIMARY KEY (%s)\n);\n\n", listaDeColunas->nome);
    getchar();
} 

void gerarCreateTable(){
	col *aux; 
	aux = listaDeColunas;
	while (aux != NULL){
		printf ("\n %s varchar2,", aux -> nome);
		aux = aux -> prox;
	}
	getch();
}

void exibirCabecalho(){
	printf ("kivik base teste versao 1.0 - MySQL\n");
	printf ("Desenvolvido por: Alam Maia da Silva Vianna\n");
	printf ("Colaboradores: antoniomquadrosfilho\n");
	printf ("IRC, servidor RIZON, canal #gold_code\n\n\n");
}

void gerarInserts(){
	col *aux; 
	aux = listaDeColunas;

	while (aux != NULL){
		if(aux -> prox == NULL){
			printf ("%s)", aux -> nome );
		}else{
			printf ("%s,", aux -> nome );      
		}
		aux = aux -> prox;
	}
	getch();
}

void cls();

int main () {
	char tabela[50];
	int qtdColunas=0;
	
	exibirCabecalho();
	
	printf ("Nome da tabela: ");
	scanf ("%s", &tabela);
		
	criarListaDeColunas();
	
	printf ("\n\nInserir numero de colunas: ");
	scanf ("%d", &qtdColunas);
	
	for (cont=0; cont<qtdColunas; cont++){
		inserirColuna();
	}
	
	cls();
	
	exibirCabecalho();

	printf ("\ncreate table %s (", tabela);

	gerarCreateTable();
	primarykey();
	
	printf ("insert into %s (", tabela);
	gerarInserts();
		
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

