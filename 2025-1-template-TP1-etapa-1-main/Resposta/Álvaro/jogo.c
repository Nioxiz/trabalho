#include "util.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogo {
    char id[10];
    char titulo[99];
    int restricao_assinatura;
    int restricao_de_idade;
    float nota_media;
    int ano;
    int duracao;
    char categoria[16];
    char idioma[3];
    char desenvolvedora[19];
}tJogo;

/// @brief Retorna o ano de lançamento de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O ano de lançamento do jogo
char getDesenvolvedora(void *dado){
    if(!dado){
        return -1;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->desenvolvedora;
}
char getCategoria(void *dado){
    if(!dado){
        return -1;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->categoria;
}

int getAnoLancamentoJogo(void *dado){
    if(!dado){
        return -1;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->ano;
}

/// @brief Retorna o codigo (id único) de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O codigo (id único) do jogo
char* getCodConteudoJogo(void *dado){
    if(!dado){
        return NULL;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->id;
}

/// @brief Retorna o título de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O título do jogo
char* getTituloJogo(void *dado){
    if(!dado){
        return NULL;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->titulo;
}

/// @brief Retorna a duração média de um jogo (em horas)
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return A duração média do jogo
int getDuracaoJogo(void *dado){
    if(!dado){
        return -1;
    }

    tJogo* Jogo=(tJogo*)dado;
    return Jogo->duracao;
}

/// @brief Retorna a nota média de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return A nota média do jogo
float getNotaMediaJogo(void *dado){
    if(dado==NULL){
        return -1;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->nota_media;
}

/// @brief Função que imprime as informações de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
void printaJogo(void *dado){
    if (!dado) {
        return;
    }
    tJogo* Jogo = (tJogo*)dado;
    printf("J;%s;%s;%d;%d;%.1f;%d;%d;%s;%s",
           Jogo->id,
           Jogo->titulo,
           Jogo->restricao_assinatura,
           Jogo->restricao_de_idade,
           Jogo->nota_media,
           Jogo->ano,
           Jogo->duracao,
           Jogo->categoria,
            Jogo->desenvolvedora);
}

/// @brief Cria uma variável do tipo tJogo
/// @param linhaJogo - A string com as informações de um jogo 
/// @return O objeto criado
tJogo* criaJogo(char *linhaJogo){
    tJogo* Jogo=(tJogo*)malloc(sizeof(tJogo));
    sscanf(linhaJogo, "%9[^;];%99[^;];%d;%d;%f;%d;%d;%2[^;];%20[^/n]",
           Jogo->id,
           Jogo->titulo,
           &Jogo->restricao_assinatura,
           &Jogo->restricao_de_idade,
           &Jogo->nota_media,
           &Jogo->ano,
           &Jogo->duracao,
           Jogo->categoria);
}

/// @brief Retorna o tipo de assinatura de um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O tipo da assinatura do jogo
TipoAssinatura getRestricaoAssinaturaJogo(void *dado){
    if (dado == NULL) {
        return NULL; // Ou outro valor padrão (se aplicável)
    }
    tJogo* Jogo = (tJogo*)dado;
    return Jogo->restricao_assinatura;
}

/// @brief Retorna o tipo de um jogo
/// @return o caractere usado para representar um jogo: 'J'
char getTipoJogo(){
    return 'J';
}

/// @brief Retorna o tipo do usuario que pode jogar
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
/// @return O tipo do usuario que pode jogar
TipoUsuario getRestricaoIdadeJogo(void *dado){
    if(!dado){
        return -1;
    }
    tJogo* Jogo=(tJogo*)dado;
    return Jogo->restricao_assinatura;
}

/// @brief Função que libera a memória alocada para um jogo
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tJogo*
void liberaJogo(void *dado){
    if(dado==NULL){
        return;
    }
    tJogo* Jogo=(tJogo*)dado;
    free(dado);
}