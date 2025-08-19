#include "serie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
typedef struct Serie {
        char id[10];
    char titulo[99];
    int restricao_assinatura;
    int restricao_de_idade;
    float nota_media;
    int ano;//ano de lancamento
    int duracao;//tempo de duracao do filme
    
    char idioma[3];//se o filme e dublado ou legendado

}tSerie;
/// @brief Retorna o ano de lançamento de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O ano de lançamento da série
int getAnoLancamentoSerie(void *dado){
    if(!dado){
        return -1;
    }
    tSerie* Serie=(tSerie*)dado;
    return Serie->ano;
}

/// @brief Retorna o codigo (id único) de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O codigo (id único) da série
char* getCodConteudoSerie(void *dado){
    if(!dado){
        return -1;
    }
    tSerie* Serie=(tSerie*)dado;
    return Serie->id;
}

/// @brief Retorna o título de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O título da série
char* getTituloSerie(void *dado){
    if(dado==NULL){
        return NULL;
    }
    tSerie* Serie=(tSerie*)dado;
    return Serie->titulo;
}

/// @brief Retorna o número total de episódios de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O número total de episódios
int getTotalEpisodiosSerie(void *dado){
    if(dado==NULL){
        return -1;
    }

    tSerie* Serie=(tSerie*)dado;
    return Serie->duracao;
}

/// @brief Retorna a nota média de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return A nota média da série
float getNotaMediaSerie(void *dado){
    if(dado==NULL){
        return -1;
    }
    tSerie* Serie=(tSerie*)dado;
    return Serie->nota_media;    
}

/// @brief Função que imprime as informações de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
void printaSerie(void *dado){

}

/// @brief Cria uma variável do tipo tSerie
/// @param linhaSerie - A string com as informações de uma série
/// @return O objeto criado
tSerie* criaSerie(char *linhaSerie){

}

/// @brief Retorna o tipo de assinatura de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O tipo da assinatura da série
TipoAssinatura getRestricaoAssinaturaSerie(void *dado){
    if (dado == NULL) {
        return NULL; // Ou outro valor padrão (se aplicável)
    }
    tSerie* Serie = (tSerie*)dado;
    return Serie->restricao_assinatura;
}

/// @brief Retorna o tipo de uma série
/// @return o caractere usado para representar uma série: 'S'
char getTipoSerie(){
    return 'F';
}

/// @brief Retorna o tipo do usuario que pode assistir à série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O tipo do usuario que pode assistir à série
TipoUsuario getRestricaoIdadeSerie(void *dado){
    if(dado==NULL){
        return -1;
    }
    tSerie* Serie=(tSerie*)dado;
    return Serie->restricao_assinatura;    
}

/// @brief Função que libera a memória alocada para uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
void liberaSerie(void *dado){
    if(dado==NULL){
        return;
    }
    tSerie* Serie=(tSerie*)dado;
    free(dado);
    
}
