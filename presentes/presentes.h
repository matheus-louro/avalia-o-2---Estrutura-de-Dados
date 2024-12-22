/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: presentes.h - Definição das funções do módulo de presentes e definição de estruturas como DATA e PRESENTE
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#ifndef PRESENTES_H
#define PRESENTES_H

#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct p
{
    char nome[50];
    char local[50];
    float valor;
    char convidado[50];
    DATA data;
} PRESENTE;

//Para evitar erros de declaração de estrutura na compilação
struct node; // Declaração antecipada de NODE (tipo incompleto)
typedef struct node NODE;

void cadastrar_presente(NODE *lista);
void remover_presente(NODE *lista);
void buscar(NODE *lista);
void alterar_presente(NODE *lista);
void listar_presentes_entregues(NODE *lista);
void listar_presentes_nao_entregues(NODE *lista);
void listar_todos_presentes(NODE *lista);

#endif // PRESENTES_H
