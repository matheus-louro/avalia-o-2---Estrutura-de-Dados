/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: lista.c - funções da estrutura de dados lista
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

NODE* criar() 
{
    NODE *lista = malloc(sizeof(NODE));
    lista->prox = NULL;
    if (lista != NULL) 
        return lista;
    return NULL;
}

void inserir(PRESENTE novo_presente, NODE *lista)
{
    for (NODE *tmp = lista; tmp != NULL; tmp = tmp->prox) {
        if (tmp->prox == NULL) {
            NODE *novo = malloc(sizeof(NODE));
            novo->presente = novo_presente;
            novo->prox = NULL;

            tmp->prox = novo;
            break;
        }
    }
}

void remover(const char *nome, NODE *lista)
{
    for (NODE *tmp = lista; tmp->prox != NULL; tmp = tmp->prox) {
        if (strcmp(tmp->prox->presente.nome, nome) == 0) {
            NODE *aux = tmp->prox;
            tmp->prox = tmp->prox->prox;
            printf("\n\033[32m%s removido com sucesso!\033[0m\n", aux->presente.nome);
            free(aux);
            return;
        }
    }

    printf("\n\033[31m%s não foi encontrado na lista de presentes!\033[0m\n", nome);
}

void ordenar_lista(NODE *lista, CRITERIO criterio) 
{
    if (lista == NULL || lista->prox == NULL) 
        return;

    for (NODE *i = lista->prox; i != NULL; i = i->prox) {
        NODE *menor = i;

        for (NODE *j = i->prox; j != NULL; j = j->prox) {
            int comparar = 0;

            if (criterio == ORDENAR_POR_NOME) {
                comparar = strcmp(j->presente.nome, menor->presente.nome);
            } else if (criterio == ORDENAR_POR_VALOR) {
                comparar = (j->presente.valor < menor->presente.valor) ? -1 : 1;
            }

            if (comparar < 0) {
                menor = j;
            }
        }

        if (menor != i) {
            PRESENTE temp = i->presente;
            i->presente = menor->presente;
            menor->presente = temp;
        }
    }
}

void destruir(NODE *lista) 
{
    NODE *tmp = lista->prox;
    while (tmp != NULL) {
        NODE *aux = tmp;
        tmp = tmp->prox;
        free(aux);
    }

    free(lista);
}
