#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "noh.h"
#include "pilha.h"
#include "funcoes.h"

int main(int argc, char *argv[])
{
    int opcional = 0;

    if(argv[2] != NULL) /*verifica se o argumento 2 existe*/
    {
        if(argv[2][0] == '-' && argv[2][1] == 'v') /*se sim, verifica se é -v*/
        {
            opcional = 1; /*opcional (feito para forçar uma característica booleana)*/
        }
    }
    /*recebe o número de disco*/
    int a = myAtoi(argv[1]);

    /*cria as pilhas*/
    PILHA *origem = createStack('A');
    PILHA *auxiliar = createStack('B');
    PILHA *destino = createStack('C');
    /*popula a pilha de origem*/
    populaHanoi(origem, a);

    /*printa o que é mostrado no console*/
    printf("Initial configuration:\n");
    printHanoi(origem, auxiliar, destino);
    torreDeHanoi(origem, auxiliar, destino, a, opcional);
    printf("Final configuration:\n");
    printHanoi(origem, auxiliar, destino);

    /*limpa a pilha destino (pois é a única que possui elementos, então não há necessidade de limpar as outras)*/
    clear(destino);
    
    /*remove a alocação de memória que fora específicada à essas pilhas*/
    free(destino);
    free(origem);
    free(auxiliar);
    return 0;
}