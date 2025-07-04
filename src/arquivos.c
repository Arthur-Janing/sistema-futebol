#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/arquivos.h"
#include "../include/cadastros.h"
#include "../include/utils.h"


void salvar_jogadores_bin(NoJogador *comeco_lista) {
    FILE *fp = fopen("jogadores.bin", "wb");
    if (fp == NULL) return;
    NoJogador *atual = comeco_lista;
    while (atual != NULL) {
        fwrite(&(atual->dados), sizeof(DadosJogador), 1, fp);
        atual = atual->proximo;
    }
    fclose(fp);
}

void carregar_jogadores_bin(ListaJogadores *lista) {
    FILE *fp = fopen("jogadores.bin", "rb");
    if (fp == NULL) return;
    DadosJogador dados_temp;
    while (fread(&dados_temp, sizeof(DadosJogador), 1, fp) == 1) {
        NoJogador *novo_no = (NoJogador *)malloc(sizeof(NoJogador));
        if (novo_no) {
            novo_no->dados = dados_temp;
            novo_no->proximo = NULL;
            inserir_jogador_no_inicio(lista, novo_no);
        }
    }
    fclose(fp);
}

void salvar_partidas_bin(NoPartida *comeco_lista) {
    FILE *fp = fopen("partidas.bin", "wb");
    if (fp == NULL) return;
    NoPartida *atual = comeco_lista;
    while (atual != NULL) {
        fwrite(&(atual->dados), sizeof(DadosPartida), 1, fp);
        atual = atual->proximo;
    }
    fclose(fp);
}

void carregar_partidas_bin(ListaPartidas *lista) {
    FILE *fp = fopen("partidas.bin", "rb");
    if (fp == NULL) return;
    DadosPartida dados_temp;
    while (fread(&dados_temp, sizeof(DadosPartida), 1, fp) == 1) {
        NoPartida *novo_no = (NoPartida *)malloc(sizeof(NoPartida));
        if (novo_no) {
            novo_no->dados = dados_temp;
            novo_no->proximo = NULL;
            inserir_partida_no_inicio(lista, novo_no);
        }
    }
    fclose(fp);
}



void exportar_jogadores_csv(const char* nome_arquivo, NoJogador* comeco_lista) {
    FILE* fp = fopen(nome_arquivo, "w");
    if (!fp) {
        printf("erro ao criar arquivo\n");
        return;
    }
    fprintf(fp, "Nome;Posicao;Idade;Salario;Status\n");
    NoJogador* atual = comeco_lista;
    while (atual) {
        fprintf(fp, "%s;%s;%d;%.2f;%s\n",
                atual->dados.nome, atual->dados.posicao, atual->dados.idade,
                atual->dados.salario, (atual->dados.status == 1) ? "ATIVO" : "INATIVO");
        atual = atual->proximo;
    }
    fclose(fp);
    printf("Arquivo gerado\n");
}

void exportar_jogadores_html(const char* nome_arquivo, NoJogador* comeco_lista) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        printf("Erro ao criar arquivo\n");
        return;
    }
    fprintf(fp, "<html><body><table><tr><td><h1>Nome do Jogador</h1></td><td><h1>Posicao</h1></td><td><h1>Salario</h1></td></tr>\n");
    NoJogador* atual = comeco_lista;
    while (atual) {
        fprintf(fp, "<tr><td><p>%s</p></td><td><p>%s</p></td><td><p>%.2f</p></td></tr>\n",
                atual->dados.nome, atual->dados.posicao, atual->dados.salario);
        atual = atual->proximo;
    }
    fprintf(fp, "</table></body></html>");
    fclose(fp);
    printf("Arquivo gerado\n");
}

void exportar_partidas_csv(const char* nome_arquivo, NoPartida* comeco_lista) {
    FILE* fp = fopen(nome_arquivo, "w");
    if (!fp) {
        printf("erro.\n");
        return;
    }
    fprintf(fp, "Adversario;Data;Local;Placar;Resultado\n");
    NoPartida* atual = comeco_lista;
    while (atual) {
        fprintf(fp, "%s;%s;%s;%s;%s\n",
                atual->dados.adversario, atual->dados.data, atual->dados.local,
                atual->dados.placar, atual->dados.resultado);
        atual = atual->proximo;
    }
    fclose(fp);
    printf("Arquivo gerado\n");
}

void exportar_partidas_html(const char* nome_arquivo, NoPartida* comeco_lista) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        printf("erro ao criar arquivo\n");
        return;
    }
    fprintf(fp, "<html><body><table><tr><td><h1>Adversario</h1></td><td><h1>Data</h1></td><td><h1>Placar</h1></td></tr>\n");
    NoPartida* atual = comeco_lista;
    while (atual) {
        fprintf(fp, "<tr><td><p>%s</p></td><td><p>%s</p></td><td><p>%s</p></td></tr>\n",
                atual->dados.adversario, atual->dados.data, atual->dados.placar);
        atual = atual->proximo;
    }
    fprintf(fp, "</table></body></html>");
    fclose(fp);
    
    printf("Arquivo gerado\n");
}