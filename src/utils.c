#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#include "../include/utils.h"

void limpar_tela() {
    system("clear");
}


void pausar_sistema() {
    printf("\nAperte a tecla ENTER para continuar");
    getchar();
}


void retirar_enter(char str[]) {
    *(str + strlen(str) - 1) = '\0';
}

void to_upper(char str[]) {
    for (size_t i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}