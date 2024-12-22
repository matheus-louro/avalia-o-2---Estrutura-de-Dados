/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: menus.c - funções de interface com o usuário
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../presentes/presentes.h"


//headers das funções de menus
void menu_principal(NODE *lista);
void menu_continuar_cadastro();
void menu_invalido();
void tela_encerramento();
void menu_listar_presentes(NODE *lista);

//funções de menus
void menu_principal_template()
{
    printf("\n\033[1;34m"); // Define a cor azul
    printf("╔════════════════════════════════════════╗\n");
    printf("║         🌟  MENU PRINCIPAL  🌟         ║\n");
    printf("╚════════════════════════════════════════╝\033[0m\n");
    
    printf("\033[33m"); // Define a cor amarela para as opções
    printf("  [1] 🎁  Cadastrar presente\n");
    printf("  [2] 🗑️  Remover presente\n");
    printf("  [3] 🔎  Buscar presente\n");
    printf("  [4] ✏️  Alterar presente\n");
    printf("  [5] 📋  Listar presentes\n");
    printf("  [6] 🧹  Limpar terminal\n");
    printf("  [7] 🚪  Sair\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    
    printf("\033[34m╔════════════════════════════════════════╗\n");
    printf("║       Selecione uma opção [1-7]        ║\n");
    printf("╚════════════════════════════════════════╝\033[0m\n");
    printf("Selecionar: ");
}

void menu_principal(NODE *lista)
{
    int opcao = 0;

    do
    {
        menu_principal_template();        
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrar_presente(lista);
            break;
        case 2:
            remover_presente(lista);
            break;
        case 3:
            buscar(lista);
            break;
        case 4:
            alterar_presente(lista);
            break;
        case 5:
            menu_listar_presentes(lista);
            break;
        case 6:
            system("clear");
            break;
        case 7:
            return;
        
        default:
            menu_invalido();
            break;
        }
    
    } while (opcao != 7);
    
    
}

void menu_listar_presentes_template()
{
    printf("\n\033[1;34m"); // Define a cor azul
    printf("╔════════════════════════════════════════╗\n");
    printf("║          📋 LISTAR PRESENTES 📋        ║\n");
    printf("╚════════════════════════════════════════╝\033[0m\n");
    
    printf("\033[33m"); // Define a cor amarela para as opções
    printf("  [1] ✅  Listar presentes já entregues\n");
    printf("  [2] 📦  Listar presentes não entregues\n");
    printf("  [3] 🎁  Listar todos os presentes\n");
    printf("  [4] 🔙  Voltar ao menu principal\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    
    printf("\033[34m╔════════════════════════════════════════╗\n");
    printf("║       Selecione uma opção [1-4]        ║\n");
    printf("╚════════════════════════════════════════╝\033[0m\n");
    printf("Selecionar: ");
}

void menu_listar_presentes(NODE *lista)
{
    int opcao = 0;
    do
    {
        menu_listar_presentes_template();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            listar_presentes_entregues(lista);
            break;
        case 2:
            listar_presentes_nao_entregues(lista);
            break;
        case 3:
            listar_todos_presentes(lista);
            break;
        case 4:
            return;
        default:
            menu_invalido();
            break;
        }    
    } while (opcao != 4);
    
}

//menus templates
void menu_invalido()
{
    printf("\n");
    printf("\033[31m"); // Define a cor vermelha
    printf("====================================================================\n");
    printf("!!! Opção inválida. Por favor, escolha uma opção válida do menu. !!!\n");
    printf("====================================================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
}

void menu_continuar_cadastro()
{
    printf("Deseja continuar o cadastro de presentes?\n");
    printf("[1] Sim\n");
    printf("[2] Não\n");
    printf("Escolha uma opção: ");
}

void tela_encerramento()
{
    printf("\n\033[32m"); // Define a cor azul
    printf("╔════════════════════════════════════════╗\n");
    printf("║          👋  ENCERRANDO...  👋         ║\n");
    printf("╚════════════════════════════════════════╝\033[0m\n");

    exit(0);
}




