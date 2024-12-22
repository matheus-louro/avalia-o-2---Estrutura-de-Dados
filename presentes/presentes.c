/***************************************************************

Projeto: Avaliação 2 - Sistema de Cadastro de Presentes
Arquivo: presentes.c - Implementação das funções do módulo de presentes
Nome: Matheus Henrique Moreira Louro
Data: 15/12/2024

/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "presentes.h"
#include "../lista/lista.h"
#include "../menus/menus.h"
#include <time.h>

//FUNCÕES AUXILIARES

//Função para armazenar strings com espaços
char *input()
{
    char buffer[1024];
    char *string = NULL;
    size_t tamanho = 0;

    if (fgets(buffer, sizeof(buffer), stdin))
    {
        tamanho = strlen(buffer);

        if (buffer[tamanho - 1] == '\n')
        {
            buffer[tamanho - 1] = '\0';
            tamanho--;
        }

        string = malloc(tamanho + 1);
        if (string)
        {
            strcpy(string, buffer);
        }
    }

    return string;
}
//Função para evitar erros de buffer
void limpar_buffer_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//funcões de validação
bool nome_valido(const char *nome) {
    return strlen(nome) > 2;
}


bool data_valida(DATA data) {
    return (data.dia >= 1 && data.dia <= 31) && (data.mes >= 1 && data.mes <= 12);
}


//Funções principais do programa

void cadastrar_presente(NODE *lista) {
    int opcao;

    do {
        PRESENTE novo_presente;

        printf("\033[34m"); // Define a cor azul
        printf("============================================\n");
        printf("            \033[1;37m🎁 MENU DE CADASTRO 🎁\033[0;34m            \n");
        printf("============================================\n");
        printf("\033[0m"); // Reseta a cor para o padrão

        // Nome do presente
        char *aux_nome_presente;
        do {
            printf("\033[36mNome do presente:\033[0m ");
            limpar_buffer_entrada();
            aux_nome_presente = input();
            if (!nome_valido(aux_nome_presente)) {
                printf("\033[31m[Erro] Nome inválido! O nome deve ter mais de 2 caracteres.\033[0m\n");
            }
        } while (!nome_valido(aux_nome_presente));
        strncpy(novo_presente.nome, aux_nome_presente, sizeof(novo_presente.nome) - 1);
        novo_presente.nome[sizeof(novo_presente.nome) - 1] = '\0';
        free(aux_nome_presente);

        // Local de compra
        char *aux_nome_local;
        do {
            printf("\033[36mLocal onde encontrar/comprar:\033[0m ");
            aux_nome_local = input();
            if (!nome_valido(aux_nome_local)) {
                printf("\033[31m[Erro] Local inválido! Deve ter mais de 2 caracteres.\033[0m\n");
            }
        } while (!nome_valido(aux_nome_local));
        strncpy(novo_presente.local, aux_nome_local, sizeof(novo_presente.local) - 1);
        novo_presente.local[sizeof(novo_presente.local) - 1] = '\0';
        free(aux_nome_local);

        // Valor do presente
        do {
            printf("\033[36mValor do presente:\033[0m ");
            if (scanf("%f", &novo_presente.valor) != 1 || novo_presente.valor <= 0) {
                printf("\033[31m[Erro] Valor inválido! Deve ser maior que 0.\033[0m\n");
                limpar_buffer_entrada();
            }
        } while (novo_presente.valor <= 0);

        // Nome do convidado
        char *aux_nome_convidado;
        do {
            printf("\033[36mNome do convidado:\033[0m ");
            limpar_buffer_entrada();
            aux_nome_convidado = input();
            if (!nome_valido(aux_nome_convidado)) {
                printf("\033[31m[Erro] Nome do convidado inválido! Deve ter mais de 2 caracteres.\033[0m\n");
            }
        } while (!nome_valido(aux_nome_convidado));
        strncpy(novo_presente.convidado, aux_nome_convidado, sizeof(novo_presente.convidado) - 1);
        novo_presente.convidado[sizeof(novo_presente.convidado) - 1] = '\0';
        free(aux_nome_convidado);

        // Data do presente
        do {
            printf("\033[36mDigite a data (dd/mm/aaaa):\033[0m ");
            if (scanf("%2d/%2d/%4d", &novo_presente.data.dia, &novo_presente.data.mes, &novo_presente.data.ano) != 3 || !data_valida(novo_presente.data)) {
                printf("\033[31m[Erro] Data inválida! O dia deve estar entre 1 e 31, e o mês entre 1 e 12.\033[0m\n");
                limpar_buffer_entrada();
            }
        } while (!data_valida(novo_presente.data));

        inserir(novo_presente, lista);
        printf("\033[32m✅ %s cadastrado com sucesso!\033[0m\n", novo_presente.nome);

        // Menu de continuar cadastro
        do {
            printf("\033[33mDeseja cadastrar outro presente?\033[0m\n");
            printf("\033[36m[1] Sim   [2] Não\033[0m\n");
            printf("Escolha: ");
            if (scanf("%d", &opcao) != 1) {
                printf("\033[31m[Erro] Opção inválida! Digite 1 para Sim ou 2 para Não.\033[0m\n");
                limpar_buffer_entrada();
                opcao = 0; // Força a repetição em caso de erro
            } else if (opcao != 1 && opcao != 2) {
                printf("\033[31m[Erro] Escolha inválida! Tente novamente.\033[0m\n");
            }
        } while (opcao != 1 && opcao != 2);

    } while (opcao == 1);

    printf("\033[32mCadastro finalizado. Retornando ao menu principal.\033[0m\n");
}


void remover_presente(NODE *lista)
{
    printf("\033[34m"); // Cor azul para o título
    printf("============================================\n");
    printf("          \033[1;37m🗑️  REMOVER PRESENTE 🗑️\033[0;34m            \n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor padrão
    char *nome;
    printf("Digite o nome do presente que deseja remover: ");
    limpar_buffer_entrada();
    nome = input();

    remover(nome, lista);

    free(nome);
}

void buscar(NODE *lista)
{
    char *nome;
    printf("\033[34m"); // Define a cor azul
    printf("============================================\n");
    printf("            \033[1;37m🎁 BUSCAR PRESENTE 🎁\033[0;34m            \n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão
    printf("Digite o nome do presente que deseja buscar: ");
    limpar_buffer_entrada();
    nome = input();

    for (NODE *tmp = lista; tmp != NULL; tmp = tmp->prox)
    {
        if (strcmp(tmp->presente.nome, nome) == 0)
        {
            printf("\033[32m\n╔════════════════════════════════════════╗\n");
            printf("║       🎁  PRESENTE ENCONTRADO  🎁      ║\n");
            printf("╚════════════════════════════════════════╝\033[0m\n");
            printf("\033[33mNome do Presente   :\033[0m %s\n", tmp->presente.nome);
            printf("\033[33mLocal de Compra    :\033[0m %s\n", tmp->presente.local);
            printf("\033[33mValor do Presente  :\033[0m R$ %.2f\n", tmp->presente.valor);
            printf("\033[33mNome do Convidado  :\033[0m %s\n", tmp->presente.convidado);
            printf("\033[33mData do Presente   :\033[0m %02d/%02d/%d\n",
                   tmp->presente.data.dia,
                   tmp->presente.data.mes,
                   tmp->presente.data.ano);
            printf("\n\033[32m╚════════════════════════════════════════╝\033[0m\n");
            free(nome);
            return;
        }
    }

    printf("\033[31m%s não foi encontrado na lista de presentes!\033[0m\n", nome);
    free(nome);
    return;
}


void alterar_presente(NODE *lista)
{
    printf("\033[34m");
    printf("============================================\n");
    printf("            \033[1;37m🎁 ALTERAR PRESENTE 🎁\033[0;34m            \n");
    printf("============================================\n");
    printf("\033[0m"); // Reseta a cor para o padrão

    char *nome_busca;
    printf("\033[36mDigite o nome do presente que deseja alterar:\033[0m ");
    limpar_buffer_entrada();
    nome_busca = input();

    NODE *atual = lista->prox; // Percorre a lista (pulando o nó cabeça, se houver)
    int encontrado = 0;

    while (atual != NULL) {
        if (strcmp(atual->presente.nome, nome_busca) == 0) {
            encontrado = 1;
            int opcao;

            printf("\n\033[32m✔ Presente encontrado:\033[0m\n");
            printf("\033[36m--------------------------------------------\033[0m\n");
            printf("\033[33mNome:\033[0m %s\n", atual->presente.nome);
            printf("\033[33mLocal:\033[0m %s\n", atual->presente.local);
            printf("\033[33mValor:\033[0m R$ %.2f\n", atual->presente.valor);
            printf("\033[36m--------------------------------------------\033[0m\n");

            do {
                printf("\n\033[34mSelecione o que deseja alterar:\033[0m\n");
                printf("\033[36m[1]\033[0m Local de compra\n");
                printf("\033[36m[2]\033[0m Valor do presente\n");
                printf("\033[36m[3]\033[0m Cancelar alteração\n");
                printf("\033[35mEscolha uma opção:\033[0m ");

                if (scanf("%d", &opcao) != 1) {
                    printf("\033[31mOpção inválida! Tente novamente.\033[0m\n");
                    limpar_buffer_entrada();
                    opcao = 0; // Força a repetição
                }

                switch (opcao) {
                    case 1: {
                        char *novo_local;
                        printf("\n\033[35mDigite o novo local de compra:\033[0m ");
                        limpar_buffer_entrada();
                        novo_local = input();

                        if (nome_valido(novo_local)) {
                            strncpy(atual->presente.local, novo_local, sizeof(atual->presente.local) - 1);
                            atual->presente.local[sizeof(atual->presente.local) - 1] = '\0';
                            printf("\033[32m✔ Local de compra alterado com sucesso!\033[0m\n");
                        } else {
                            printf("\033[31m❌ Local inválido! Deve ter mais de 2 caracteres.\033[0m\n");
                        }
                        free(novo_local);
                        break;
                    }
                    case 2: {
                        float novo_valor;
                        do {
                            printf("\n\033[35mDigite o novo valor do presente:\033[0m ");
                            limpar_buffer_entrada();
                            if (scanf("%f", &novo_valor) != 1 || novo_valor <= 0) {
                                printf("\033[31m❌ Valor inválido! Deve ser maior que 0.\033[0m\n");
                                limpar_buffer_entrada();
                            }
                        } while (novo_valor <= 0);

                        atual->presente.valor = novo_valor;
                        printf("\033[32m✔ Valor do presente alterado com sucesso!\033[0m\n");
                        break;
                    }
                    case 3:
                        printf("\033[33m⚠ Alteração cancelada pelo usuário.\033[0m\n");
                        break;
                    default:
                        printf("\033[31m❌ Opção inválida! Tente novamente.\033[0m\n");
                }
            } while (opcao != 1 && opcao != 2 && opcao != 3);

            break;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("\n\033[31m❌ Presente com o nome '%s' não encontrado.\033[0m\n", nome_busca);
    }

    free(nome_busca);
}



void listar_presentes_entregues(NODE *lista)
{
    if (lista == NULL || lista->prox == NULL)
    {
        printf("\033[31m❌ A lista de presentes está vazia!\033[0m\n");
        return;
    }

    int escolha;
    printf("Deseja listar os presentes em:\n");
    printf("[1] Ordem alfabética (Nome)\n");
    printf("[2] Ordem de valor\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        ordenar_lista(lista, ORDENAR_POR_NOME);
    }
    else if (escolha == 2)
    {
        ordenar_lista(lista, ORDENAR_POR_VALOR);
    }
    else
    {
        printf("\033[31m❌ Opção inválida!\033[0m\n");
        return;
    }

    // Data do presente
    DATA data_informada;
    do {
        printf("\033[36mDigite a data (dd/mm/aaaa):\033[0m ");
        if (scanf("%2d/%2d/%4d", &data_informada.dia, &data_informada.mes, &data_informada.ano) != 3 || !data_valida(data_informada)) {
            printf("\033[31m[Erro] Data inválida! O dia deve estar entre 1 e 31, e o mês entre 1 e 12.\033[0m\n");
            limpar_buffer_entrada();
        }
    } while (!data_valida(data_informada));

    printf("\033[34m");
    printf("============================================\n");
    printf("        \033[1;37m🎁 PRESENTES ENTREGUES 🎁\033[0;34m        \n");
    printf("============================================\033[0m\n");

    for (NODE *tmp = lista; tmp != NULL; tmp = tmp->prox)
    {
        if ((tmp->presente.data.ano < data_informada.ano) ||
            (tmp->presente.data.ano == data_informada.ano && tmp->presente.data.mes < data_informada.mes) ||
            (tmp->presente.data.ano == data_informada.ano && tmp->presente.data.mes == data_informada.mes && tmp->presente.data.dia <= data_informada.dia))
        {
            printf("\033[32m\n╔════════════════════════════════════════╗\n");
            printf("║        🎁  PRESENTE ENTREGUE  🎁       ║\n");
            printf("╚════════════════════════════════════════╝\033[0m\n");
            printf("\033[33mNome do Presente   :\033[0m %s\n", tmp->presente.nome);
            printf("\033[33mLocal de Compra    :\033[0m %s\n", tmp->presente.local);
            printf("\033[33mValor do Presente  :\033[0m R$ %.2f\n", tmp->presente.valor);
            printf("\033[33mNome do Convidado  :\033[0m %s\n", tmp->presente.convidado);
            printf("\033[33mData do Presente   :\033[0m %02d/%02d/%d\n",
                   tmp->presente.data.dia,
                   tmp->presente.data.mes,
                   tmp->presente.data.ano);
            printf("\n\033[32m╚════════════════════════════════════════╝\033[0m\n");
        }
    }
}

void listar_presentes_nao_entregues(NODE *lista)
{
    if (lista == NULL || lista->prox == NULL)
    {
        printf("\033[31m❌ A lista de presentes está vazia!\033[0m\n");
        return;
    }

    int escolha;
    printf("Deseja listar os presentes em:\n");
    printf("[1] Ordem alfabética (Nome)\n");
    printf("[2] Ordem de valor\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        ordenar_lista(lista, ORDENAR_POR_NOME);
    }
    else if (escolha == 2)
    {
        ordenar_lista(lista, ORDENAR_POR_VALOR);
    }
    else
    {
        printf("\033[31m❌ Opção inválida!\033[0m\n");
        return;
    }

    // Data do presente
    DATA data_informada;
    do {
        printf("\033[36mDigite a data (dd/mm/aaaa):\033[0m ");
        if (scanf("%2d/%2d/%4d", &data_informada.dia, &data_informada.mes, &data_informada.ano) != 3 || !data_valida(data_informada)) {
            printf("\033[31m[Erro] Data inválida! O dia deve estar entre 1 e 31, e o mês entre 1 e 12.\033[0m\n");
            limpar_buffer_entrada();
        }
    } while (!data_valida(data_informada));

    printf("\033[34m");
    printf("============================================\n");
    printf("       \033[1;37m🎁 PRESENTES NÃO ENTREGUES 🎁\033[0;34m       \n");
    printf("============================================\033[0m\n");

    for (NODE *tmp = lista->prox; tmp != NULL; tmp = tmp->prox)
    {
        if ((tmp->presente.data.ano > data_informada.ano) ||
            (tmp->presente.data.ano == data_informada.ano && tmp->presente.data.mes > data_informada.mes) ||
            (tmp->presente.data.ano == data_informada.ano && tmp->presente.data.mes == data_informada.mes && tmp->presente.data.dia > data_informada.dia))
        {
            printf("\033[32m\n╔════════════════════════════════════════╗\n");
            printf("║   🎁  PRESENTE NÃO ENTREGUE  🎁        ║\n");
            printf("╚════════════════════════════════════════╝\033[0m\n");
            printf("\033[33mNome do Presente   :\033[0m %s\n", tmp->presente.nome);
            printf("\033[33mLocal de Compra    :\033[0m %s\n", tmp->presente.local);
            printf("\033[33mValor do Presente  :\033[0m R$ %.2f\n", tmp->presente.valor);
            printf("\033[33mNome do Convidado  :\033[0m %s\n", tmp->presente.convidado);
            printf("\033[33mData do Presente   :\033[0m %02d/%02d/%d\n",
                   tmp->presente.data.dia,
                   tmp->presente.data.mes,
                   tmp->presente.data.ano);
            printf("\n\033[32m╚════════════════════════════════════════╝\033[0m\n");
        }
    }
}

void listar_todos_presentes(NODE *lista)
{
    if (lista == NULL || lista->prox == NULL)
    {
        printf("\033[31m❌ A lista de presentes está vazia!\033[0m\n");
        return;
    }

    int escolha;
    printf("Deseja listar os presentes em:\n");
    printf("[1] Ordem alfabética (Nome)\n");
    printf("[2] Ordem de valor\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        ordenar_lista(lista, ORDENAR_POR_NOME);
    }
    else if (escolha == 2)
    {
        ordenar_lista(lista, ORDENAR_POR_VALOR);
    }
    else
    {
        printf("\033[31m❌ Opção inválida!\033[0m\n");
        return;
    }

    printf("\033[34m");
    printf("============================================\n");
    printf("          \033[1;37m🎁 TODOS OS PRESENTES 🎁\033[0;34m          \n");
    printf("============================================\033[0m\n");

    for (NODE *tmp = lista->prox; tmp != NULL; tmp = tmp->prox)
    {
        printf("\033[32m\n╔════════════════════════════════════════╗\n");
            printf("║                  🎁                    ║\n");
            printf("╚════════════════════════════════════════╝\033[0m\n");
            printf("\033[33mNome do Presente   :\033[0m %s\n", tmp->presente.nome);
            printf("\033[33mLocal de Compra    :\033[0m %s\n", tmp->presente.local);
            printf("\033[33mValor do Presente  :\033[0m R$ %.2f\n", tmp->presente.valor);
            printf("\033[33mNome do Convidado  :\033[0m %s\n", tmp->presente.convidado);
            printf("\033[33mData do Presente   :\033[0m %02d/%02d/%d\n",
                   tmp->presente.data.dia,
                   tmp->presente.data.mes,
                   tmp->presente.data.ano);
            printf("\n\033[32m╚════════════════════════════════════════╝\033[0m\n");
    }
}
