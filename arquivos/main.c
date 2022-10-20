//Breno: TItem -> TListaDeLinhas -> TPalavra ->
//Jeiverson: -> lista_palavras
//Alice: -> tad_dicionario
// gcc -o main main.c TItem.c TListaDeLinhas.c TPalavra.c lista_palavras.c tad_dicionario.c

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//#include "TItem.h"
//#include "TListaDeLinhas.h"
//#include "TPalavra.h"
//#include "lista_palavras.h"
#include "tad_dicionario.h"

int main()
{
	FILE* texto;
	texto = fopen("gabriel.txt", "r");

	TipoDicionario dicionario;
	constroi_dicionario(texto, &dicionario);
	imprime_dicionario(&dicionario);

	return 0;
}
