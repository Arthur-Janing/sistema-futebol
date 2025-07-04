#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cadastros.h"
#include "../include/consultas.h"
#include "../include/utils.h"

void inicializa_lista_jogadores(ListaJogadores* lista) {
    lista->inicio_lista = NULL;
    lista->quantidade = 0;
}

void inicializa_lista_partidas(ListaPartidas* lista) {
    lista->inicio_lista = NULL;
    lista->quantidade = 0;
}


void inserir_partida_no_inicio(ListaPartidas* lista, NoPartida* novo_no) {
    novo_no->proximo = lista->inicio_lista;
    lista->inicio_lista = novo_no;
    lista->quantidade++;
}


void inserir_jogador_no_inicio(ListaJogadores* lista, NoJogador* novo_no) {
    novo_no->proximo = lista->inicio_lista;
    lista->inicio_lista = novo_no;
    lista->quantidade++;
}


void cadastrar_jogador(ListaJogadores* lista) {
    NoJogador *novo_no = (NoJogador *)malloc(sizeof(NoJogador));
    if (novo_no == NULL) {
        printf("rrro ao alocar memoria na rip\n");
        return;
    }

    limpar_tela();
    printf("--- Cadastro de Novo Jogador ---\n");

    printf("Digite o nome do jogador: ");
    fgets(novo_no->dados.nome, MAX_NOME, stdin);
    retirar_enter(novo_no->dados.nome);
    to_upper(novo_no->dados.nome);

    printf("Digite a idade: ");
    scanf("%d", &novo_no->dados.idade);
    getchar();

    printf("Digite a altura : ");
    scanf("%f", &novo_no->dados.altura);
    getchar();

    printf("Digite o peso : ");
    scanf("%f", &novo_no->dados.peso);
    getchar();

    printf("Digite a posicao: ");
    fgets(novo_no->dados.posicao, MAX_POSICAO, stdin);
    retirar_enter(novo_no->dados.posicao);
    to_upper(novo_no->dados.posicao);

    printf("Digite o valor do passe: ");
    scanf("%f", &novo_no->dados.valor_passe);
    getchar();

    printf("Digite o valor de aquisicao: ");
    scanf("%f", &novo_no->dados.valor_aquisicao);
    getchar();

    printf("Digite o salario: ");
    scanf("%f", &novo_no->dados.salario);
    getchar();

    printf("Status do jogador (1 - Ativo, 0 - Inativo): ");
    scanf("%d", &novo_no->dados.status);
    getchar();

    if (novo_no->dados.status == 0) {
        printf("Digite o motivo da inatividade ( VENDIDO ou RECUPERACAO): ");
        fgets(novo_no->dados.motivo, MAX_MOTIVO, stdin);
        retirar_enter(novo_no->dados.motivo);
        to_upper(novo_no->dados.motivo);
    } else {
        strcpy(novo_no->dados.motivo, "N/A");
    }

    novo_no->proximo = NULL;

    inserir_jogador_no_inicio(lista, novo_no);

    printf("\nJogador cadastrado\n");
    pausar_sistema();
}


void cadastrar_partida(ListaPartidas* lista_partidas, ListaJogadores* lista_jogadores) {
    char escalacao_completa[MAX_ESCALADOS];
    int jogadores_validos = 0;

    limpar_tela();
    printf("--- Cadastro de Partida ---\n");
    
    printf("Digite a escalacao (os nomes devem ser separados por virgula): ");
    fgets(escalacao_completa, MAX_ESCALADOS, stdin);
    retirar_enter(escalacao_completa);

    char nome_jogador_atual[MAX_NOME];
    int nome_atual = 0;

    for (int i = 0; i <= strlen(escalacao_completa); i++) {
        if (escalacao_completa[i] == ',' || escalacao_completa[i] == '\0') {
            nome_jogador_atual[nome_atual] = '\0';

            // Limpa espaços em branco do início
            int inicio_nome = 0;
            while (nome_jogador_atual[inicio_nome] == ' ') inicio_nome++;

            // Ponteiro para o nome limpo
            char *nome_limpo = &nome_jogador_atual[inicio_nome];

            // Limpa espaços em branco do final
            int len = strlen(nome_limpo);
            while (len > 0 && nome_limpo[len - 1] == ' ') nome_limpo[--len] = '\0';

            if (strlen(nome_limpo) > 0) {
                to_upper(nome_limpo);
                if (consulta_jogador_por_nome(lista_jogadores->inicio_lista, nome_limpo) == NULL) {
                    printf("\nO jogador \"%s\" nao esta cadastrado no sistema. Cadastre-o antes de prosseguir.\n", nome_limpo);
                    pausar_sistema();
                    return;
                }
                jogadores_validos++;
            }

            nome_atual = 0;
        } else {
            if (nome_atual < MAX_NOME - 1) {
                nome_jogador_atual[nome_atual] = escalacao_completa[i];
                nome_atual++;
            }
        }
    }

    if (jogadores_validos < 11) {
        printf("\nPrecisa escalar pelo menos 11 jogadores.\n");
        pausar_sistema();
        return; 
    }

    NoPartida *novo_no = (NoPartida *)malloc(sizeof(NoPartida));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para a nova partida.\n");
        pausar_sistema();
        return;
    }

    strcpy(novo_no->dados.escalados, escalacao_completa);

    printf("Digite o nome do time adversario: ");
    fgets(novo_no->dados.adversario, MAX_ADVERSARIO, stdin);
    retirar_enter(novo_no->dados.adversario);
    to_upper(novo_no->dados.adversario);

    printf("Digite a data da partida (xx/xx/xxxx): ");
    fgets(novo_no->dados.data, 12, stdin);
    retirar_enter(novo_no->dados.data);

    printf("Digite o local da partida: ");
    fgets(novo_no->dados.local, MAX_LOCAL, stdin);
    retirar_enter(novo_no->dados.local);
    to_upper(novo_no->dados.local);

    printf("Digite o placar da partida (ex: 2-1): ");
    fgets(novo_no->dados.placar, 10, stdin);
    retirar_enter(novo_no->dados.placar);

    printf("Digite o resultado (VITORIA, DERROTA ou EMPATE): ");
    fgets(novo_no->dados.resultado, 10, stdin);
    retirar_enter(novo_no->dados.resultado);
    to_upper(novo_no->dados.resultado);

    printf("Digite a quantidade de substituicoes: ");
    scanf("%d", &novo_no->dados.substituicoes);
    getchar();

    novo_no->proximo = NULL;
    inserir_partida_no_inicio(lista_partidas, novo_no);
    
    printf("\nPartida cadastrada com sucesso!\n");
    pausar_sistema();
}
