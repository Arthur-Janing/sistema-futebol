#ifndef TYPES_H
#define TYPES_H


#define MAX_NOME 50
#define MAX_POSICAO 30
#define MAX_MOTIVO 100
#define MAX_ADVERSARIO 50
#define MAX_LOCAL 100
#define MAX_ESCALADOS 500

//Jogadores
typedef struct {
    char nome[MAX_NOME];
    int idade;
    float altura;
    float peso;
    char posicao[MAX_POSICAO];
    float valor_passe;
    float valor_aquisicao;
    float salario;
    int status;
    char motivo[MAX_MOTIVO];
} DadosJogador;

typedef struct NoJogador {
    DadosJogador dados;
    struct NoJogador *proximo;
} NoJogador;


typedef struct {
    NoJogador* inicio_lista;
    int quantidade;
} ListaJogadores;

//Partidas
typedef struct {
    char adversario[MAX_ADVERSARIO];
    char data[12];
    char local[MAX_LOCAL];
    char placar[10];
    char resultado[10];
    char escalados[MAX_ESCALADOS];
    int substituicoes;
} DadosPartida;

typedef struct NoPartida {
    DadosPartida dados;
    struct NoPartida *proximo;
} NoPartida;


typedef struct {
    NoPartida* inicio_lista;  
    int quantidade;
} ListaPartidas;

#endif 
