#include <stdio.h>
#include <stdlib.h>
#include "TListaDeLinhas.h"

void faz_lista_de_linhas_vazia(TipoListaDeLinhas* ptrLista)
{
	ptrLista->ptrPrimeiro = (Apontador) malloc(sizeof(TipoCelula));
	ptrLista->ptrUltimo = ptrLista->ptrPrimeiro;
	ptrLista->ptrPrimeiro->ptrProx = NULL;
}

void insere_linha_na_lista(TipoListaDeLinhas* ptrLista, TItem* ptrItem)
{
	ptrLista->ptrUltimo->ptrProx = (Apontador) malloc(sizeof(TipoCelula));
	ptrLista->ptrUltimo = ptrLista->ptrUltimo->ptrProx;
	ptrLista->ptrUltimo->Item = *ptrItem;
	ptrLista->ptrUltimo->ptrProx = NULL;
}

void imprime_lista_de_linhas(TipoListaDeLinhas* ptrLista)
{
	Apontador ptrAux;
	ptrAux = ptrLista->ptrPrimeiro->ptrProx;
	printf("Linha:  ");
	printf("|");
	while(ptrAux != NULL)
	{
		printf("%d|", ptrAux->Item.linha);
		
		ptrAux = ptrAux->ptrProx;
	}
	printf("\n");
	printf("--------------------------------------\n");
}