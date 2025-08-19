#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conteudo.h"
#include "avaliacao.h"

typedef struct Conteudo {
    void *dado;

    func_ptr_codConteudo codConteudo;
    func_ptr_titulo titulo;
    func_ptr_anoLancamento anoLancamento;
    func_ptr_notaMedia notaMedia;
    func_ptr_duracao duracao;
    func_ptr_printaConteudo printaConteudo;
    func_ptr_liberaConteudo liberaConteudo;
    func_ptr_restricaoConteudo restricaoConteudo;
    func_ptr_restricaoIdade restricaoIdade;
    func_ptr_tipoConteudo tipoConteudo;

    tAvaliacao **avaliacoes;
    int qtdAvaliacoes;
} tConteudo;  


tConteudo *criaConteudo(void *dado,
                        func_ptr_anoLancamento anoLancamento,
                        func_ptr_codConteudo codConteudo,
                        func_ptr_notaMedia notaMedia,
                        func_ptr_titulo titulo,
                        func_ptr_duracao duracao,
                        func_ptr_printaConteudo printaConteudo,
                        func_ptr_restricaoConteudo restricaoConteudo,
                        func_ptr_tipoConteudo tipoConteudo,
                        func_ptr_restricaoIdade restricaoIdade,
                        func_ptr_liberaConteudo liberaConteudo) {
    
    
    if (!dado || !anoLancamento || !codConteudo || !notaMedia || !titulo || 
        !duracao || !printaConteudo || !restricaoConteudo || !tipoConteudo || 
        !restricaoIdade || !liberaConteudo) {
        return NULL;
    }

    tConteudo *conteudo = malloc(sizeof(tConteudo));
    if (!conteudo) return NULL;

    conteudo->dado = dado;

    conteudo->anoLancamento = anoLancamento;
    conteudo->codConteudo = codConteudo;
    conteudo->notaMedia = notaMedia;
    conteudo->titulo = titulo;
    conteudo->duracao = duracao;
    conteudo->printaConteudo = printaConteudo;
    conteudo->restricaoConteudo = restricaoConteudo;
    conteudo->tipoConteudo = tipoConteudo;
    conteudo->restricaoIdade = restricaoIdade;
    conteudo->liberaConteudo = liberaConteudo;

    conteudo->avaliacoes = NULL;
    conteudo->qtdAvaliacoes = 0;

    return conteudo;
}


TipoAssinatura getRestricaoConteudo(tConteudo *conteudo) {
    if (!conteudo) return PADRAO;
    return conteudo->restricaoConteudo(conteudo->dado);
}


void printaConteudo(tConteudo *conteudo) {
    if (conteudo && conteudo->printaConteudo) {
        conteudo->printaConteudo(conteudo->dado);
    }
}

char getTipoConteudo(tConteudo *conteudo) {
    if (!conteudo) return '\0';
    return conteudo->tipoConteudo();
}

int getDuracaoConteudo(tConteudo *conteudo) {
    if (!conteudo) return -1;
    return conteudo->duracao(conteudo->dado);
}

char *getCodConteudo(tConteudo *conteudo) {
    if (!conteudo) return NULL;
    return conteudo->codConteudo(conteudo->dado);
}

TipoUsuario getRestricaoIdade(tConteudo *conteudo) {
    if (!conteudo) return INFANTIL;
    return conteudo->restricaoIdade(conteudo->dado);
}

void inserirAvaliacaoConteudo(tConteudo *c, tAvaliacao *a) {
    if (!c || !a) return;

    
    tAvaliacao **novo = realloc(c->avaliacoes, sizeof(tAvaliacao*) * (c->qtdAvaliacoes + 1));
    if (!novo) return; 
    
    c->avaliacoes = novo;
    c->avaliacoes[c->qtdAvaliacoes] = a;
    c->qtdAvaliacoes++;
}

void printaConteudoComNota(tConteudo *conteudo, char* cpf) {
    if (!conteudo || !cpf) return;
    
    printaConteudo(conteudo);
    
    tAvaliacao* a = buscaNotaAvaliacao(conteudo, cpf);
    if (a) {
        printf("Nota dada por %s: %d\n", cpf, getNotaAvaliacao(a));
    } else {
        printf("Nota dada por %s: Usuario ainda nao avaliou o conteudo\n", cpf);
    }
}

tAvaliacao* buscaNotaAvaliacao(tConteudo *conteudo, char* cpf) {
    if (!conteudo || !cpf || !conteudo->avaliacoes) return NULL;

    for (int i = 0; i < conteudo->qtdAvaliacoes; i++) {
        char *cpf_avaliacao = getCpfAvaliacao(conteudo->avaliacoes[i]);
        if (cpf_avaliacao && strcmp(cpf_avaliacao, cpf) == 0) {
            return conteudo->avaliacoes[i];
        }
    }
    return NULL;
}

int getQtdAvaliacoes(tConteudo *conteudo) {
    if (!conteudo) return 0;
    return conteudo->qtdAvaliacoes;
}

tAvaliacao* getAvaliacaoPosicao(tConteudo *conteudo, int pos) {
    if (!conteudo || pos < 0 || pos >= conteudo->qtdAvaliacoes) return NULL;
    return conteudo->avaliacoes[pos];
}

char* getTituloConteudo(tConteudo *conteudo) {
    if (!conteudo) return NULL;
    return conteudo->titulo(conteudo->dado);
}

float getNotaMediaConteudo(tConteudo *conteudo) {
    if (!conteudo) return -1.0f;
    return conteudo->notaMedia(conteudo->dado);
}

// Liberação de memória
void liberaConteudo(tConteudo *conteudo) {
    if (!conteudo) return;

    // Libera todas as avaliações
    if (conteudo->avaliacoes) {
        for (int i = 0; i < conteudo->qtdAvaliacoes; i++) {
            if (conteudo->avaliacoes[i]) {
                liberaAvaliacao(conteudo->avaliacoes[i]);
            }
        }
        free(conteudo->avaliacoes);
    }

    // Libera o dado específico
    if (conteudo->liberaConteudo && conteudo->dado) {
        conteudo->liberaConteudo(conteudo->dado);
    }

    free(conteudo);
}

void* getDadoConteudo(tConteudo *conteudo) {
    if (!conteudo) return NULL;
    return conteudo->dado;
}