#include "noh.h"
#include "pilha.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


PILHA *createStack(char nome) /*cria a pilha*/
{
    PILHA *p = (PILHA *)malloc(sizeof(PILHA));
    p->topo = NULL; /*nulo pq to criando a pilha*/
    p->nome = nome;
    return p;
}

void push(NOH *noh, PILHA *p) /*adiciona um nó à pilha*/
{
    if (noh == NULL || p == NULL)
    {
        printf("Erro de alocação\n");
    }
    else
    {
        noh->prox = p->topo;
        p->topo = noh;
    }
}

NOH *peek(PILHA *p) /*INSPECIONA o último elemento da pilha*/
{
    if (p->topo == NULL)
    {
        printf("PILHA VAZIA!\n");
        return 0;
    }
    else
    {
        return p->topo;
    }
}


NOH *pop(PILHA *p) /*remove um nó da pilha*/
{
    if (p->topo == NULL)
    {
        printf("PILHA VAZIA!\n");
        return 0;
    }
    else
    {
        NOH *topo = peek(p);
        NOH *aux = topo;
        p->topo = p->topo->prox;
        return aux;
    }
}

void clear(PILHA *p) /*limpa os ELEMENTOS da pilha, não a alocação dela*/
{
    if (p->topo == NULL)
    {
        printf("PILHA VAZIA!\n");
    }
    else
    {
        NOH *aux = p->topo;
        while (aux != NULL)
        {
            NOH *aux2 = aux;
            aux = aux->prox;
            free(aux2);
        }
        p->topo = NULL;
    }
}

void populaHanoi(PILHA *p, int n) /*popula a pilha origem (pino A da torre)*/
{
    int i;
    for (i = 1; i <= n; i++)
    {
        NOH *noh = criaNoh(i);
        push(noh, p);
    }
}


void printStack(PILHA *p) /*imprime a pilha*/
{
    if (p->topo == NULL)
    {
        printf("\n");
    }
    else
    {
        NOH *aux = p->topo;
        while (aux != NULL)
        {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}
