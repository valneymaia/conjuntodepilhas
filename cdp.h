#ifndef CDP_H_INCLUDED
#define CDP_H_INCLUDED

struct conjunto_de_pilhas {
    Pilha *pilha;
    struct conjunto_de_pilhas *proxima_pilha;
};

typedef struct conjunto_de_pilhas CDP;

CDP * criar_lista();
void inserir_lista(CDP *cdp, struct aluno dados, int n);
void imprimir_lista(CDP *cdp);
void destruir_lista(CDP *cdp);




#endif // CDP_H_INCLUDED
