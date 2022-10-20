#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_palavras.h"

void cria_lista_palavras(TipoListaPalavras *ptr_lista){
	ptr_lista->ptr_primeiro = (ApontadorP) malloc(sizeof(TipoCelulaPalavra));
	ptr_lista->ptr_ultimo = ptr_lista->ptr_primeiro;
	ptr_lista->ptr_primeiro->ptr_prox = NULL;
}

int lista_eh_vazia(TipoListaPalavras *ptr_lista){
	//printf("Lista eh vazia.\n");
	return (ptr_lista->ptr_primeiro == ptr_lista->ptr_ultimo);
}

void insere_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra){
	ptr_lista->ptr_ultimo->ptr_prox = (ApontadorP) malloc(sizeof(TipoCelulaPalavra));
	ptr_lista->ptr_ultimo = ptr_lista->ptr_ultimo->ptr_prox;
	ptr_lista->ptr_ultimo->Palavra = *ptr_palavra;
	ptr_lista->ptr_ultimo->ptr_prox = NULL;
}

int verifica_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra){
	if (lista_eh_vazia(ptr_lista)){
 		//printf("A palavra %s nao esta na lista, porque a lista eh vazia.. \n", ptr_palavra->nomePalavra);
 		return 0;
 	}
 	ApontadorP ptr_aux;
	ptr_aux = ptr_lista->ptr_primeiro->ptr_prox;
	char guarda_palavra1[47];
	char guarda_palavra2[47];
 	while(1){
 		if(ptr_aux == NULL){
 			//printf("A palavra %s nao esta na lista. \n", ptr_palavra->nomePalavra);
 			return 0;
 		}

 		strcpy(guarda_palavra1, ((ptr_aux->Palavra).nomePalavra));
 		strcpy(guarda_palavra2, (ptr_palavra->nomePalavra));


 		//if(guarda_palavra1 == guarda_palavra2){
 		if (strcmp(guarda_palavra1, guarda_palavra2) == 0){
 			if(ptr_aux->Palavra.lista.ptrUltimo->Item.linha != ptr_palavra->lista.ptrUltimo->Item.linha)
 				insere_linha_na_lista(&ptr_aux->Palavra.lista, &ptr_palavra->lista.ptrUltimo->Item);
 			return 1;
 		}

 		ptr_aux = ptr_aux->ptr_prox;
 	}
}

int remove_palavra(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra, TipoPalavra *ptr_palavra_retirada){
	if (lista_eh_vazia(ptr_lista))
 		return 0;
 	if(verifica_palavra(ptr_lista, ptr_palavra)){
 		ApontadorP ptr_aux1;
 		ApontadorP ptr_aux2;
	 	*ptr_palavra_retirada = *ptr_palavra;
	 	ptr_aux1 = ptr_lista->ptr_primeiro->ptr_prox;
	 	ptr_aux2 = ptr_lista->ptr_primeiro;
	 	char guarda_palavra1[47];
		char guarda_palavra2[47];
		strcpy(guarda_palavra1, (ptr_aux1->Palavra).nomePalavra);
		strcpy(guarda_palavra2, ptr_palavra->nomePalavra);
	 	while (1){
	 		//if(guarda_palavra1 != guarda_palavra2)
	 		if(strcmp(guarda_palavra1, guarda_palavra2) != 0)
	 		{
	 			ptr_aux2 = ptr_aux1;
	 			ptr_aux1 = ptr_aux1->ptr_prox;
	 			strcpy(guarda_palavra1, (ptr_aux1->Palavra).nomePalavra);
	 		}
	 		else{
	 			if(ptr_aux1->ptr_prox == NULL){
	 				ptr_lista->ptr_ultimo = ptr_aux2; 
	 			}
	 			ptr_aux2->ptr_prox = ptr_aux1->ptr_prox;
	 			free(ptr_aux1);
	 			break;
	 		}
	 	}
	 	return 1;
	 }
}

int remove_palavra_final(TipoListaPalavras *ptr_lista, TipoPalavra *ptr_palavra_retirada){
	ApontadorP ptr_aux1;
	ApontadorP ptr_aux2;
 	if (lista_eh_vazia(ptr_lista))
 		return 0;
 	*ptr_palavra_retirada = ptr_lista->ptr_ultimo->Palavra;
 	ptr_aux1 = ptr_lista->ptr_primeiro->ptr_prox;
 	ptr_aux2 = ptr_lista->ptr_primeiro;
 	while (ptr_aux1 != ptr_lista->ptr_ultimo){
 		ptr_aux2 = ptr_aux2->ptr_prox;
 		ptr_aux1 = ptr_aux1->ptr_prox;
 	}	
 	ptr_lista->ptr_ultimo = ptr_aux2;
 	ptr_lista->ptr_ultimo->ptr_prox = NULL;
 	free(ptr_aux1);
 	return 1;
}


int numero_palavras(TipoListaPalavras *ptr_lista){
	if (lista_eh_vazia(ptr_lista)){
 		return 0;
 	}
 	ApontadorP ptr_aux;
 	int cont = 0;
	ptr_aux = ptr_lista->ptr_primeiro->ptr_prox;
	while(1){
		if(ptr_aux == NULL){
			return cont;
		}
		cont++;
		ptr_aux = ptr_aux->ptr_prox;
	}	
}

void imprime_lista_palavras(TipoListaPalavras *ptr_lista){
	ApontadorP ptr_aux;
 	ptr_aux = ptr_lista->ptr_primeiro->ptr_prox;
 	while (ptr_aux != NULL){
 		imprime_TipoPalavra(&ptr_aux->Palavra);
 		ptr_aux = ptr_aux->ptr_prox;
 	}	
}