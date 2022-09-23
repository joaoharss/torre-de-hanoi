#include "noh.h"
#include "pilha.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


NOH *criaNoh(tipo_t dado) /*cria o nó */
{
    NOH *noh = (NOH *)malloc(sizeof(NOH));
    noh->dado = dado;
    noh->prox = NULL;
    return noh;
}
