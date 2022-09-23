#ifndef noh_h_
#define noh_h_


typedef int tipo_t; /*tipo de dado a ser iterado na pilha*/
typedef struct NOH
{
    tipo_t dado;      /*dado a ser iterado na pilha*/
    struct NOH *prox; /*aponta para o prox elemento*/
} NOH;

NOH *criaNoh(tipo_t dado);

#endif