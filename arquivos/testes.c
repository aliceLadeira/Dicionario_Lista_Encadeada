#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

TipoListaPalavras* retorna_lista_certa(TipoDicionario* dicionario, char letra);

TipoPalavra* encontra_palavra(TipoListaPalavras* ptrLista, char* nomeDaPalavra);

 int main()
{
	
	printf("**************************************************************\n");
	printf("*************************| DICIONARIO |***********************\n");
	printf("**************************************************************\n");
	
	int confere = 0;
	int op;
	while (op != -1)
	{
	char umaPalavra[47], nomeArqTexto[50], le;
	int umaLinha;
	TItem umItem;
	TipoListaDeLinhas umaListaLinhas;
	TipoPalavra umaTPalavra;
	TipoDicionario dicionario;
	TipoListaPalavras umaListaPalavras;
	char palavraRemover[47], letraDaPalavraRemover;
	TipoListaPalavras listaReferencia;
	TipoPalavra palavraASerRemovida, palavraRetirada;
	
	if (confere == 0)
	{
	printf("\n\n");
	
	printf("      Lista de operacoes      \n\n");
	printf("Criar Palavra [1]\n");
	printf("Criar Lista de Palavras [2]\n");
	printf("Criar Dicionario [3]\n");
//	printf("Remover Palavra [4]\n");
	printf("Imprimir Palavra [7]\n");
	printf("Imprimir Dicionario [8]\n");
//	printf("Imprimir Lista de Palavras [9]\n");
	
	printf("\n");
	}
	if (confere == 1)
	{
	printf("      Lista de operacoes      \n\n");
	printf("Criar Palavra [1]\n");
	printf("Criar Lista de Palavras [2]\n");
	printf("Criar Dicionario [3]\n");
	printf("Remover Palavra do Dicionario [4]\n");
	printf("Imprimir Palavra [7]\n");
	printf("Imprimir Dicionario [8]\n");
	
	printf("\n");
	}
	
	int sub, sub2, sub3;
	int l;
	int teimosia = 0;
	printf("Qual operacao deseja fazer? (Digite o numero da operacao): ");
	while (!scanf("%d", &op)) {
	    teimosia += 1;
	    if (teimosia == 1)
        	printf("\nPor favor, monitor, digite um numero.\n");
        if (teimosia == 2)
        	printf("\nE serio, digite um numero.\n");
        if (teimosia == 3)
        	printf("\nO codigo funciona, isto e, se voce usa-lo como planejado. Tente digitar um numero.\n");
        if (teimosia == 4)
        	printf("\n...Serio. Digite um numero.\n");
        if (teimosia > 4 && teimosia != 10)
        	printf("\nDigite um numero.\n");
        if (teimosia == 10)
        	printf("\nSe o usuario tentar digitar um numero, provavelmente ele veria as outras funcionalidades do codigo.\n");
//        teimosia += 1;
		getchar();
        }
		
		switch (op)
		{
			case 1:
				printf("\nDigite uma palavra: ");
				scanf("%s", &umaPalavra);
				printf("\nAtribua uma linha para essa palavra: ");
				scanf("%d", &umaLinha);
				inicia_TipoItem(&umItem, umaLinha);
				faz_lista_de_linhas_vazia(&umaListaLinhas);
				cria_palavra(&umaTPalavra, &umaListaLinhas, &umItem);
				nomeia_palavra(&umaTPalavra, umaPalavra);
				printf("\nPalavra criada.\n");
				printf("\nImprimir Palavra: [1]\nVoltar[2]\n");
				while(!scanf("%d", &sub) || sub > 2)
					printf("Digite uma operacao valida.\n");
				if(sub == 1)
					imprime_TipoPalavra(&umaTPalavra);
				break;
			case 2:
				cria_lista_palavras(&umaListaPalavras);
				printf("\nFoi criada uma lista de palavras vazia.");
				printf("\nAdicionar palavras na lista: [2]\nRemover a ultima palavra da lista: [3]\nVoltar: [4]\n");
				sub2 = 0;
				while (sub2 != 4)
				{
				while(!scanf("%d", &sub2) || sub2 > 4)
					printf("Digite uma operacao valida.\n");
				if(sub2 == 1)
				{
					imprime_lista_palavras(&umaListaPalavras);
					printf("\nImprimir Lista: [1]\nAdicionar palavra na lista: [2]\nRemover a ultima palavra da lista: [3]\nVoltar: [4]\n");
				}
				
				if(sub2 == 2)
				{
					printf("\nDigite uma palavra: ");
					scanf("%s", &umaPalavra);
					printf("\nAtribua uma linha para essa palavra: ");
					scanf("%d", &umaLinha);
					inicia_TipoItem(&umItem, umaLinha);
					faz_lista_de_linhas_vazia(&umaListaLinhas);
					cria_palavra(&umaTPalavra, &umaListaLinhas, &umItem);
					nomeia_palavra(&umaTPalavra, umaPalavra);
					insere_palavra(&umaListaPalavras, &umaTPalavra);
					printf("\nImprimir Lista: [1]\nAdicionar palavra na lista: [2]\nRemover a ultima palavra da lista: [4]\nVoltar: [3]\n");
				}
				if(sub2 == 3)
				{
					remove_palavra_final(&umaListaPalavras, &palavraRetirada);
					printf("\nImprimir Lista: [1]\nAdicionar palavra na lista: [2]\nRemover a ultima palavra da lista: [4]\nVoltar: [3]\n");
				}
				}
/*					while(!scanf("%d", &sub2) || sub2 > 3)
						printf("Digite uma operacao valida.\n");
//					printf("\nImprimir : [1]\nVoltar[2]\n");
//					while(!scanf("%d", &sub) || sub > 2)
//						printf("Digite uma operacao valida.\n");
					if(sub == 1)
						imprime_lista_palavras(&umaListaPalavras);
					
				} */
				if(sub2 == 4)
				 break;
				break;
			case 3:
				inicializa_dicionario(&dicionario);
				printf("\nPara construir um dicionario e preciso de um arquivo de texto.\n");
				printf("\nDigite o nome do arquivo de texto para construir seu dicionario: ");
				scanf("%s", &nomeArqTexto);
				FILE *texto;
				texto = fopen(nomeArqTexto, "r");
				constroi_dicionario(texto, &dicionario);
				confere = 1;
				printf("\nImprimir Dicionario: [1]\nVoltar[2]\n");
				while(!scanf("%d", &sub) || sub > 2)
					printf("Digite uma operacao valida.\n");
				if(sub == 1)
					imprime_dicionario(&dicionario);
				if(sub == 2)
					break;
				break;
			case 4:
				printf("\nDigite a palavra a ser removida: ");
				scanf("%s", &umaPalavra);
				listaReferencia = *retorna_lista_certa(&dicionario, umaPalavra[0]);
				palavraASerRemovida = *encontra_palavra(&listaReferencia, umaPalavra);
				remove_palavra(&listaReferencia, &palavraASerRemovida, &palavraRetirada);
				break;
			case 7:
				printf("\nDigite uma palavra para imprimir(digite uma palavra que esteja no dicionario): ");
				scanf("%s", &umaPalavra);
				listaReferencia = *retorna_lista_certa(&dicionario, umaPalavra[0]);
				umaTPalavra = *encontra_palavra(&listaReferencia, umaPalavra);
				imprime_TipoPalavra(&umaTPalavra);
				break;
			case 8:
				imprime_dicionario(&dicionario);
				break;

		}
	}
	return 0;
}

TipoPalavra* encontra_palavra(TipoListaPalavras* ptrLista, char* nomeDaPalavra)
{
	ApontadorP ptrAux;
	ptrAux = ptrLista->ptr_primeiro->ptr_prox;
	
	int verificador;
	
	while (ptrAux != NULL)
	{
		for (int i = 0; i < strlen(nomeDaPalavra); i++)
		{
			if (nomeDaPalavra[i] != get_Palavra(&ptrAux->Palavra)[i])
				verificador = 1;
			else
				verificador = 0;
		}
			if (verificador == 0)
				return &ptrAux->Palavra;
			else
				ptrAux = ptrAux->ptr_prox;
	}
	return NULL;
}

TipoListaPalavras* retorna_lista_certa(TipoDicionario* dicionario, char letra)
{
	ApontadorDicionario ptrAux;
	ptrAux = dicionario->ptr_primeirodicionario->ptr_proximo;
	while (ptrAux != NULL)
	{
		if(get_Palavra(&ptrAux->ListaPalavras.ptr_primeiro->ptr_prox->Palavra)[0] != letra)
			ptrAux = ptrAux->ptr_proximo;
		else
			return &ptrAux->ListaPalavras;
	}
	if (ptrAux == NULL)
		return NULL;
}
