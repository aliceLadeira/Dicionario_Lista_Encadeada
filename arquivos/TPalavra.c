#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TPalavra.h"

void cria_palavra(TipoPalavra* ptrPalavra,TipoListaDeLinhas* ptrLista, TItem* ptrItem)
{
	faz_lista_de_linhas_vazia(ptrLista);
	insere_linha_na_lista(ptrLista, ptrItem);
	ptrPalavra->lista = *ptrLista;
}

/*
void nomeia_palavra(TipoPalavra* ptrPalavra, char* nome)
{
	strcpy(*ptrPalavra->nomePalavra, nome);
}
*/
void nomeia_palavra(TipoPalavra* ptrPalavra, char* nome)
{
	strcpy(ptrPalavra->nomePalavra, nome);
}
/*
char* get_Palavra(TipoPalavra *ptrPalavra)
{
	return *ptrPalavra->nomePalavra;
}
*/
char* get_Palavra(TipoPalavra *ptrPalavra)
{
	return ptrPalavra->nomePalavra;
}

void imprime_palavra(TipoPalavra* ptrPalavra)
{
	printf("%s", get_Palavra(ptrPalavra));
}

void imprime_TipoPalavra(TipoPalavra* ptrPalavra)
{
	printf("--------------------------------------\n");
	printf("Palavra: ");
	printf("%s\n", get_Palavra(ptrPalavra));
//	printf("%d\n", ptrPalavra->lista->ptrPrimeiro->Item.linha);
	imprime_lista_de_linhas(&ptrPalavra->lista);
}