#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "types.h"


NoJogador* consulta_jogador_por_nome(NoJogador *inicio_lista, const char* nome);
void consulta_e_mostra_jogador_por_nome(NoJogador* inicio_lista);
void localizar_jogadores_por_posicao(NoJogador* inicio_lista);
void localizar_jogadores_por_faixa_salarial(NoJogador* inicio_lista);

void localizar_jogador_maior_salario(NoJogador* inicio_lista);
void localizar_jogadores_por_idade(NoJogador* inicio_lista);



void localizar_jogos_por_adversario(NoPartida* inicio_lista);

#endif