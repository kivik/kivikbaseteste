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
	
	printf ("Nome da tabela: "); // vers�es futuras numero de tabelas ser� aleat�rio
	scanf ("%s", &tabela);
	
// cria lista vazia
    listaDeColunas = NULL;
    printf ("\nColunas prontas para serem inseridas");

	printf ("\n\nDigite 10 para gerar 10 colunas: "); // vers�es futuras numero de colunas ser� aleat�rio
	scanf ("%d", &qtdColunas);
	
	printf ("\nPrimeira coluna eh primary key.\n\n"); 
	
	for (cont=0; cont<qtdColunas; cont++){
    //col *aux, *novo;

	printf ("Digite o nome da coluna: "); // vers�es futuras nome da coluna ser� gerado randomicamente
	scanf ("%s", &addcol);
	printf ("insira alguma variavel do tipo char: "); // vers�es futuras poder� escolher tipo da variavel nesse momento
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
	
	/*


fprintf(fp, "texto que vai ser salvo\n");


	*/
	FILE *fp = fopen("kivik.txt", "a+");
	
	if (fp) {
	
	fprintf (fp, "\ncreate table %s (", tabela);
	
	//col *aux; 
	aux = listaDeColunas;
	while (aux != NULL){
		fprintf (fp, "\n %s varchar2,", aux -> nome); // vers�es futuras criar cases para tipo de variavel (recomendavel aqui)
		aux = aux -> prox;
	}
	
	fprintf(fp, "\nPRIMARY KEY (%s)\n);\n\n", listaDeColunas->nome);
	
	printf ( "insira quantidade de dados a serem criados: ");
	scanf ("%d", &quant_dados);
	
	for (i=quant_dados; i>=1; i--)
	{
	
	fprintf (fp, "\ninsert into %s (", tabela);
	
//	col *aux; 
	aux = listaDeColunas;

		while (aux != NULL){
			if(aux -> prox == NULL){
				fprintf (fp, "%s) VALUES ( %d, 'kivik%d', 'kivik%d', '%dkivik', 'kivik%d', '%dkivik', 'kivik%d', '%dkivik', 'kivik%d', '%dkivik');"
				, aux -> nome, i, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000, rand() % 2000);
			}else{
				fprintf (fp, "%s,", aux -> nome );      
			}
			aux = aux -> prox;
		}
	}
	fclose(fp);
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
