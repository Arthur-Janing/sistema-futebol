#ifndef CADASTROS_H
#define CADASTROS_H

#include "types.h"


void cadastrar_jogador(ListaJogadores* lista);
void cadastrar_partida(ListaPartidas* lista_partidas, ListaJogadores* lista_jogadores);
void inserir_jogador_no_inicio(ListaJogadores* lista, NoJogador* novo_no);
void inserir_partida_no_inicio(ListaPartidas* lista, NoPartida* novo_no);
void inicializa_lista_jogadores(ListaJogadores* lista);
void inicializa_lista_partidas(ListaPartidas* lista);

#endif 