#ifndef funcoes_h_
#define funcoes_h_
#include "pilha.h"
#include "noh.h"

PILHA *createStack(char nome);
NOH *criaNoh(tipo_t dado);
void push(NOH *noh, PILHA *p);
NOH *peek(PILHA *p);
NOH *pop(PILHA *p);
void printStack(PILHA *p);
void clear(PILHA *p);
void populaHanoi(PILHA *p, int n);
void printTorreDeHanoi(int discos, PILHA *origem, PILHA *destino);
void torreDeHanoi(PILHA *p1, PILHA *p2, PILHA *p3, int discos, int opc);
void printHanoi(PILHA *origem, PILHA *auxiliar, PILHA *destino);
int myAtoi(char *str);

#endif

