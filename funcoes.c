#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "noh.h"
#include "pilha.h"
#include "funcoes.h"


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