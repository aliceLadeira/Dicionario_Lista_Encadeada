// TItem -> TListaDeLinhas -> TPalavra -> lista_palavras -> tad_dicionario

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_dicionario.h"

void inicializa_dicionario(TipoDicionario* ptr_dicionario){
    ptr_dicionario->ptr_primeirodicionario = (ApontadorDicionario) malloc(sizeof(TipoCelulaDicionario));
    ptr_dicionario->ptr_ultimodicionario = ptr_dicionario->ptr_primeirodicionario;
    ptr_dicionario->ptr_primeirodicionario->ptr_proximo = NULL;    
}

int dicionario_ehvazio(TipoDicionario* ptr_dicionario){
    return (ptr_dicionario->ptr_primeirodicionario == ptr_dicionario->ptr_ultimodicionario);
}

void insere_lista(TipoDicionario *ptr_dicionario, TipoListaPalavras *ptr_lista){
    ApontadorDicionario ptr_aux;
    ApontadorDicionario ptr_aux2;
    int encontrou = 0;
    ptr_aux = ptr_dicionario->ptr_primeirodicionario->ptr_proximo;
    ptr_aux2 = ptr_dicionario->ptr_primeirodicionario;
    while(ptr_aux != NULL){
        if(get_Palavra(&(ptr_aux->ListaPalavras.ptr_primeiro->ptr_prox->Palavra))[0] > get_Palavra(&(ptr_lista->ptr_primeiro->ptr_prox->Palavra))[0]){
            ptr_aux2->ptr_proximo = (ApontadorDicionario) malloc(sizeof(TipoCelulaDicionario));
            ptr_aux2->ptr_proximo->ListaPalavras = *ptr_lista;
            ptr_aux2->ptr_proximo->ptr_proximo = ptr_aux;
            encontrou = 1;
            break;
        }    
        
        ptr_aux2 = ptr_aux;
        ptr_aux = ptr_aux->ptr_proximo;
        
    }
    if(!encontrou){
        ptr_aux2->ptr_proximo = (ApontadorDicionario) malloc(sizeof(TipoCelulaDicionario));
        ptr_aux2->ptr_proximo->ListaPalavras = *ptr_lista;
        ptr_aux2->ptr_proximo->ptr_proximo = NULL;
        ptr_dicionario->ptr_ultimodicionario = ptr_aux2->ptr_proximo;
    }
}

void constroi_dicionario(FILE* texto, TipoDicionario* dicionario){
    TipoPalavra Palavra;
    inicializa_dicionario(dicionario);
    TipoListaDeLinhas ListaLinhas;
    TItem Linha;

    char nome[47];
    char caracter;
    int quant_linhas = 1;
    int guarda_quant_linhas = quant_linhas;
    inicia_TipoItem(&Linha, quant_linhas);
    do
    {
        fscanf(texto, "%s", nome);
        caracter = fgetc(texto);
        //if do \n

        if(quant_linhas > guarda_quant_linhas){
            inicia_TipoItem(&Linha, quant_linhas);
            guarda_quant_linhas = quant_linhas;
        }
        cria_palavra(&Palavra, &ListaLinhas, &Linha);
        nomeia_palavra(&Palavra, nome);
        if (dicionario_ehvazio(dicionario)){
            TipoListaPalavras ListaPalavras;
            cria_lista_palavras(&ListaPalavras);
            insere_palavra(&ListaPalavras, &Palavra);
            insere_lista(dicionario, &ListaPalavras);
        }
        else {
            ApontadorDicionario ptr_aux;
            ptr_aux = dicionario->ptr_primeirodicionario->ptr_proximo;
            int verificador;
            int acabei_de_inserir = 0;
            while(ptr_aux!=NULL){
                verificador = 0;
                // se a lista eh da letra da palavra que quero inserir
                if(get_Palavra(&ptr_aux->ListaPalavras.ptr_primeiro->ptr_prox->Palavra)[0] == nome[0]){
                    // se a palavra não está na lista
                    if(verifica_palavra(&ptr_aux->ListaPalavras, &Palavra) == 0){
                        insere_palavra(&ptr_aux->ListaPalavras, &Palavra);
                    }

                    /*else{
                            // não deu certo
                            insere_linha_na_lista(&(Palavra.lista), &Linha);    
                        }*/ 
                    verificador = 1;
                    break;   
                    }
                
                ptr_aux = ptr_aux->ptr_proximo;
            }
            if(!verificador){
                TipoListaPalavras NovaListaPalavras;
                cria_lista_palavras(&NovaListaPalavras);
                insere_palavra(&NovaListaPalavras, &Palavra);
                insere_lista(dicionario, &NovaListaPalavras);
            }
        }
        if(caracter == '\n'){
            quant_linhas++;
        }
    } while (!feof(texto));
    fclose(texto);

}

// Não usamos a função abaixo

/*void exibe_listadepalavras(TipoDicionario *ptr_dicionario, char letra_inicial)
{
    ApontadorDicionario ptr_aux;
    ptr_aux = ptr_dicionario->ptr_primeirodicionario->ptr_proximo;
    while(ptr_aux != NULL)
    {
        if(letra_inicial == ptr_aux->ListaPalavras.ptr_primeiro->Palavra.nomePalavra[0])
        {
            imprime_lista_palavras(&ptr_aux->ListaPalavras);
            break;
        }
    }
}*/


void imprime_dicionario(TipoDicionario *ptr_dicionario){
    ApontadorDicionario ptr_aux;
    ptr_aux = ptr_dicionario->ptr_primeirodicionario->ptr_proximo;
    char ultima_letra = '!';
    printf("***********************************\n");
    while (ptr_aux != NULL)
    {
        //printf("***********************************\n");
        char letra;
		letra = get_Palavra(&(ptr_aux->ListaPalavras.ptr_primeiro->ptr_prox->Palavra))[0];
        if((letra != ultima_letra)&&(ultima_letra != '!')){
            printf("***********************************\n");
            printf("\n");
            printf("***********************************\n");
        }
        ultima_letra = letra;
        printf("Letra:[%c]\n", letra);
        printf("\n");
        imprime_lista_palavras(&ptr_aux->ListaPalavras);
        ptr_aux = ptr_aux->ptr_proximo;
    }
    printf("***********************************\n");
    
}