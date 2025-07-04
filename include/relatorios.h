#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "types.h"



//Relatorio de Jogador
void mostrar_jogador_detalhado(NoJogador* jogador);
void relatorio_completo_jogadores(NoJogador* inicio_lista);
void relatorio_jogadores_vendidos(NoJogador* inicio_lista);
void relatorio_valor_time(NoJogador* inicio_lista);



//Relatorios de partidas
void mostrar_partida_detalhada(NoPartida* partida);
void relatorio_completo_partidas(NoPartida* inicio_lista);
void relatorio_aproveitamento_time(NoPartida* inicio_lista);













#endif