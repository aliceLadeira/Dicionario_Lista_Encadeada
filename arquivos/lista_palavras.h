#include "TPalavra.h"

typedef struct CelulaP* ApontadorP;

typedef struct CelulaP{
	TipoPalavra Palavra;
	struct CelulaP *ptr_prox;
}TipoCelulaPalavra;

typedef struct 
{
	ApontadorP ptr_primeiro;
	ApontadorP ptr_ultimo;		
}TipoListaPalavras;

void cria_lista_palavras(TipoListaPalavras *ptr_lista);
int lista_eh_vazia(TipoListaPalavras *ptr_lista);
void insere_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra);
int verifica_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra);
int remove_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra, TipoPalavra *ptr_palavra_retirada);
int remove_palavra_final(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra_retirada);
int numero_palavras(TipoListaPalavras *ptr_lista);
void imprime_lista_palavras(TipoListaPalavras *ptr_lista);