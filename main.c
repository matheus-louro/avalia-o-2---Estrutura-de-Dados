/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: main.c - Função principal do programa
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <locale.h>
#include <signal.h>
#include "lista/lista.h"
#include "menus/menus.h"

int main()
{
    //Configura o idioma para portugues no terminal
    setlocale(LC_ALL, "Portuguese");

    //Configura a tela de encerramento para quando o usuário encerrar o programa com ctrl + c
    signal(SIGINT, tela_encerramento);

    NODE *lista = criar();
    if (lista == NULL) {
        printf("\n--- Erro ao criar a lista. ---\n");
        return 1; // Encerrar o programa
    }

    menu_principal(lista);

    destruir(lista);

    tela_encerramento();
    return 0;
}