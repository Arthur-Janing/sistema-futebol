#include <stdio.h>
#include <string.h>
#include "../include/relatorios.h"
#include "../include/utils.h"


void mostrar_jogador_detalhado(NoJogador* jogador) {
    if (jogador == NULL) return;

    printf("Nome: %s\n", jogador->dados.nome);
    printf("Idade: %d\n", jogador->dados.idade);
    printf("Posicao: %s\n", jogador->dados.posicao);
    printf("Salario: R$ %.2f\n", jogador->dados.salario);
    printf("Valor do Passe: R$ %.2f\n", jogador->dados.valor_passe);

    if (jogador->dados.status == 1) {
        printf("Status: Ativo\n");
    } else {
        printf("Status: Inativo\n");
    }

    if (jogador->dados.status == 0) {
        printf("Motivo da Inatividade : %s\n", jogador->dados.motivo);
    }
}


void relatorio_completo_jogadores(NoJogador* inicio_lista) {
    limpar_tela();
    printf("======= Relatorio Completo de Jogadores =======\n");

    if (inicio_lista == NULL) {
        printf("\nNenhum jogador foi cadastrado.\n");
    } else {
        NoJogador* atual = inicio_lista;
        while(atual != NULL) {
            mostrar_jogador_detalhado(atual);
            printf("\n\n"); 
            atual = atual->proximo;
        }
        printf("----------------------------------------\n");
    }
    pausar_sistema();
}

void relatorio_jogadores_vendidos(NoJogador* inicio_lista) {
    limpar_tela();
    printf("======= Relatorio de Jogadores Vendidos =======\n");
    int encontrados = 0;
    NoJogador* atual = inicio_lista;

    while (atual != NULL) {
        if (atual->dados.status == 0 && strcmp(atual->dados.motivo, "VENDIDO") == 0) {
            printf("Nome: %s, Valor do Passe: R$ %.2f\n", atual->dados.nome, atual->dados.valor_passe);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0) {
        printf("\nNenhum jogador foi vendido.\n");
    } else {
        printf("\nTotal de jogadores vendidos: %d\n", encontrados);
    }
    pausar_sistema();
}

void relatorio_valor_time(NoJogador* inicio_lista) {
    limpar_tela();
    printf("======= Relatorio de Valor do Time (Jogadores Ativos) =======\n");
    float valor_total = 0.0;
    int jogadores_ativos = 0;
    NoJogador* atual = inicio_lista;

    while (atual != NULL) {
        if (atual->dados.status == 1) {
            valor_total += atual->dados.valor_passe;
            jogadores_ativos++;
        }
        atual = atual->proximo;
    }

    if (jogadores_ativos == 0) {
        printf("\nNenhum jogador ativo no time.\n");
    } else {
        printf("Numero de jogadores ativos: %d\n", jogadores_ativos);
        printf("Valor total do time: R$ %.2f\n", valor_total);
    }
    pausar_sistema();
}



void mostrar_partida_detalhada(NoPartida* partida) {
    if (partida == NULL) return;

    printf("----------------------------------------\n");
    printf("Adversario: %s\n", partida->dados.adversario);
    printf("Data: %s\n", partida->dados.data);
    printf("Local: %s\n", partida->dados.local);
    printf("Placar: %s\n", partida->dados.placar);
    printf("Resultado: %s\n", partida->dados.resultado);
}

void relatorio_completo_partidas(NoPartida* inicio_lista) {
    limpar_tela();
    printf("======= Relatorio Completo de Partidas =======\n");

     if (inicio_lista == NULL) {
        printf("\nNenhuma partida foi cadastrada n sistema.\n");
    } else {
        NoPartida* atual = inicio_lista;
        while(atual != NULL) {
            mostrar_partida_detalhada(atual);
            printf("\n\n"); 
            atual = atual->proximo;
        }
        printf("----------------------------------------\n");
    }
    pausar_sistema();
}

void relatorio_aproveitamento_time(NoPartida* inicio_lista) {
    limpar_tela();
    printf("======= Relatorio de Aproveitamento do Time =======\n");
    int vitorias = 0, empates = 0, derrotas = 0, total_jogos = 0;
    NoPartida* atual = inicio_lista;

    while (atual != NULL) {
        total_jogos++;
        if (strcmp(atual->dados.resultado, "VITORIA") == 0) {
            vitorias++;
        } else if (strcmp(atual->dados.resultado, "EMPATE") == 0) {
            empates++;
        } else if (strcmp(atual->dados.resultado, "DERROTA") == 0) {
            derrotas++;
        }
        atual = atual->proximo;
    }

    if (total_jogos == 0) {
        printf("\nNenhuma partida cadastrada para eu conseguir calcular o aproveitamento.\n");
    } else {
        float aproveitamento = ((float)vitorias * 3 + (float)empates * 1) / ((float)total_jogos * 3) * 100;
        printf("Total de jogos: %d\n", total_jogos);
        printf("Vitorias: %d\n", vitorias);
        printf("Empates: %d\n", empates);
        printf("Derrotas: %d\n", derrotas);
        printf("Aproveitamento de pontos: %.2f%%\n", aproveitamento);
    }
    pausar_sistema();
}