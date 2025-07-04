#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "include/types.h"
#include "include/menus.h"
#include "include/utils.h"
#include "include/cadastros.h"
#include "include/relatorios.h"
#include "include/consultas.h"
#include "include/arquivos.h"

int main() {
    ListaJogadores lista_jogadores;
    ListaPartidas lista_partidas;
    int opcao;
    char nome_arquivo[100];

    // funcao de iniciar
    inicializa_lista_jogadores(&lista_jogadores);
    inicializa_lista_partidas(&lista_partidas);

    // Carrega dados salvos ao iniciar
    carregar_jogadores_bin(&lista_jogadores);
    carregar_partidas_bin(&lista_partidas);

    do {
        opcao = menu_principal();

        switch (opcao) {
            case 1: // Cadastros
                do {
                    opcao = menu_cadastros();
                    switch (opcao) {
                        case 1: cadastrar_jogador(&lista_jogadores); break;
                        case 2: cadastrar_partida(&lista_partidas, &lista_jogadores); break;
                        case 0: break; 
                        default: printf("Opcao invalida!\n"); pausar_sistema(); break;
                    }
                } while (opcao != 0);
                opcao = -1; 
                break;
            case 2: // Relatórios
                do {
                    opcao = menu_relatorios();
                    switch (opcao) {
                        case 1: relatorio_completo_jogadores(lista_jogadores.inicio_lista); break;
                        case 2: relatorio_jogadores_vendidos(lista_jogadores.inicio_lista); break;
                        case 3: relatorio_valor_time(lista_jogadores.inicio_lista); break;
                        case 4: relatorio_completo_partidas(lista_partidas.inicio_lista); break;
                        case 5: relatorio_aproveitamento_time(lista_partidas.inicio_lista); break;
                        case 0: break; 
                        default: printf("Opcao invalida!\n"); pausar_sistema(); break;
                    }
                } while (opcao != 0);
                opcao = -1;
                break;
            case 3: // Consultas
                do {
                    opcao = menu_consultas();
                    switch (opcao) {
                        case 1: consulta_e_mostra_jogador_por_nome(lista_jogadores.inicio_lista); break;
                        case 2: localizar_jogadores_por_posicao(lista_jogadores.inicio_lista); break;
                        case 3: localizar_jogadores_por_faixa_salarial(lista_jogadores.inicio_lista); break;
                        case 4: localizar_jogador_maior_salario(lista_jogadores.inicio_lista); break;
                        case 5: localizar_jogadores_por_idade(lista_jogadores.inicio_lista); break;
                        case 6: localizar_jogos_por_adversario(lista_partidas.inicio_lista); break;
                        case 0: break; 
                        default: printf("Opcao invalida!\n"); pausar_sistema(); break;
                    }
                } while (opcao != 0);
                opcao = -1;
                break;
            case 4: // Exportar
                do {
                    
                    opcao = menu_exportar();
                    switch (opcao) {
                        case 1:
                            printf("Qual o nome do arquivo de saida (ex: jogadores.csv)? ");
                            fgets(nome_arquivo, 100, stdin);
                            retirar_enter(nome_arquivo);
                            exportar_jogadores_csv(nome_arquivo, lista_jogadores.inicio_lista);
                            pausar_sistema();
                            break;
                        case 2:
                            printf("Qual o nome do arquivo de saida (ex: jogadores.html)? ");
                            fgets(nome_arquivo, 100, stdin);
                            retirar_enter(nome_arquivo);
                            exportar_jogadores_html(nome_arquivo, lista_jogadores.inicio_lista);
                            pausar_sistema();
                            break;
                        case 3:
                            printf("Qual o nome do arquivo de saida (ex: partidas.csv)? ");
                            fgets(nome_arquivo, 100, stdin);
                            retirar_enter(nome_arquivo);
                            exportar_partidas_csv(nome_arquivo, lista_partidas.inicio_lista);
                            pausar_sistema();
                            break;
                        case 4:
                            printf("Qual o nome do arquivo de saida (ex: partidas.html)? ");
                            fgets(nome_arquivo, 100, stdin);
                            retirar_enter(nome_arquivo);
                            exportar_partidas_html(nome_arquivo, lista_partidas.inicio_lista);
                            pausar_sistema();
                            break;
                        case 0: break; 
                        default: printf("Opcao invalida!\n"); pausar_sistema(); break;
                    }
                } while (opcao != 0);
                opcao = -1;
                break;
            case 0:
                printf("Saindo\n");
                salvar_jogadores_bin(lista_jogadores.inicio_lista);
                salvar_partidas_bin(lista_partidas.inicio_lista);
                break;
            default:
                printf("Opcao nao foi encontrada\n");
                pausar_sistema();
                break;
        }
    } while (opcao != 0);

    // Libera memória dos jogadores
    NoJogador *atual_j = lista_jogadores.inicio_lista;
    while (atual_j != NULL) {
        NoJogador *temp = atual_j;
        atual_j = atual_j->proximo;
        free(temp);
    }

    // Libera memória das partidas
    NoPartida *atual_p = lista_partidas.inicio_lista;
    while (atual_p != NULL) {
        NoPartida *temp = atual_p;
        atual_p = atual_p->proximo;
        free(temp);
    }

    return 0;
}