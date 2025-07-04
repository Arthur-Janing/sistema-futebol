#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/consultas.h"
#include "../include/relatorios.h"
#include "../include/utils.h"
#include "../include/types.h"


NoJogador* consulta_jogador_por_nome(NoJogador *inicio_lista, const char* nome) {
    NoJogador *atual = inicio_lista;
    while(atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void consulta_e_mostra_jogador_por_nome(NoJogador* inicio_lista) {
    char nome_busca[MAX_NOME];
    limpar_tela();
    printf("--- Consultar Jogador por Nome ---\n");
    printf("Digite o nome do jogador: ");
    fgets(nome_busca, MAX_NOME, stdin);
    retirar_enter(nome_busca);
    to_upper(nome_busca);

    NoJogador* jogador_encontrado = consulta_jogador_por_nome(inicio_lista, nome_busca);

    if (jogador_encontrado != NULL) {
        
        mostrar_jogador_detalhado(jogador_encontrado);


    } else {
        printf("\nJogador com o nome '%s' nao foi encontrado.\n", nome_busca);
    }
    pausar_sistema();
}

void localizar_jogadores_por_posicao(NoJogador* inicio_lista) {
    char posicao_busca[MAX_POSICAO];
    int encontrados = 0;
    limpar_tela();
    printf("--- Localizar Jogadores por Posicao ---\n");
    printf("Digite a posicao que deseja buscar: ");
    fgets(posicao_busca, MAX_POSICAO, stdin);
    retirar_enter(posicao_busca);
    to_upper(posicao_busca);

    printf("\nJogadores na posicao '%s':\n", posicao_busca);
    NoJogador* atual = inicio_lista;
    while (atual != NULL) {
        if (strcmp(atual->dados.posicao, posicao_busca) == 0) {
            printf("- %s\n", atual->dados.nome);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0) {
        printf("\nNenhum jogador encontrado nesta posicao.\n");
    }
    pausar_sistema();
}

void localizar_jogadores_por_faixa_salarial(NoJogador* inicio_lista) {
    float min, max;
    int encontrados = 0;
    limpar_tela();
    printf("--- Localizar jogadores por faixa Salarial ---\n");
    printf("Digite o salario minimo: ");
    scanf("%f", &min);
    printf("Digite o salario maximo: ");
    scanf("%f", &max);
    getchar();

    printf("\nJogadores com salario entre R$ %.2f e R$ %.2f:\n", min, max);
    NoJogador* atual = inicio_lista;
    while(atual != NULL) {
        if (atual->dados.salario >= min && atual->dados.salario <= max) {
            printf("- %s (Salario: R$ %.2f)\n", atual->dados.nome, atual->dados.salario);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0) {
        printf("\nNenhum jogador encontrado nesta faixa salarial.\n");
    }
    pausar_sistema();
}

void localizar_jogador_maior_salario(NoJogador* inicio_lista) {
    limpar_tela();
    printf("--- Localizar Jogador com Maior Salario ---\n");
    if (inicio_lista == NULL) {
        printf("\nNenhum jogador cadastrado.\n");
        pausar_sistema();
        return;
    }

    NoJogador* jogador_maior_salario = inicio_lista;
    NoJogador* atual = inicio_lista->proximo;

    while (atual != NULL) {
        if (atual->dados.salario > jogador_maior_salario->dados.salario) {
            jogador_maior_salario = atual;
        }
        atual = atual->proximo;
    }

    printf("\nJogador com o maior salario encontrado:\n");
    mostrar_jogador_detalhado(jogador_maior_salario);
    pausar_sistema();
}

void localizar_jogadores_por_idade(NoJogador* inicio_lista) {
    int min, max, encontrados = 0;
    limpar_tela();
    printf("--- Localizar Jogadores por Faixa de Idade ---\n");
    printf("Digite a idade minima: ");
    scanf("%d", &min);
    printf("Digite a idade maxima: ");
    scanf("%d", &max);
    getchar();

    printf("\nJogadores com idade entre %d e %d anos:\n", min, max);
    NoJogador* atual = inicio_lista;
    while(atual != NULL) {
        if (atual->dados.idade >= min && atual->dados.idade <= max) {
            printf("- %s (Idade: %d)\n", atual->dados.nome, atual->dados.idade);
            encontrados++;
        }
        atual = atual->proximo;
    }
    if (encontrados == 0) {
        printf("\nNenhum jogador encontrado nesta faixa de idade.\n");
    }
    pausar_sistema();
}



void localizar_jogos_por_adversario(NoPartida* inicio_lista) {
    char adversario_busca[MAX_ADVERSARIO];
    int encontrados = 0;
    limpar_tela();
    printf("--- Localizar Jogos por Adversario ---\n");
    printf("Digite o nome do adversario: ");
    fgets(adversario_busca, MAX_ADVERSARIO, stdin);
    retirar_enter(adversario_busca);
    to_upper(adversario_busca);

    printf("\nJogos contra '%s':\n", adversario_busca);
    NoPartida* atual = inicio_lista;
    while (atual != NULL) {
        if (strcmp(atual->dados.adversario, adversario_busca) == 0) {
            mostrar_partida_detalhada(atual);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0) {
        printf("\nNenhum jogo encontrado contra esse time que vc mencionou.\n");
    }
    pausar_sistema();
}