#include <stdio.h>
#include <stdlib.h>
#include "lista_palavras.h"

typedef struct CelulaDicionario* ApontadorDicionario;

typedef struct CelulaDicionario {
    TipoListaPalavras ListaPalavras;
    struct CelulaDicionario* ptr_proximo;
} TipoCelulaDicionario;

typedef struct {
    ApontadorDicionario ptr_primeirodicionario;
    ApontadorDicionario ptr_ultimodicionario;
} TipoDicionario;

void inicializa_dicionario(TipoDicionario *ptr_dicionario);
int dicionario_ehvazio(TipoDicionario* ptr_listas);
void insere_lista(TipoDicionario *ptr_dicionario, TipoListaPalavras *ptr_lista);

void constroi_dicionario(FILE *texto, TipoDicionario* dicionario);

//void exibe_listadepalavras(TipoDicionario *ptr_dicionario, char letra_inicial);
void imprime_dicionario(TipoDicionario *ptr_dicionario);
