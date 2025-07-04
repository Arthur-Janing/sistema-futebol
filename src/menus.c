#include <stdio.h>
#include "../include/menus.h"
#include "../include/utils.h"

int menu_principal() {
    int opcao;
    limpar_tela();
    printf("\n======== Menu Principal ========\n");
    printf("1. Cadastros\n");
    printf("2. Relatorios\n");
    printf("3. Consultas e Buscas\n");
    printf("4. Exportar Dados\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); 
    return opcao;
}

int menu_cadastros() {
    int opcao;
    limpar_tela();
    printf("\n--- Menu de Cadastros ---\n");
    printf("1. Cadastrar Novo Jogador\n");
    printf("2. Cadastrar Nova Partida\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int menu_relatorios() {
    int opcao;
    limpar_tela();
    printf("\n--- Menu de Relatorios ---\n");
    printf("1. Relatorio Completo de Jogadores\n");
    printf("2. Relatorio de Jogadores Vendidos\n");
    printf("3. Relatorio de Valor do Time\n");
    printf("4. Relatorio Completo de Partidas\n");
    printf("5. Relatorio de Aproveitamento do Time\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int menu_consultas() {
    int opcao;
    limpar_tela();
    printf("\n--- Menu de Consultas e Buscas ---\n");
    printf("1. Buscar Jogador por Nome\n");
    printf("2. Buscar Jogadores por Posicao\n");
    printf("3. Buscar Jogadores por Faixa Salarial\n");
    printf("4. Buscar Jogador com Maior Salario\n");
    printf("5. Buscar Jogadores por Faixa de Idade\n");
    printf("6. Buscar Jogos por Adversario\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

int menu_exportar() {
    int opcao;
    limpar_tela();
    printf("\n--- Menu de Exportacao ---\n");
    printf("1. Exportar Jogadores para .CSV\n");
    printf("2. Exportar Jogadores para .HTML\n");
    printf("3. Exportar Partidas para .CSV\n");
    printf("4. Exportar Partidas para .HTML\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}