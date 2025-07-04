#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "types.h"

//salvar dados em formato b
void salvar_jogadores_bin(NoJogador *comeco_lista);
void carregar_jogadores_bin(ListaJogadores *lista);
void salvar_partidas_bin(NoPartida *comeco_lista);
void carregar_partidas_bin(ListaPartidas *lista);

//dados para outro formato
void exportar_jogadores_csv(const char* nome_arquivo, NoJogador* comeco_lista);
void exportar_jogadores_html(const char* nome_arquivo, NoJogador* comeco_lista);
void exportar_partidas_csv(const char* nome_arquivo, NoPartida* comeco_lista);
void exportar_partidas_html(const char* nome_arquivo, NoPartida* comeco_lista);

#endif 