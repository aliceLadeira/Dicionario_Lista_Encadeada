#include "TItem.h"

typedef struct Celula* Apontador;

typedef struct Celula {
	TItem Item;
	struct Celula* ptrProx;
} TipoCelula;

typedef struct {
	struct Celula* ptrPrimeiro;
	struct Celula* ptrUltimo;
} TipoListaDeLinhas;

void faz_lista_de_linhas_vazia(TipoListaDeLinhas* ptrLista);

void insere_linha_na_lista(TipoListaDeLinhas* ptrLista, TItem* ptrItem);

void imprime_lista_de_linhas(TipoListaDeLinhas* ptrLista);