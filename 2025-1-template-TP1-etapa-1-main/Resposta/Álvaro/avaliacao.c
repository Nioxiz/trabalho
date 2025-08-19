#include "avaliacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Avaliacao {
    char cpf[15];
    int nota;
    
}tAvaliacao;


/// @brief Função que cria um objeto do tipo tAvaliação*
/// @param cpf - CPF da pessoa que fez a avaliação
/// @param nota - A nota que a pessoa deu
/// @return O objeto avaliação criado
tAvaliacao* criaAvaliacao(char* cpf, int nota){
    if (!cpf) return NULL;

    tAvaliacao* nova_avaliacao = (tAvaliacao*)malloc(sizeof(tAvaliacao));
    if (!nova_avaliacao) {
        return NULL;
    }
    strncpy(nova_avaliacao->cpf, cpf, 14); // Copia no máximo 14 caracteres
    return nova_avaliacao;
}
/// @brief Retorna a nota de uma avaliação
/// @param a 
/// @return A nota de uma avaliação
int getNotaAvaliacao(tAvaliacao *a){
    return a->nota;
}

/// @brief Retorna o CPF de quem fez aquela avaliação
/// @param a 
/// @return O CPF do responsável pela avaliação
char* getCpfAvaliacao(tAvaliacao *a){
    return a->cpf;
}

/// @brief Função que libera a memória alocada para uma avaliação
/// @param avaliacao um ponteiro para uma variável do tipo tAvaliacao
void liberaAvaliacao(tAvaliacao *avaliacao){
    free(avaliacao);
    
}