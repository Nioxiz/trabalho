#ifndef _SERIE_H
#define _SERIE_H

#include "util.h"

typedef struct Serie tSerie;

/// @brief Retorna o ano de lançamento de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O ano de lançamento da série
int getAnoLancamentoSerie(void *dado);

/// @brief Retorna o codigo (id único) de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O codigo (id único) da série
char* getCodConteudoSerie(void *dado);

/// @brief Retorna o título de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O título da série
char* getTituloSerie(void *dado);

/// @brief Retorna o número total de episódios de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O número total de episódios
int getTotalEpisodiosSerie(void *dado);

/// @brief Retorna a nota média de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return A nota média da série
float getNotaMediaSerie(void *dado);

/// @brief Função que imprime as informações de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
void printaSerie(void *dado);

/// @brief Cria uma variável do tipo tSerie
/// @param linhaSerie - A string com as informações de uma série
/// @return O objeto criado
tSerie* criaSerie(char *linhaSerie);

/// @brief Retorna o tipo de assinatura de uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O tipo da assinatura da série
TipoAssinatura getRestricaoAssinaturaSerie(void *dado);

/// @brief Retorna o tipo de uma série
/// @return o caractere usado para representar uma série: 'S'
char getTipoSerie();

/// @brief Retorna o tipo do usuario que pode assistir à série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
/// @return O tipo do usuario que pode assistir à série
TipoUsuario getRestricaoIdadeSerie(void *dado);

/// @brief Função que libera a memória alocada para uma série
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tSerie*
void liberaSerie(void *dado);

#endif