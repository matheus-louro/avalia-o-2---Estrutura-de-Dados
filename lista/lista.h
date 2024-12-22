/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: lista.h - declaração das funções da estrutura de dados lista e definição do tipo NODE
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#ifndef LISTA_H
#define LISTA_H

#include "../presentes/presentes.h"

typedef struct node
{
    PRESENTE presente;
    struct node *prox;
} NODE;

typedef enum {
    ORDENAR_POR_NOME,
    ORDENAR_POR_VALOR
} CRITERIO;

NODE* criar();
void inserir(PRESENTE novo_presente, NODE *lista);
void remover(const char *nome, NODE *lista);
void ordenar_lista(NODE *lista, CRITERIO criterio);
void destruir(NODE *lista);

#endif // LISTA_H
