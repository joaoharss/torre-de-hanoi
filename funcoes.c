#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "noh.h"
#include "pilha.h"
#include "funcoes.h"

PILHA *createStack(char nome) /*cria a pilha*/
{
    PILHA *p = (PILHA *)malloc(sizeof(PILHA));
    p->topo = NULL; /*nulo pq to criando a pilha*/
    p->nome = nome;
    return p;
}

NOH *criaNoh(tipo_t dado) /*cria o nó */
{
    NOH *noh = (NOH *)malloc(sizeof(NOH));
    noh->dado = dado;
    noh->prox = NULL;
    return noh;
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

void printTorreDeHanoi(int discos, PILHA *origem, PILHA *destino) /*printa torre de hanoi caso argumento -v seja passado*/
{ 
    printf("Move disk %i from %c to %c\n", discos, origem->nome, destino->nome);
}

void torreDeHanoi(PILHA *p1, PILHA *p2, PILHA *p3, int discos, int opc) /*algoritmo torre de hanoi*/
{
    if (opc == 1)
    {
        if (discos == 1)
        {
            NOH *noh = pop(p1);
            push(noh, p3);
            printTorreDeHanoi(discos, p1, p3);
        }
        else
        {
            torreDeHanoi(p1, p3, p2, discos - 1, opc);
            NOH *noh = pop(p1);
            push(noh, p3);
            printTorreDeHanoi(discos, p1, p3);
            torreDeHanoi(p2, p1, p3, discos - 1, opc);
        }
    }
    else
    {
        if (discos == 1)
        {
            NOH *noh = pop(p1);
            push(noh, p3);
        }
        else
        {
            torreDeHanoi(p1, p3, p2, discos - 1, opc);
            NOH *noh = pop(p1);
            push(noh, p3);
            torreDeHanoi(p2, p1, p3, discos - 1, opc);
        }
    }
}

void printHanoi(PILHA *origem, PILHA *auxiliar, PILHA *destino) /*printa os elementos da pilha*/
{
    printf("A: ");
    printStack(origem);
    printf("B: ");
    printStack(auxiliar);
    printf("C: ");
    printStack(destino);
    printf("\n");
}

int myAtoi(char *str) /*transforrma um char para inteiro (feito para receber o número de discos)*/
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}