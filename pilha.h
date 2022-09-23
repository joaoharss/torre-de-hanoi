#ifndef pilha_h_
#define pilha_h_

typedef struct PILHA{
    NOH *topo /*topo = dado e prox*/;
    char nome; /*nome da pilha (a, b, c no caso de hanoi)*/
    int tam;
}PILHA;
PILHA *createStack(char nome);
NOH *peek(PILHA *p);
NOH *pop(PILHA *p);
void printStack(PILHA *p);
void clear(PILHA *p);
void populaHanoi(PILHA *p, int n);
void push(NOH *noh, PILHA *p);

#endif