#include <stdio.h>
#include <stdlib.h>

/** ===================================

            Constantes

====================================== */

#define TAM_NOME_COL 100
#define TAM_NOME_TAB 100

// SGBD's suportados pela ferramenta
#define SGBD_MYSQL 1

// Tipos de dados do MySQL
#define MYSQL_VARCHAR 1
#define MYSQL_INT 2
#define MYSQL_CHAR 3

// Tipos de dados da linguagem C
#define C_CHAR 1
#define C_INT 2

/** ===================================

            Structs

====================================== */

typedef struct Coluna Coluna;
typedef struct Tabela Tabela;
typedef struct DataType DataType;
typedef struct ConstraintFK ConstraintFK;
typedef struct ConstraintPK ConstraintPK;

struct DataType{
    short SGBD;
    short tipo;//tipo em c. char, int, short...
};

struct ConstraintFK{
    Tabela *tabelaReferenciada;
    Coluna *colunaReferenciada;
};

struct ConstraintPK{
    int incrementoInicial;
    int incremento;
};

struct Coluna{
    char nome[TAM_NOME_COL];
    ConstraintFK *constraintFK;
    ConstraintPK *constraintPK;
    DataType tipo;
    double tamanho;
    Coluna * prox;
};

struct Tabela{
    char nome[TAM_NOME_TAB];
    Coluna * colunas;
};

/** ===================================

            Variáveis globais

====================================== */

Coluna * listaDeColunas = NULL;

/** ======================================

    Funções para manipulação da tabela

========================================= */

Coluna* criarColuna() {
    return (Coluna*) malloc(sizeof(Coluna));
}

DataType * criarDataType(int sgbd, int tipo){
    switch(sgbd){
	case SGBD_MYSQL:
		return criarDataTypeMySQL(tipo);
		break;
    }
}

DataType* criarDataTypeMySQL(int sgbd){
    DataType *dataType = (DataType*) malloc(sizeof(DataType));
    dataType->SGBD = sgbd;
    
    switch(tipo){
        case MYSQL_CHAR:
            dataType->tipo = C_CHAR;
            break;

        case MYSQL_INT:
            dataType->tipo = C_INT;
            break;

        case MYSQL_VARCHAR:
            dataType->tipo = C_CHAR;
            break;
    }

    return dataType;
}

/*
	Insere coluna no final da lista dinâmica
*/
void inserirColuna() {
    char addcol[50];
    char *tipo;
    char addtipo;
    int i, cont;
    Coluna *colunaAux, *novo;

    printf ("\nPrimeira coluna eh primary key, number e randomica.\n\n");

	printf ("Digite o nome da coluna: ");
	scanf ("%s", &addcol);
	printf ("Digite V para continuar.");
//        fflush(stdio);
	scanf ("%s", &tipo);

	novo = (Coluna*)malloc(sizeof(Coluna));
	memcpy(novo->nome, addcol, 50);
    novo->tipo = criarDataType(SGBD_MYSQL, MYSQL_CHAR);

	novo -> prox = NULL;
	if(listaDeColunas == NULL){
		listaDeColunas = novo;
	} else {
		colunaAux = listaDeColunas;
		while (colunaAux -> prox != NULL) colunaAux = colunaAux->prox;
		colunaAux -> prox = novo;
	}
}

void primarykey(void){
    fprintf(stdout, "\nPRIMARY KEY (%s)\n);\n\n", listaDeColunas->nome);
    getchar();
}

void gerarCreateTable(){
	Coluna *colunaAux;
	aux = listaDeColunas;
	while (colunaAux != NULL){
		printf ("\n %s varchar2,", aux -> nome);
		colunaAux = colunaAux->prox;
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

