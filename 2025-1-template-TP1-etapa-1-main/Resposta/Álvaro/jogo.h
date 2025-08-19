#ifndef _JOGO_H
#define _JOGO_H

#include "util.h"

typedef struct Jogo tJogo;
char getDesenvolvedora(void *dado);
char getCategoria(void *dado);
/// @brief Retorna o ano de lançamento de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O ano de lançamento do jogo
int getAnoLancamentoJogo(void *dado);

/// @brief Retorna o codigo (id único) de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O codigo (id único) do jogo
char* getCodConteudoJogo(void *dado);

/// @brief Retorna o título de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O título do jogo
char* getTituloJogo(void *dado);

/// @brief Retorna a duração média de um jogo (em horas)
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return A duração média do jogo
int getDuracaoJogo(void *dado);

/// @brief Retorna a nota média de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return A nota média do jogo
float getNotaMediaJogo(void *dado);

/// @brief Função que imprime as informações de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
void printaJogo(void *dado);

/// @brief Cria uma variável do tipo tJogo
/// @param linhaJogo - A string com as informações de um jogo 
/// @return O objeto criado
tJogo* criaJogo(char *linhaJogo);

/// @brief Retorna o tipo de assinatura de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O tipo da assinatura do jogo
TipoAssinatura getRestricaoAssinaturaJogo(void *dado);

/// @brief Retorna o tipo de um jogo
/// @return o caractere usado para representar um jogo: 'J'
char getTipoJogo();

/// @brief Retorna o tipo do usuario que pode jogar
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O tipo do usuario que pode jogar
TipoUsuario getRestricaoIdadeJogo(void *dado);

/// @brief Função que libera a memória alocada para um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
void liberaJogo(void *dado);

#endif