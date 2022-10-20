#include "TListaDeLinhas.h"

typedef struct {
	//char* nomePalavra[47];
	char nomePalavra[47];
	TipoListaDeLinhas lista;
} TipoPalavra;

void cria_palavra(TipoPalavra* ptrPalavra,TipoListaDeLinhas* ptrLista, TItem* ptrItem);

//void nomeia_palavra(TipoPalavra* ptrPalavra, char* nome);
void nomeia_palavra(TipoPalavra* ptrPalavra, char* nome);

//char* get_Palavra(TipoPalavra *ptrPalavra);
char* get_Palavra(TipoPalavra *ptrPalavra);

void imprime_TipoPalavra(TipoPalavra* ptrPalavra);