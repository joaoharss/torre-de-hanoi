#ifndef pilha_h_
#define pilha_h_

typedef struct PILHA
{
    NOH *topo /*topo = dado e prox*/;
    char nome; /*nome da pilha (a, b, c no caso de hanoi)*/
    int tam;
} PILHA;

#endif