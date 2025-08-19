#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
typedef struct Filme{
    
    char id[10];
    char titulo[99];
    int restricao_assinatura;
    int restricao_de_idade;
    float nota_media;
    int ano;//ano de lancamento
    int duracao;//tempo de duracao do filme
    
    char idioma[3];//se o filme e dublado ou legendado
    

} tFilme;

/// @brief Retorna o ano de lançamento de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return O ano de lançamento do filme
int getAnoLancamentoFilme(void *dado){
   if(!dado){
        return -1;
    }
    tFilme* Filme=(tFilme*)dado;
    return Filme->ano;
}

/// @brief Retorna o codigo (id único) de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return O codigo (id único) do filme
char* getCodConteudoFilme(void *dado){
    if(dado==NULL){
        return NULL;
    }
    tFilme* Filme=(tFilme*)dado;
    return Filme->id;
}

/// @brief Retorna o título de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return O título do filme
char* getTituloFilme(void *dado){
    if(dado==NULL){
        return NULL;
    }
    tFilme* Filme=(tFilme*)dado;
    return Filme->titulo;
}
/// @brief Retorna a duração de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return A duração do filme
int getDuracaoFilme(void *dado){
    if(dado==NULL){
        return -1;
    }

    tFilme* Filme=(tFilme*)dado;
    return Filme->duracao;
}

/// @brief Retorna a nota média de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return A nota média do filme
float getNotaMediaFilme(void *dado){
    if(dado==NULL){
        return -1;
    }
    tFilme* Filme=(tFilme*)dado;
    return Filme->nota_media;
}

/// @brief Função que imprime as informações de um filme conforme especificação do trabalho
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
void printaFilme(void *dado){
    if (dado == NULL) {
        return;
    }
    tFilme* filme = (tFilme*)dado;
    printf("F;%s;%s;%d;%d;%.1f;%d;%d;%s",
           filme->id,
           filme->titulo,
           filme->restricao_assinatura,
           filme->restricao_de_idade,
           filme->nota_media,
           filme->ano,
           filme->duracao,
           filme->idioma);
}


/// @brief Cria uma variável do tipo tFilme
/// @param linhaFilme - A string lida do teclado com as informações de um filme 
/// @return O objeto criado
tFilme* criaFilme(char *linhaFilme){
    tFilme* filme = (tFilme*)malloc(sizeof(tFilme));
    if (filme == NULL) {
        return NULL;
    }
    
    sscanf(linhaFilme, "%9[^;];%99[^;];%d;%d;%f;%d;%d;%2[^;];%2s",
           filme->id,
           filme->titulo,
           &filme->restricao_assinatura,
           &filme->restricao_de_idade,
           &filme->nota_media,
           &filme->ano,
           &filme->duracao,
           filme->idioma);
    
    return filme;
}
    


/// @brief Retorna o tipo de assinatura de um filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return O tipo da assinatura do filme (olhar util.h/.c)
TipoAssinatura getRestricaoAssinaturaFilme(void *dado){
    if (dado == NULL) {
        return NULL; // Ou outro valor padrão (se aplicável)
    }
    tFilme* filme = (tFilme*)dado;
    return filme->restricao_assinatura;
    
}

/// @brief Retorna o tipo de um filme
/// @return o caractere usado para representar um filme: 'F'
char getTipoFilme(){
    return 'F'; // Retorna o tipo fixo 'F' para filme
}
    
/// @brief Retorna o tipo do usuario que pode assistir ao filme
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme*
/// @return O tipo do usuario que pode assistir ao filme (olhar util.h/.c)
TipoUsuario getRestricaoIdadeFilme(void *dado){
    if(dado==NULL){
        return -1;
    }
    tFilme* Filme=(tFilme*)dado;
    return Filme->restricao_assinatura;
}

/// @brief Função que libera a memória alocada dinamicamente para armazenar um filmea
/// @param dado Um ponteiro para um dado genérico, que deve ser convertido para tFilme* e posteriormente liberado
void liberaFilme(void *dado){
    if(dado==NULL){
        return;
    }
    tFilme* Filme=(tFilme*)dado;
    free(dado);
    
}